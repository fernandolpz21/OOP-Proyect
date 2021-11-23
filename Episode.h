#pragma once
#include <string>

class Episode{
    private:
        std::string title;
        int season;
        float length;
    public:
        Episode();
        Episode(std::string _title, int _season);

        std::string getTitle();
        int getSeason();

        void setTitle(std::string _title);
        void setSeason(int _season);

};