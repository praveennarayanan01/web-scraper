#include "WebScrapper.hxx"

web_scapper::WebScrapper::WebScrapper()
{
}

web_scapper::WebScrapper::~WebScrapper()
{
}

size_t web_scapper::WebScrapper::WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output)
{
    size_t totalSize = size * nmemb;
    output->append(static_cast<char *>(contents), totalSize);
    return totalSize;
}

void web_scapper::WebScrapper::scrap(const std::string &file_name)
{
    try
    {
        std::fstream scrapping_file_stream;

        scrapping_file_stream.open(file_name, std::ios::in | std::ios::out | std::ios::binary);

        if (!scrapping_file_stream.is_open())
        {
            throw error_handling::ErrorManager(000002);
        }

        scrapping_file_stream.seekp(0, std::ios::beg); // move the curser to the beginning

        std::vector<std::vector<std::string>> data;
        std::string line;

        while (getline(scrapping_file_stream, line))
        {
            std::vector<std::string> row;
            std::string element;
            std::stringstream ss(line);
            while (getline(ss, element, ','))
            {
                row.push_back(element);
            }
            data.push_back(row);
        }

        for (size_t i = 0; i < data.size(); i++)
        {
            if (!i == 0)
            {
                for (size_t j = 0; j < data[i].size(); j++)
                {
                    if (!j == 0)
                    {
                        if (!data[i][j].empty())
                        {
                            CURL *curl;
                            CURLcode res;
                            curl_global_init(CURL_GLOBAL_DEFAULT);
                            curl = curl_easy_init();

                            if (!curl)
                            {
                                throw error_handling::ErrorManager(000003);
                            }

                            std::string url = data[i][j];
                            std::string readBuffer;

                            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
                            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
                            curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0");

                            res = curl_easy_perform(curl);

                            if (res != CURLE_OK)
                            {
                                std::cerr << "CURL error: " << curl_easy_strerror(res) << std::endl;
                                throw error_handling::ErrorManager(000004);
                            }
                            else
                            {
                                std::string new_file_name = "files/fetched/" + data[i][0] + "_" + data[0][j] + ".html";
                                std::fstream fetched_file;

                                fetched_file.open(new_file_name, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);

                                if (!fetched_file.is_open())
                                {
                                    throw error_handling::ErrorManager(000005);
                                }

                                fetched_file << readBuffer;
                                fetched_file.close();
                            }

                            curl_easy_cleanup(curl);
                            curl_global_cleanup();
                        }
                    }
                }
            }
        }
    }
    catch (error_handling::ErrorManager em)
    {
        std::cerr << em.what() << std::endl;
    }
    catch (std::exception e)
    {
        std::cerr << e.what() << std::endl;
    }
}