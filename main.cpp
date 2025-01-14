#include "WebScrapper.hxx"

int main()
{
    web_scapper::WebScrapper newsWebscrapper;
    newsWebscrapper.scrap("files/input/news_scrapping_sites.csv");
}