#ifndef MAPDOWNLOADER_MAPDOWNLOADER_H
#define MAPDOWNLOADER_MAPDOWNLOADER_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>

#include <stdio.h>
#include <curl/curl.h>
#include <openssl/md5.h>

class MapDownloader {
private:
    CURL *curl;
    FILE *fp;
    CURLcode res;

public:
    MapDownloader();

    ~MapDownloader();

    std::string download(const std::string &url, const std::string &path, const bool lowercase = true);
};

#endif //MAPDOWNLOADER_MAPDOWNLOADER_H
