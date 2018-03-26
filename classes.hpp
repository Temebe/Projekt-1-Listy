#include <iostream>

class Element {
    class Element *next;
    int value;
public:
    Element();
    int getValue();
    class Element *getNext();
    void setValue(int x);
    void setNext(class Element *temp);
};

class List {
    int index;
    class Element *first, *last;
public:
    List(int ValueOfIndex);
    List(int valueOfIndex, class List &listToCopy);
    // OPERATORY
    class List operator+(class List listB);
    class List operator-(class List listB);
    bool operator<(class List listB);
    bool operator<=(class List listB);
    bool operator>(class List listB);
    bool operator>=(class List listB);
    bool operator==(class List listB);
    //METODY USUWANIA ELEMENTOW
    void delByValue (int value);
    void delByValue(int minimum, int maximum);
    void delByIndex(int index);
    void delDuplicates();
    //METODY DODAWANIA ELEMENTOW
    void addElement (int value);
    void addElement (class Element *original);
    void addElement(int value, int indexValue);
    void addElementAfter(int value, int cmpValue);
    //SETERY I GETERY
    void setFirst(class Element *temp);
    int getIndex();
    class Element *getFirst();
    class Element *getLast();
    void *setLast(class Element *tempElement);
    class Element *getByIndex(int index);
    class Element *getByValue(int value);
};
