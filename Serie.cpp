#include "Serie.h"

Serie::Serie(){

}
Serie::Serie(std::string _id, std::string _name, float _length, std::string _genre, int _rate, int _numEpisodes):   
    Video{_id, _name, _length, _genre, _rate}, numEpisodes{_numEpisodes}{

}
        
int Serie::getRate(){
    //Promedio de Episodios
}