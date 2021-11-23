#include "Movie.h"

//Constructors
Movie::Movie(){
}
Movie::Movie(std::string _id, std::string _name, float _length, std::string _genre, int _rate):
    Video{_id, _name, _length, _genre, _rate}{
}

//Methods
int Movie::getRate(){
    return Video::rate;
}
