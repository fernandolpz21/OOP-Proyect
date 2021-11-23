#pragma once
#include "Video.h"
#include "Episode.h"
#include <vector>

class Serie: public Video{
    private:
        int numEpisodes;

    public:
        Serie();
        Serie(std::string _id, std::string _name, float _length, std::string _genre, int _rate, int _numEpisodes);
        
        int getRate() override;
        std::vector <Episode> episodes;//vector<tipo de dato> nombre del vector
};