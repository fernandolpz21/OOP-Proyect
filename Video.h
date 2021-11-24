#pragma once
#include <string>

//Abstract class

class Video{
    private:
        std::string id;
        std::string name;
        std::string genre;
        
    protected:
        float rate;
        float length;
    public:
        //Constructors
        Video(std::string _id, std::string _name, std::string _genre);
        Video();

        //getters
        std::string getId();
        std::string getName();
        std::string getGenre();
        float getRate();
        float getLength();

        //setters
        void setId(std::string _id);
        void setName(std::string _name);
        void setGenre(std::string _genre);
        
        //methods for the abstract class

        void virtual setLength(float _length) = 0;
        void virtual setRate(float _rate);


        //Sobrecarga de operadores: comparar rate de peliculas




};