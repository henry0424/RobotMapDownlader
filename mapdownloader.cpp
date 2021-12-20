#include "mapdownloader.h"

MapDownloader::MapDownloader() {
    this->curl = curl_easy_init();
}

MapDownloader::~MapDownloader() {
    curl_easy_cleanup(this->curl);
}

std::string MapDownloader::download(const std::string &url, const std::string &path, const bool lowercase) {

    auto str = [&](unsigned char *md5_result) -> std::string {
        std::stringstream ss;
        ss.clear();
        for (auto i = 0; i < MD5_DIGEST_LENGTH; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int) md5_result[i];
        }
        auto ret = ss.str();
        if (!lowercase)
            ret = boost::to_upper_copy<std::string>(ret);
        else
            ret = boost::to_lower_copy<std::string>(ret);
//        std::cout << "calculate hash : " << ret << std::endl << std::flush;
        return ret;
    };

    if (this->curl) {
        {
            fp = fopen(path.c_str(), "w");
            res = curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            if (res != CURLE_OK)
                throw std::runtime_error("CURLcode [" + std::to_string(res) + "] != CURLE_OK");
            res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
            if (res != CURLE_OK)
                throw std::runtime_error("CURLcode [" + std::to_string(res) + "] != CURLE_OK");
            res = curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            if (res != CURLE_OK)
                throw std::runtime_error("CURLcode [" + std::to_string(res) + "] != CURLE_OK");
            res = curl_easy_perform(curl);
            if (res != CURLE_OK)
                throw std::runtime_error("CURLcode [" + std::to_string(res) + "] != CURLE_OK");
            fclose(fp);
        }
        {
            fp = fopen(path.c_str(), "r");
            fseek(fp, 0L, SEEK_END);
            const auto size = ftell(fp);
            fseek(fp, 0L, SEEK_SET);
            unsigned char *md5_result = (unsigned char *) malloc(MD5_DIGEST_LENGTH);
            unsigned char *content_c_str = (unsigned char *) malloc(size);
            auto read_size = fread(content_c_str, 1, size, fp);
            fclose(fp);

            MD5(content_c_str, size, md5_result);
            auto ret = str(md5_result);
            free(content_c_str);
            free(md5_result);
            return ret;
        }
    }
    throw std::runtime_error("Download Error");
}
