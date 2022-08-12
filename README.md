# Streaming service console app

Challenge:  
A limited version of a console application to support a future streaming service provider.
The program works with two types of videos: movies and series; the user is interested in knowing the average rating that each of the videos has received.

The system is capable of showing the videos in general with their ratings, showing the episodes of a series and/or a specific movie with their ratings



Credits:  
Author: Fernando López Gómez   
Professor: Jose Maria Castellanos Ortuño  
  
About the class:  
Programación orientada a objetos TC1031  
Instituto Tecnológico de Monterrey Campus Guadalajara  
  
>**References and Notes:**  
>[R1] ASCII generator: http://www.network-science.de/ascii/

>[RA] switch condicional:
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
https://www.programarya.com/Cursos/C++/Condicionales/Condicional-switch

>[RB] Compare function
Sintax 1:
int string::compare (const string& str) const
Returns:
0 : if both strings are equal.
A value < 0 : if *this is shorter than str or,
first character that doesn't match is smaller than str.
A value > 0 : if *this is longer than str or,
first character that doesn't match is greater

>Sintax 2:

>int string::compare (size_type idx, size_type len, const string& str) const
Throws out_of_range if index > size().
where:
idx is an index character number where the program should start reading
len is the number of characters thath the program should read to compare
str is the string that has to be compared whith len

>For example: s2.compare(3, 5, s1))  

>we want the program to avoid the first 3 characters of the string s2, read the next 5 characters and compare them with the string s1. If there are equal, it should return 0

https://www.geeksforgeeks.org/stdstringcompare-in-c/


