#include "Episode.h"

using namespace std;

Episode::Episode(){

}
Episode::Episode(std::string _title, int _season, float _length, float _rate): title{_title}, season{_season}, length{_length}, rate{_rate}{

}
//Getters & Setters
string Episode::getTitle(){
    return this -> title;
}
int Episode::getSeason(){
    return this -> season;
}
float Episode::getLength(){
    return this -> length;
}
float Episode::getRate(){
    return this -> rate;
}
void Episode::setTitle(string _title){
    this -> title = _title;
}
void Episode::setSeason(int _season){
    this -> season = _season;
}
void Episode::setRate(float _rate){
    this -> rate = _rate;
}