#pragma once
#include <string>

class Episode{
    private:
        std::string title;
        int season;
        float length;
        float rate;
        int epNumber;
    public:
        Episode();
        Episode(std::string _title, int _season, int _epNumber, float _length, float _rate);

        //getters & setters
        std::string getTitle();
        int getSeason();
        float getLength();
        float getRate();
        int getEpNumber();

        void setTitle(std::string _title);
        void setSeason(int _season);
        void setRate(float _rate);

};