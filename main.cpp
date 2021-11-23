///Author: Fernando López Gómez A01639715
///Due date: December 3rd


#include <iostream>
#include "Video.h"
#include "Movie.h"
#include "Serie.h"
#include "Episode.h"

using namespace std;

void welcome(){
    cout << "Welcome!" << endl;
}
void loadData(){
    
}
void initSerie(){
    Serie DemonSlayer("12345", "Kimetsu no Yaiba", 9.966, "Fantasy", 5, 26);
}


int main(){
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
        cout << "What option do you want? : " ;
        cin >> op;
        cout << endl;

        switch (op){
            case 1: cout << "Elegiste la opción 1" << endl;
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