#include "Video.h"
#include <string>
#include <iostream>

using namespace std;

Video::Video(string _id, string _name, string _genre): 
    id{_id}, name{_name}, genre{_genre}{
}
Video::Video(){
    setId("uk");
    setName("uk");
    setGenre("uk");
}

//getters
string Video::getId(){
    return this -> id;
}
string Video::getName(){
    return this -> name;
}
string Video::getGenre(){
    return this -> genre;
}
float Video::getRate(){
    return this -> rate;
}
float Video::getLength(){
    return this -> length;
}

//setters
void Video::setId(string _id){
    this -> id = _id;
}
void Video::setName(string _name){
    this -> name = _name;
}
void Video::setGenre(string _genre){
    this -> genre = _genre;
}
void Video::setRate(float _rate){
    if(_rate < 1.0 || _rate > 5.0){
        throw "ERROR: The rate must be between 1 and 5" ;
    }
    else{
        this -> rate = _rate;
    }

}
bool Video::operator == (string _videoType){
    try{
        if(_videoType == "serie"){
            return this -> getId().compare(3, 2, "45") == 0; //[RB]
        }
        else if(_videoType == "movie"){
            return this -> getId().compare(3, 2, "21") == 0;
        }
        else{
            throw "This isn't a movie or a Serie";
        }
    }
    catch(const char* exception){
        cout << exception << endl;
        
    }
    return false;
}