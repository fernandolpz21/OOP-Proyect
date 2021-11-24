#include "Serie.h"

Serie::Serie(){

}
Serie::Serie(std::string _id, std::string _name, std::string _genre, float _rate, std::vector<Episode> _episodes):   
    Video{_id, _name, _genre}, episodes{_episodes}{
        updateLength();
        setNumEpisodes(this -> episodes);
}

//Getters&Setters
int Serie::getNumEpisodes(){
    return this -> numEpisodes;
}
void Serie::setNumEpisodes(std::vector<Episode> _episodes){
    int count = 0;
    for(Episode ep: _episodes){
        count ++ ;
    }
    this -> numEpisodes = count;
}

//Override setters
void Serie::setLength(float _length){
    Video::length = _length;
}
void Serie::setRate(float _rate){
    //Promedio de length de episodios
}

//Methods
void Serie::updateLength(){
    //Promedio de Rate de Episodios
    float totalLenght = 0;
    for(Episode ep : this-> episodes){ //For an episode variable called "ep" in each member of the vector episodes
        totalLenght = totalLenght + ep.getLength();
    }
    setLength(totalLenght);
}
