#include "Episode.h"

using namespace std;

Episode::Episode(){

}
Episode::Episode(std::string _title, int _season): title{_title}, season{_season}{

}

string Episode::getTitle(){
    return this -> title;
}
int Episode::getSeason(){
    return this -> season;
}

void Episode::setTitle(string _title){
    this -> title = _title;
}
void Episode::setSeason(int _season){
    this -> season = _season;
}