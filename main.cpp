///Author: Fernando López Gómez A01639715
///Due date: December 3rd


#include <iostream>
#include <fstream> 
#include <string>
#include "Video.h"
#include "Movie.h"
#include "Serie.h"
#include "Episode.h"

using namespace std;

void welcome(){
    cout << "Welcome!" << endl;
}
void loadDataTxt(){
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
    
}
void loadData(vector<Video*> _catalog){
    int cont = 0;
    for(Video* vid: _catalog){
        cont ++;
        cout << "Catalog Number: " << cont << endl;
        cout << "*****" << vid -> getName() << "*****" << endl;
        cout << "ID: " << vid -> getId() << endl;
        cout << "Genre: " << vid -> getGenre() << endl;
        cout << "Rate: " << vid -> getRate() << endl;
        cout << "==========================================" << endl;
    }
}

vector<Video*> initSeries(){ //En caso de que no quieras abrir archivos

    ///No lo estás inicializando globalmente
    try{          
        vector <Episode> demonEpisodes;
        Episode ds1{"ds1", 1, 23.0};
        demonEpisodes.push_back(ds1);
        Serie DemonSlayer("12345", "Kimetsu no Yaiba", "Fantasy/Action", 4.5, demonEpisodes); 


        vector <Episode> trollEpisodes;
        Episode th1{"th1", 2, 22.4};
        trollEpisodes.push_back(th1);
        Serie TrollHunters("23456", "Troll Hunters", "Fantasy/Action", 5, trollEpisodes);

        Movie PacificRim("12321", "Pacific Rim", "Sci-Fi", 2.11, 4.3);
        Movie MurgenTrain("23421", "Demon Slayer: Murgen Train", "Fantasy/Action", 1.57, 4.9);

        vector<Video*> catalog {&DemonSlayer, &TrollHunters, &PacificRim, &MurgenTrain};
        //return catalog;
        int cont = 0;
        for(Video* vid: catalog){
            cont ++;
            cout << "*****" << vid -> getName() << "*****" << endl;
            cout << "Position in catalog: " << cont << endl;
            cout << "ID: " << vid -> getId() << endl;
            cout << "Genre: " << vid -> getGenre() << endl;
            cout << "Rate: " << vid -> getRate() << endl;
            cout << "==========================================" << endl;
        }
    }
    catch(const char* exception){
        cout << exception << endl;
    }
}


int main(){
    system("cls");
    welcome();
    int op = 1;
    while(op != 0){
        cout << "*******MAIN MENU*******" << endl;
        cout << "1) Load data" << endl;
        cout << "2) Show all videos" << endl;
        cout << "3) Show episodes" << endl;
        cout << "4) Show movies" << endl;
        cout << "5) Rate a video" << endl;
        cout << "0) Exit" << endl;
        cout << "Choose an option : " ;
        cin >> op;
        cout << endl;

        switch (op){
            case 1:initSeries();
            break;
            case 2: cout << "Elegiste la opción 2" << endl;
            break;
            case 3: cout << "Elegiste la opción 3" << endl;
            break;
            case 4: cout << "Elegiste la opción 4" << endl;
            break;
            case 5: cout << "Elegiste la opción 5" << endl;
            break;
            case 0: cout << "Come back soon :)" << endl;
            break;
            default: cout << "The chosen option is not correct. Please try again" << endl;

        }
    } //La calificación de la serie es el promedio de las calificaciones de los episodios
}

/*
switch(opción) //donde opción es la variable a comparar
{
    case valor1: //Bloque de instrucciones 1;
    break; //Indica el fin del primer bloque de instrucciones
    case valor2: //Bloque de instrucciones 2;
    break;
    case valor3: //Bloque de instrucciones 3;
    break;
    //Nótese que valor 1 2 y 3 son los valores que puede tomar la opción
    //la instrucción break es necesaria, para no ejecutar todos los casos.
    default: //Bloque de instrucciones por defecto;
    //default, es el bloque que se ejecuta en caso de que no se de ningún caso
}
*/