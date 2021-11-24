#include "Movie.h"

//Constructors
Movie::Movie(){
}
Movie::Movie(std::string _id, std::string _name, std::string _genre, float _length, float _rate):
    Video{_id, _name, _genre}{
    this -> setLength(_length);
    this -> setRate(_rate);

}

//Methods
void Movie::setLength(float _length){
    Video::length = _length;
}
void Movie::setRate(float _rate){
    Video::rate = _rate;
}