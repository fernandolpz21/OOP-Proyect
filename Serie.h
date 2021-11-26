#pragma once
#include "Video.h"
#include "Episode.h"
#include <vector>

class Serie: public Video{
    private:
        int numEpisodes;

    public:
        Serie();
        Serie(std::string _id, std::string _name, std::string _genre, float _rate, std::vector<Episode> _episodes);
        
        //getters
        int getNumEpisodes();

        //Setters
        void setNumEpisodes(std::vector<Episode> _episodes);

        //Override setters
        void setLength(float _length) override;
        void setRate(float _rate) override;
        void setLength();

        std::vector <Episode> episodes;//vector <type> name

        //Methods
        void updateLength();
        void updateRate();
        void showEpisodes();
};