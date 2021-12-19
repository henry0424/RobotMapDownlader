#include <memory>
#include "mapdownloader.h"

int main(int argc, char **argv) {

    auto map_download = std::make_shared<MapDownloader>();
    auto md5 = map_download->download(
            "http://ftp.tku.edu.tw/Linux/Ubuntu/ubuntu-releases/bionic/ubuntu-18.04.6-live-server-amd64.iso",
            "./ubuntu-18.04.6-live-server-amd64.iso");
    std::cout << "MD5: " << md5 << std::endl;
    return EXIT_SUCCESS;
}