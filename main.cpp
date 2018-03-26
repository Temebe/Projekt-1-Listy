//Autor: Sebastian Aksamit
//Cel zadania: klasa realizujaca liste cykliczna jednokierunkowa przechowujaca liczby calkowite

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include "classes.hpp"

void error(std::string msg) {
    std::cout << msg << std::endl;
    exit(1);
}

int cmdLength(class List FirstList) {
    class Element *tempElement = FirstList.getFirst();
    int counter = 0;
    while(tempElement != NULL){
        counter++;
        tempElement = tempElement -> getNext();
    }
    std::cout << counter << std::endl;
    return 0;
}

int cmdShowElements(class List FirstList) {
    class Element *tempElement = FirstList.getFirst();
    int index = 0;
    if(tempElement == NULL) return 0;
    do{
        std::cout << "[" << index << "]" << tempElement -> getValue() << std::endl;
        index++;
        tempElement = tempElement -> getNext();
    }while(tempElement != FirstList.getFirst());
    return 0;
}

// OPCJE USUWANIA

int cmdDeleteDuplicates(class List FirstList) { // czemu nie wyluskanie jak w cmdDeleteByValue?
    FirstList.delDuplicates();
    return 0;
}

int cmdDeleteByValue(int value, class List& FirstList) {
    FirstList.delByValue(value);
    return 0;
}

int cmdDeleteByValue(int minimum, int maximum, class List &FirstList) {
    FirstList.delByValue(minimum, maximum);
    return 0;
}

int cmdDeleteByIndex(int index, class List &FirstList) {
    FirstList.delByIndex(index);
    return 0;
}

int cmdDelete(class List& FirstList) {
    int a, b;
    std::string cmd;
    std::cout << "Co masz zamiar usunac?" << std::endl;
    std::cout << "Element / Duplikaty" << std::endl;
    std::cin >> cmd;
    if(cmd == "duplikaty") return cmdDeleteDuplicates(FirstList);
    if(cmd == "element"){
        std::cout << "O okreslonej (w)artosc, (z)akresie czy (i)ndexie?" << std::endl;
        std::cin >> cmd;
        if(cmd == "w"){
            std::cout << "Podaj wartosc elementu (zostanie usuniety tylko pierwszy): ";
            std::cin >> a;
            return cmdDeleteByValue(a, FirstList);
        }
        if(cmd == "z"){
            std::cout << "Podaj minimalna i maksymalna wartosc jakie beda usuniete z listy: ";
            std::cin >> a >> b;
            return cmdDeleteByValue(a, b, FirstList);
        }
        if(cmd == "i"){
            std::cout << "Podaj index";
            std::cin >> a;
            return cmdDeleteByIndex(a, FirstList);
        }
    }
    std::cout << "Podano niepoprawna komende." << std::endl;
    return 0;
}

int cmdAdd(class List& FirstList) {
    int value, index, cmpValue;
    std::string cmd;
    std::cout << "Chcesz dodac (k)olejny element, na konkretnym (i)ndexie czy po konkretnej (w)artosci?" << std::endl;
    std::cin >> cmd;
    if(cmd == "k") {
        std::cout << "Wartosc: ";
        std::cin >> value;
        FirstList.addElement(value);
    }else {
    if(cmd == "i") {
        std::cout << "Wartosc: ";
        std::cin >> value;
        std::cout << "Index: ";
        std::cin >> index;
        FirstList.addElement(value, index);
    }else {
    if(cmd == "w") {
        std::cout << "Wartosc dodawana: ";
        std::cin >> value;
        std::cout << "Wartosc szukana: ";
        std::cin >> cmpValue;
        FirstList.addElementAfter(value, cmpValue);
    }else {
    std::cout << "Podano niepoprawna komende." << std::endl; }}}
    return 0;
}

int cmdGet(class List& FirstList) {
    class Element *tempElement;
    int value, index;
    std::string cmd;
    std::cout << "Chcesz pobrac element po (w)artosci czy (i)ndexie?" << std::endl;
    std::cin >> cmd;
    if(cmd == "w") {
        std::cout << "Wartosc: ";
        std::cin >> value;
        tempElement = FirstList.getByValue(value);
        std::cout << tempElement -> getValue() << std::endl;
    }else {
    if(cmd == "i") {
        std::cout << "Index: ";
        std::cin >> index;
        tempElement = FirstList.getByIndex(index);
        std::cout << tempElement -> getValue() << std::endl;
    }else {
    std::cout << "Podano niepoprawna komende." << std::endl; }}
    return 0;
}

void interface(class List &FirstList, class List &SecondList) {
    std::string cmd;
    int eoi = 0; //end of interface
    while(eoi == 0) {
        std::cout << "Podaj komende: " << std::endl;
        std::cin >> cmd;
        if(cmd == "dlugosc") eoi = cmdLength(FirstList);
        if(cmd == "elementy") eoi = cmdShowElements(FirstList);
        if(cmd == "dodaj") eoi = cmdAdd(FirstList);
        if(cmd == "usun") eoi = cmdDelete(FirstList);
        if(cmd == "pobierz") eoi = cmdGet(FirstList);
        if(cmd == "test") {FirstList = FirstList + SecondList; eoi = 0;}
        if(cmd == "test2") {if(FirstList>SecondList) {std::cout << "POINK" << std::endl;}}
        if(cmd == "exit") eoi = 1;

    }
}

void wiadomoscPowitalna() {
    std::cout << "Czesc" << std::endl;
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
