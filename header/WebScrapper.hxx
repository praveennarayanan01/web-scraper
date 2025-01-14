#ifndef _WEB_SCRAPPER_HPP_
#define _WEB_SCRAPPER_HPP_

#include <chrono>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <curl/curl.h>

#include "Error.hxx"

namespace web_scapper
{
    class WebScrapper
    {
    public:
        WebScrapper();
        ~WebScrapper();
        static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output);
        void scrap(const std::string &file_name);
    };
}

#endif