///Author: Fernando López Gómez A01639715
///Due date: December 3rd


/*
Disclamer: Not all the things here are made by myself
References are stablished by comments as:
     [Rn] where n is the number of the reference. You can search for the reference in the README.md file. That code is not mine
     [Rx] where x is a letter. Those references are for the reader to know how the code is working.
*/

// *** Libreries *** 
#include <iostream>
#include <fstream> 
#include <string>
#include <stdexcept>
#include "Video.h"
#include "Movie.h"
#include "Serie.h"
#include "Episode.h"

using namespace std;

// *** Functions ***
void welcome(){
    //[R1]
    printf("""\t===================================================================\n\t888       888        888                                     888888\n\t888   o   888        888                                     888888\n \t888  d8b  888        888                                     888888\n \t888 d888b 888 .d88b. 888 .d8888b .d88b. 88888b d88b.  .d88b. 888888\n \t888d88888b888d8P  Y8b888d88P    d88  88b888  888  88bd8P  Y8b888888\n \t88888P Y8888888888888888888     888  888888  888  88888888888Y8PY8P\n \t8888P   Y8888Y8b.    888Y88b    Y88..88P888  888  888Y8b      "  " \n \t888P     Y888  Y8888 888  Y8888P  Y88P  888  888  888  Y8888 888888\n\t===================================================================\n""");
}
bool hasEnding (std::string const &fullString, std::string const &ending) { //Puede que ni la use
    //[R2][RB]
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}
/*void loadDataTxt(){
    //I will try to do this later, it doesn't work for now
    string text;
    ifstream catalog("catalog.txt");
    if(catalog.is_open()){
        int counter = 1;
        while(getline(catalog,text)){
            cout << counter << endl;
            counter ++;
        }
        catalog.close();
    }
    else{
        throw "Can't open data file";
    } 
}*/
void showVideos(vector<Video*> sortedCatalog){
    int cont = 0;
    for(Video* vid: sortedCatalog){
        cont ++;
        cout << "Catalog Number: " << cont << endl;
        cout << "*****" << vid -> getName() << "*****" << endl;
        cout << "ID: " << vid -> getId() << endl;
        cout << "Genre: " << vid -> getGenre() << endl;
        cout << "Rate: " << vid -> getRate() << endl;
        cout << "==========================================" << endl;
    }
}
void sortByGenre(vector<Video*> _catalog){ 
    int op = 1;
    string genre;
    while (op != 0){
        cout << endl;
        cout << "** SORT BY GENRE **" << endl;
        cout << "1) Action" << endl;
        cout << "2) Fantasy" << endl;
        cout << "3) Sci-Fi" << endl;
        cout << "4) Comedy" << endl;
        cout << "0) Go back" << endl;
        cout << "Choose an option : " ;
        cin >> op;
        cout << endl;
        switch(op){
            case 1: genre = "Action";
            break;
            case 2: genre = "Fantasy";
            break;
            case 3: genre = "Sci-Fi";
            break;
            case 4: genre = "Comedy";
            break;
            case 0: cout << endl;
            break;
            default: 
                cout << "The chosen option is not correct. Please try again" << endl;
                cout << endl;
        }
        if(op != 0){
            vector<Video*> sortedCatalog;
            int cont = 0;
            for(Video* vid: _catalog){ //Putting only the selected genre into the sorted catalog
                if(!vid -> getGenre().find(genre)){ //If (vid->getGenre().find(genre) != std::string::npos)
                    sortedCatalog.push_back(vid);
                    cont ++;
                }
            }
            if(cont != 0){
                showVideos(sortedCatalog);
            }
            else{
                cout << "There are no videos that match your request" << endl;
            }
        }
    }
}
void sortByRate(vector<Video*> _catalog){
    vector<Video*> sortedCatalog;
    int op = 1;
    float rate[2];
    while (op != 0){
        cout << endl;
        cout << "** SORT BY RATE **" << endl;
        cout << "1) 1 -> 2" << endl;
        cout << "2) 2.1 -> 3" << endl;
        cout << "3) 3.1 -> 4" << endl;
        cout << "4) 4.1 -> 5" << endl;
        cout << "0) Go back" << endl;
        cout << "Choose an option : " ;
        cin >> op;
        cout << endl;
        switch(op){
            case 1: {
                rate[1] = 1.0;
                rate[2] = 2.0;
            }
            break;
            case 2: {
                rate[1] = 2.1;
                rate[2] = 3.0;
            }
            break;
            case 3: {
                rate[1] = 3.1;
                rate[2] = 4.0;
            }
            break;
            case 4: {
                rate[1] = 4.1;
                rate[2] = 5.0;
            }
            break;
            case 0: cout << endl;
            break;
            default: 
                cout << "The chosen option is not correct. Please try again" << endl;
                cout << endl;
        }
        if(op != 0){
            int cont = 0;
            for(Video* vid: _catalog){ //Putting only the selected genre into the sorted catalog
                if(vid -> getRate() >= rate[1] && vid -> getRate() <= rate[2]){
                    sortedCatalog.push_back(vid);
                    cont ++;
                }
            }
            if(cont != 0){
                showVideos(sortedCatalog);
            }
            else{
                cout << "There are no videos that match your request" << endl;
            }
        }
    }
}
vector<Video*> clasifyVideos(vector<Video*> _catalog, int _videoType){
    vector<Video*> allSeries;//Quiero que sea un vector de series
    vector<Video*> allMovies;
    int cont = 0;
    for(Video* vid: _catalog){ 
        //Aquí puedes sobrecargar == para comparar ID's
        if((vid -> getId().compare(3, 2, "45")) == 0){ //If the ID ends with "45" its a Serie
            allSeries.push_back(vid);
        }
        else if((vid -> getId().compare(3, 2, "21")) == 0){ //If the ID ends with "21" its a Movie
            allMovies.push_back(vid);
        }
    }
    try{
        switch(_videoType){
            case 1: return allSeries;
            break;
            case 2: return allMovies;
            break;
            default: throw invalid_argument("Invalid Syntax: Video type must be the integer 1 or 2");
        }
    }
    catch(std::invalid_argument ex){
        cout << ex.what() << endl;
    }
    return _catalog;
}
void showEpisodes(vector<Video*> _allSeries){
    /*
    int cont = 0;
    for(Video* vid: _series){ 
        if((vid -> getId().compare(3, 2, "45")) == 0){ //If the ID ends with "45"
            sortedCatalog.push_back(vid);

            cout << *sortedCatalog[0].showEpisodes()<< endl;
            cont ++;
        }
    }*/ //Para imprimir direcciones de video
    int op = 1;
    while (op != 0){
        cout << endl;
        cout << "** SELECT A SERIE **" << endl;
        int cont = 1;
        for(Video* vid: _allSeries){ 
            cout << cont << ") " << vid->getName() << endl;
        }
        cout << "0) Go back" << endl;
        cout << "Choose an option : " ;
        cin >> op;
        cout << endl;

        switch(op){
            case 1:{
                cout << "Option 1" << endl;
                //Necesito desreferenciar
                /*
                Video s = (*_allSeries)[1];
                cout << s->showEpisodes() << endl;*/
            }
            break;
            case 2: cout << "Option 2" << endl;
            break;
            case 3: cout << "Option 3" << endl;
            break;
            case 4: cout << "Option 4" << endl;
            break;
            case 0: cout << endl;
            break;
            default: 
                cout << "The chosen option is not correct. Please try again" << endl;
                cout << endl;
        }
    }
}
void showMovies(vector<Video*> _catalog){
    showVideos(clasifyVideos(_catalog, 2));
}
void rateVideo(vector<Video*> _catalog){ //Not ready yet
    //Necesito poder entrar a la película
    int op = 1;
    while (op != 0){
        cout << endl;
        cout << "** RATE A VIDEO **" << endl;
        cout << "1) Movie" << endl;
        cout << "2) Serie Episode" << endl;
        cout << "0) Go back" << endl;
        cout << "Choose an option : " ;
        cin >> op;
        cout << endl;
        switch(op){
            case 1: 
                cout << "Option 1" << endl;
                //rateMovie();
            break;
            case 2: cout << "Option 2" << endl;
            break;
            case 0: cout << endl;
            break;
            default: 
                cout << "The chosen option is not correct. Please try again" << endl;
                cout << endl;
        }
    }
}
void rateMovie(vector<Video*> _allMovies){
    int op = 1;
    while (op != 0){
        cout << endl;
        cout << "** SELECT A MOVIE **" << endl;
        int cont = 1;
        for(Video* vid: _allMovies){ 
            cout << cont << ") " << vid->getName() << endl;
            cont++;
        }
        cout << "0) Go back" << endl;
        cout << "Choose an option : " ;
        cin >> op;
        cout << endl;

        switch(op){
            case 1:{
                cout << "Option 1" << endl;
                float newRate;
                cout << "Set new rate: " ;
                cin >> newRate;
                _allMovies[0]->setRate(newRate);
            }
            break;
            case 2: {
                cout << "Option 2" << endl;
                float newRate;
                cout << "Set new rate: " ;
                cin >> newRate;
                _allMovies[1]->setRate(newRate);
            }
            break;
            case 0: cout << endl;
            break;
            default: 
                cout << "The chosen option is not correct. Please try again" << endl;
                cout << endl;
        }
    }
}
    


