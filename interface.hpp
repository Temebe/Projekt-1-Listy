#include <iostream>
#include "classes.hpp"

void cmdLength(class List FirstList); //wypisuje ilosc elementow danej listy

void cmdShowElements(class List FirstList); //wypisywanie elementow listy

void cmdDelete(class List& FirstList); //obsluga metod usuwania elementow

void cmdAdd(class List& FirstList); //obsluga metod dodawania elementow

void cmdGet(class List& FirstList); // pobiera wskazanie na element o danym indexie/wartosci i wypisuje wartosc wskazywanego elementu

void interface(class List &FirstList, class List &SecondList);
