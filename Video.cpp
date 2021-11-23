#include "Video.h"
#include <string>

using namespace std;

Video::Video(string _id, string _name,  float _length, string _genre, int _rate): 
    id{_id}, name{_name}, length{_length}, genre{_genre}{
        setRate(_rate);

}
Video::Video(){
    setId("uk");
    setName("uk");
    setLength(0.0);
    setGenre("uk");
    setRate(1);
}

//getters
string Video::getId(){
    return this -> id;
}
string Video::getName(){
    return this -> name;
}
float Video::getLength(){
    return this -> length;
}
string Video::getGenre(){
    return this -> genre;
}

//setters
void Video::setId(string _id){
    this -> id = _id;
}
void Video::setName(string _name){
    this -> name = _name;
}
void Video::setLength(float _length){
    this -> length = _length;
}
void Video::setGenre(string _genre){
    this -> genre = _genre;
}
void Video::setRate(int _rate){
    if(_rate < 1 || _rate > 5){
        throw "ERROR: The rate must be between 1 and 5" ;
    }
    else{
        this -> rate = _rate;
    }

}