#include "interface.hpp"

void cmdLength(class List FirstList) { //wypisuje ilosc elementow danej listy
    class Element *tempElement = FirstList.getFirst();
    int counter = 0;
    if(tempElement == NULL) {
        std::cout << "0" << std::endl;
    }
    do{
        counter++;
        tempElement = tempElement -> getNext();
    }while(tempElement != FirstList.getFirst());
    std::cout << counter << std::endl;
}

void cmdShowElements(class List FirstList) { //wypisywanie elementow listy
    class Element *tempElement = FirstList.getFirst();
    int index = 0;
    if(tempElement == NULL) return;
    std::cout << "===== LISTA (" << FirstList.getIndex() << ") =====" << std::endl;
    do{
        std::cout << "[" << index << "]" << tempElement -> getValue() << std::endl;
        index++;
        tempElement = tempElement -> getNext();
    }while(tempElement != FirstList.getFirst());
}

// OPCJE USUWANIA

void cmdDelete(class List& FirstList) { //obsluga metod usuwania elementow
    int a, b;
    std::string cmd;
    std::cout << "Co masz zamiar usunac?" << std::endl;
    std::cout << "Element / Duplikaty" << std::endl;
    std::cin >> cmd;
    if(cmd == "duplikaty") {FirstList.delDuplicates(); return;}
    if(cmd == "element"){
        std::cout << "O okreslonej (w)artosc, (z)akresie czy (i)ndexie?" << std::endl;
        std::cin >> cmd;
        if(cmd == "w"){
            std::cout << "Podaj wartosc elementu (zostanie usuniety tylko pierwszy): ";
            std::cin >> a;
            FirstList.delByValue(a);
            return;
        }
        if(cmd == "z"){
            std::cout << "Podaj minimalna i maksymalna wartosc jakie beda usuniete z listy: ";
            std::cin >> a >> b;
            FirstList.delByValue(a, b);
            return;
        }
        if(cmd == "i"){
            std::cout << "Podaj index";
            std::cin >> a;
            FirstList.delByIndex(a);
            return;
        }
    }
    std::cout << "Podano niepoprawna komende." << std::endl;
}

void cmdAdd(class List& FirstList) { //obsluga metod dodawania elementow
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
}

void cmdGet(class List& FirstList) { // pobiera wskazanie na element o danym indexie/wartosci i wypisuje wartosc wskazywanego elementu
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
}

void interface(class List &FirstList, class List &SecondList) {
    class List ThirdList(2);
    std::string cmd;
    int eoi = 0; //end of interface
    while(eoi == 0) {
        std::cout << "Podaj komende: " << std::endl;
        std::cin >> cmd;
        if(cmd == "dlugosc") cmdLength(FirstList);
        if(cmd == "elementy0") cmdShowElements(FirstList);
        if(cmd == "elementy1") cmdShowElements(SecondList);
        if(cmd == "elementy2") cmdShowElements(ThirdList);
        if(cmd == "dodaj") cmdAdd(FirstList);
        if(cmd == "usun") cmdDelete(FirstList);
        if(cmd == "pobierz") cmdGet(FirstList);
        if(cmd == "testDodawania") {ThirdList = FirstList + SecondList;}
        if(cmd == "testOdejmowania") {ThirdList = FirstList - SecondList;}
        if(cmd == "testPorownywania") {
            if(ThirdList>FirstList) {
                std::cout << "Lista (2) jest wieksza od listy (0)" << std::endl;
            } else {
                std::cout << "Lista (0) jest wieksza lub rowna od listy (0)" << std::endl;
            }}
        if(cmd == "exit") eoi = 1;

    }
}