//****** MAIN PROGRAM **********

int main(){
    //system("cls"); //Clear console
    welcome();
    vector<Video*> catalog;
    int op = 1;
    while(op != 0){
        cout << endl;
        cout << "******* MAIN MENU *******" << endl;
        cout << "1) Load data" << endl;
        cout << "2) Show all videos" << endl;
        cout << "3) Show sorted videos" << endl;
        cout << "4) Show episodes" << endl;
        cout << "5) Show movies" << endl;
        cout << "6) Rate a video" << endl;
        cout << "0) Exit" << endl;
        cout << "Choose an option : " ;
        cin >> op;
        cout << endl;

        //Evaluate if there is data in the catalog vector only if the selected option is not Load Data
        try{
            if(op != 1 && op != 0){
                int cont = 0;
                for(Video* vid: catalog){
                    cont++;
                }
                if(cont == 0){
                    throw "WARNING: There is no data loaded";
                }
            }
        }
        catch(const char* exception){
            cout << exception << endl;
        }

        //Menu options
        switch (op){
            case 1: //Load data
                try{          
                    vector <Episode> demonEpisodes;
                    Episode ds1{"ds1", 1, 1, 23.0, 4.5};
                    demonEpisodes.push_back(ds1);
                    Serie DemonSlayer("12345", "Kimetsu no Yaiba", "Action", 4.5, demonEpisodes); 


                    vector <Episode> trollEpisodes;
                    Episode th1{"th1", 2, 1, 22.4, 4.4};
                    trollEpisodes.push_back(th1);
                    Serie TrollHunters("23445", "Troll Hunters", "Fantasy", 5, trollEpisodes);

                    Movie PacificRim("12321", "Pacific Rim", "Sci-Fi", 2.11, 4.3);
                    Movie WhiteChicks("23421", "White Chicks", "Comedy", 1.49, 4.6);

                    catalog.push_back(&DemonSlayer);
                    catalog.push_back(&TrollHunters);
                    catalog.push_back(&PacificRim);
                    catalog.push_back(&WhiteChicks);

                    cout << "Data loaded succesfully" << endl;
                }
                catch(const char* exception){
                    cout << exception << endl;
                }
            break;
            case 2: showVideos(catalog);
            break;
            case 3: {//show sorted videos
                int op1 = 1;
                while (op1 != 0){
                    cout << endl;
                    cout << "** SORT **" << endl;
                    cout << "1) BY GENRE" << endl;
                    cout << "2) BY RATE" << endl;
                    cout << "0) Go back" << endl;
                    cout << "Choose an option : " ;
                    cin >> op1;
                    cout << endl;

                    switch(op1){
                        case 1: sortByGenre(catalog); 
                        break;
                        case 2: sortByRate(catalog);
                        break;
                        case 0: cout << endl;
                        break;
                        default: 
                            cout << "The chosen option is not correct. Please try again" << endl;
                            cout << endl;
                    }
                }
                break;
            }
            case 4: //show episodes
                cout << "You have chosen option 4" << endl; 
                //showEpisodes(catalog);
            break;
            case 5://show movies 
                showMovies(catalog);
            break;
            case 6://Rate a video
                cout << "You have chosen option 6" << endl;//rateVideo();
            break;
            case 0: //Exit
                cout << "Come back soon :)" << endl;
                cout << endl;
            break;
            default: 
                cout << "The chosen option is not correct. Please try again" << endl;
                cout << endl;
        }//[RA]
    } 
}