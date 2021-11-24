#pragma once
#include "Video.h"

class Movie: public Video{
    private:
    
    public:
        Movie();
        Movie(std::string _id, std::string _name,std::string _genre, float _length, float _rate);

        //Method
        void setLength(float _length) override;
        void setRate(float _rate) override;

};