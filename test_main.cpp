#include <memory>
#include "mapdownloader.h"

int main(int argc, char **argv) {

    auto map_download = std::make_shared<MapDownloader>();
    {
        const std::string url{"http://192.168.10.20:4096/"};
        const std::string domain{"graph/"};
        const std::string file{"LE_graph.json"};
        auto md5 = map_download->download((url + domain + file),
                                          "./" + file);
        std::cout << md5 << "\t" << file << std::endl;
    }
    {
        const std::string url{"http://192.168.10.20:4096/"};
        const std::string domain{"graph/"};
        const std::string file{"LE_graphConfigure.json"};
        auto md5 = map_download->download((url + domain + file),
                                          "./" + file);
        std::cout << md5 << "\t" << file << std::endl;
    }
    {
        const std::string url{"http://192.168.10.20:4096/"};
        const std::string domain{"route/"};
        const std::string file{"routeSPIL2FLE_test.json"};
        auto md5 = map_download->download((url + domain + file),
                                          "./" + file);
        std::cout << md5 << "\t" << file << std::endl;
    }
    {
        const std::string url{"http://192.168.10.20:4096/"};
        const std::string domain{"route/"};
        const std::string file{"SPIL_2FLE_0106_1013_2.png"};
        auto md5 = map_download->download((url + domain + file),
                                          "./" + file);
        std::cout << md5 << "\t" << file << std::endl;
    }
    return EXIT_SUCCESS;
}