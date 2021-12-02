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

//*** Global variables *** 
    vector<Video*> catalog;
    vector<Serie*> series;
    vector<Episode*> episodeCatalog;

// *** Functions ***
void welcome(){
    //[R1]
    printf("""\t===================================================================\n\t888       888        888                                     888888\n\t888   o   888        888                                     888888\n \t888  d8b  888        888                                     888888\n \t888 d888b 888 .d88b. 888 .d8888b .d88b. 88888b d88b.  .d88b. 888888\n \t888d88888b888d8P  Y8b888d88P    d88  88b888  888  88bd8P  Y8b888888\n \t88888P Y8888888888888888888     888  888888  888  88888888888Y8PY8P\n \t8888P   Y8888Y8b.    888Y88b    Y88..88P888  888  888Y8b      "  " \n \t888P     Y888  Y8888 888  Y8888P  Y88P  888  888  888  Y8888 888888\n\t===================================================================\n""");
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
    vector<Video*> allSeries;
    vector<Video*> allMovies;
    int cont = 0;
    for(Video* vid: _catalog){ 
        if(*vid == "serie"){ //If the ID ends with "45" its a Serie [overloaded operator]
            allSeries.push_back(vid);
        }
        else if(*vid == "movie"){ //If the ID ends with "21" its a Movie
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
int selectSerie(vector<Serie*> _series){
    int op = 1;
    while (op != 0){
        cout << endl;
        cout << "** SELECT A SERIE **" << endl;
        int cont = 1;
        for(Serie* vid: _series){ 
            cout << cont << ") " << vid->getName() << endl;
            cont++;
        }
        cout << "0) Go back" << endl;
        cout << "Choose an option : " ;
        cin >> op;
        cout << endl;
        
        try{
            if(op > 0 && op <= cont){
                return op-1; //For the rateSeries() function
            }
            else if(op == 0){
                continue;
            }
            else{
                throw "Option not avaliable. Please try again";
            }
        }
        catch(const char* exception){
            cout << exception << endl;
        } 
    }
}
void showMovies(vector<Video*> _catalog){
    showVideos(clasifyVideos(_catalog, 2));
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

        try{
            if(op > 0 && op <= cont){
                float newRate;
                cout << "Set new rate: " ;
                cin >> newRate;
                _allMovies[op-1]->setRate(newRate);
                cout << "Rate changed successfully " << endl;
            }
            else if(op == 0){
                continue;
            }
            else{
                throw "Option not avaliable. Please try again";
            }
        }
        catch(const char* exception){
            cout << exception << endl;
        }
    }
}
void rateSerie(int serieNumber){
    try{
        float newRate;
        cout << "Set new rate: " ;
        cin >> newRate;
        if(newRate < 1 || newRate > 5){
            throw "ERROR: Non valid rate";
        }
        else{
            episodeCatalog[serieNumber]->setRate(newRate);
            catalog[serieNumber]-> setRate(episodeCatalog[serieNumber]->getRate()); //Putting the info inside the catalog
            cout << "Rate changed successfully " << endl;
        }
    }
    catch(const char* exception){
        cout << exception << endl;
    }

    /*
    Again this could be the ideal code, but because of the program crashing problem I can't run this section, so against my will I will use
    the code above


    int serieNumber = selectSerie(_series);
    int op = 1;
    while (op != 0){
        cout << endl;
        cout << "** SELECT AN EPISODE **" << endl;
        int cont = 1;
        for(Episode ep: _series[serieNumber]->episodes){ 
            cout << cont << ") " << ep.getTitle() << endl;
            cont++;
        }
        cout << "0) Go back" << endl;
        cout << "Choose an option : " ;
        cin >> op;
        cout << endl;
        int numEpisodes = _series[serieNumber] -> getNumEpisodes();
        try{
            if(op > 0 && op <= numEpisodes){
                float newRate;
                cout << "Set new rate: " ;
                cin >> newRate;
                _series[serieNumber]->episodes[op-1].setRate(newRate);
                cout << "Rate changed successfully " << endl;
            }
            else if(op == 0){
                continue;
            }
            else{
                throw "Option not avaliable. Please try again";
            }
        }
        catch(const char* exception){
            cout << exception << endl;
        }
    }
    */
}
void rateVideo(vector<Video*> _catalog){
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
                rateMovie(clasifyVideos(_catalog, 2));    
            break;
            case 2: 
                cout << "Option 2" << endl;
                rateSerie(selectSerie(series));
            break;
            case 0: cout << endl;
            break;
            default: 
                cout << "The chosen option is not correct. Please try again" << endl;
                cout << endl;
        }
    }
}
void showEpisodes(int serieNumber){
    Episode selectedEpisode = *episodeCatalog[serieNumber];
    cout << endl;
    cout << "Title: " << selectedEpisode.getTitle() << endl;
    cout << "Episode number: " << selectedEpisode.getEpNumber() << endl;
    cout << "Season: " << selectedEpisode.getSeason() << endl;
    cout << "Length: " << selectedEpisode.getLength() << endl;
    cout << "Rate: " << selectedEpisode.getRate() << endl;
    cout << "==========================================" << endl;
    /*
    This section is the correct one, but the problem is that the program also crashes
    so I'm going to leave the section above me even tho i don't like it because it only works 
    for 1 episode series, but the program doesn't crash.


    for(Episode ep: _series[serieNumber]->episodes){ 
        std::cout << std::endl;
        std::cout << "Title: " << ep.getTitle() << std::endl;
        std::cout << "Episode number: " << ep.getEpNumber() << std::endl;
        std::cout << "Season: " << ep.getSeason() << std::endl;
        std::cout << "Length: " << ep.getLength() << std::endl;
        std::cout << "Rate: " << ep.getRate() << std::endl;
        std::cout << "==========================================" << std::endl;
    }
    */
}
    


//****** MAIN PROGRAM **********

int main(){
    system("cls"); //Clear console
    welcome();
    int op = 1;
    bool dataLoaded = false;
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
            if(op != 1 && op != 0 && !dataLoaded){
               throw "WARNING: There is no data loaded";
            }
            else if(op == 1 && dataLoaded){
                throw "Data already loaded";
            }
        }
        catch(const char* exception){
            cout << exception << endl;
        }

        //Menu options
        switch (op){
            case 1: //Load data
                try{
                    if(!dataLoaded){
                        vector <Episode> demonEpisodes;
                        Episode ds1{"ds1", 1, 1, 23.0, 4.5};
                        demonEpisodes.push_back(ds1);
                        Serie DemonSlayer("12345", "Demon Slayer", "Action", 4.5, demonEpisodes); 


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

                        series.push_back(&DemonSlayer);
                        series.push_back(&TrollHunters);

                        episodeCatalog.push_back(&ds1);
                        episodeCatalog.push_back(&th1);

                        cout << "Data loaded succesfully" << endl;
                    }
                }
                catch(const char* exception){
                    cout << exception << endl;
                }
                dataLoaded = true;
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
                showEpisodes(selectSerie(series));
            break;
            case 5://show movies 
                showMovies(catalog);
            break;
            case 6://Rate a video
                rateVideo(catalog);
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