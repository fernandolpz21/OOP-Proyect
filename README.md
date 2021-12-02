# OOP-Proyect
Streaming service school proyect using object oriented programing in c++

Challenge: 
"En los últimos años, han proliferado los servicios de streaming de video bajo demanda por ejemplo Netflix, Disney, DC entre otros. Algunos de ellos se especializan por el volumen de videos que proporcionan a sus usuarios mientras que otros se han puesto el reto de mostrar solamente videos de su propia marca. Una versión limitada para apoyar a un futuro proveedor de este tipo de servicios es la que se describe a continuación:

Se quiere trabajar con dos tipos de videos: películas y series. Todo video tiene un ID, un nombre, una duración y un género (drama, acción, misterio).

Las series tienen episodios y cada episodio tiene un título y temporada a la que pertenece.

Nos interesa conocer la calificación promedio que ha recibido cada uno de los videos. Esta calificación está en escala de 1 a 5 donde 5 es la mejor calificación.

El sistema debe ser capaz de :

- Mostrar los videos en general con sus calificaciones
- Mostrar los episodios de una determinada serie con sus calificaciones
- Mostrar las películas con sus calificaciones"


Credits:
Author: Fernando López Gómez A01639715
Professor: Jose Maria Castellanos Ortuño

About the class:
Programación orientada a objetos TC1031
Instituto Tecnológico de Monterrey 
Campus Guadalajara

References:
[R1] ASCII generator: http://www.network-science.de/ascii/

[RA] switch condicional:
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

[RB] Compare function
Sintax 1:
int string::compare (const string& str) const
Returns:
0 : if both strings are equal.
A value < 0 : if *this is shorter than str or,
first character that doesn't match is smaller than str.
A value > 0 : if *this is longer than str or,
first character that doesn't match is greater

Sintax 2:

int string::compare (size_type idx, size_type len, const string& str) const
Throws out_of_range if index > size().
where:
idx is an index character number where the program should start reading
len is the number of characters thath the program should read to compare
str is the string that has to be compared whith len

For example:
s2.compare(3, 5, s1))

we want the program to avoid the first 3 characters of the string s2, read the next 5 characters and compare them with the string s1. If there are equal, it should return 0

https://www.geeksforgeeks.org/stdstringcompare-in-c/


