#pragma one
#include <string>

//Abstract class

class Video{
    private:
        std::string id;
        std::string name;
        float length;
        std::string genre;
        
    protected:
        int rate;
    public:
        //Constructors
        Video(std::string _id, std::string _name, float _length, std::string _genre, int _rate);
        Video();

        //getters
        std::string getId();
        std::string getName();
        float getLength();
        std::string getGenre();

        //setters
        void setId(std::string _id);
        void setName(std::string _name);
        void setLength(float _length);
        void setGenre(std::string _genre);
        void setRate(int _rate);

        //methods for the abstract class
        int virtual getRate() = 0;

        //Sobrecarga de operadores: comparar rate de peliculas




};