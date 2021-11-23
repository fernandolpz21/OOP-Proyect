#pragma once
#include "Video.h"

class Movie: public Video{
    private:
    
    public:
        Movie();
        Movie(std::string _id, std::string _name, float _length, std::string _genre, int _rate);

        //Method
        int getRate() override;

};