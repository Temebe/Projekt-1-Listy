//Autor: Sebastian Aksamit
//Cel zadania: klasa realizujaca liste cykliczna jednokierunkowa przechowujaca liczby calkowite

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include "interface.hpp"

void wiadomoscPowitalna() {
    std::cout << "Autor: Sebastian Aksamit" << std::endl;
}

int main() {
    List FirstList(0), SecondList(1);
    wiadomoscPowitalna();
    FirstList.addElement(5);
    FirstList.addElement(7);
    FirstList.addElement(4);
    FirstList.addElement(4);
    FirstList.addElement(8);
    FirstList.addElement(8);
    FirstList.addElement(9);
    SecondList.addElement(3);
    SecondList.addElement(2);
    SecondList.addElement(1);
    SecondList.addElement(7);
    SecondList.addElement(3);
    interface(FirstList, SecondList);
}
