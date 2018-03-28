#include <iostream>
#include "classes.hpp"

int lastIndex = 1;

int Element::getValue() {
    return value;
}
class Element *Element::getNext() {
    if(next != NULL) return next;
    else return NULL;
}
void Element::setValue(int x) {
    value = x;
}
void Element::setNext(class Element *temp) {
    next = temp;
}

// OPERATORY
class List List::operator+(class List listB) {
    class List result(lastIndex+1);
    class Element *temp = this -> getFirst();
    do {
        result.addElement(temp);
        temp = temp -> getNext();
    }while((temp != this -> getFirst()) && (temp != NULL));
    temp = listB.getFirst();
    do {
        result.addElement(temp);
        temp = temp -> getNext();
    }while((temp != listB.getFirst()) && (temp != NULL));
    return result;
}
class List List::operator-(class List listB) {
    bool isThere;
    class List result(lastIndex+1);
    class Element *tempA = this -> getFirst();
    class Element *tempB = listB.getFirst();
    do {
        isThere = false;
        do {
            if(tempA -> getValue() == tempB -> getValue()) {
                isThere = true;
                break;
            }
            else
                tempB = tempB -> getNext();
        }while(tempB != listB.getFirst());
        if(isThere == false) {
            result.addElement(tempA -> getValue());
        }
        tempA = tempA -> getNext();
        tempB = listB.getFirst();
    }while(tempA != this -> getFirst());
    return result;
}
bool List::operator<(class List listB) {
    bool eoA = false, eoB = false;
    class Element *elementA = this -> getFirst();
    class Element *elementB = listB.getFirst();
    do {
        elementA = elementA -> getNext();
        elementB = elementB -> getNext();
        if(elementA == this -> getFirst()) {eoA = true;}
        if(elementB == listB.getFirst()) {eoB = true;}
        if((eoA == true) && (eoB == false)) {return true;}
    }while((eoA != true) && (eoB != true));
    return false;
}
bool List::operator<=(class List listB) {
    bool eoA = false, eoB = false;
    class Element *elementA = this -> getFirst();
    class Element *elementB = listB.getFirst();
    do {
        elementA = elementA -> getNext();
        elementB = elementB -> getNext();
        if(elementA == this -> getFirst()) {eoA = true;}
        if(elementB == listB.getFirst()) {eoB = true;}
        if(eoA == true) {return true;}
    }while(eoB != true);
    return false;
}
bool List::operator>(class List listB) {
    bool eoA = false, eoB = false;
    class Element *elementA = this -> getFirst();
    class Element *elementB = listB.getFirst();
    do {
        elementA = elementA -> getNext();
        elementB = elementB -> getNext();
        if(elementA == this -> getFirst()) {eoA = true;}
        if(elementB == listB.getFirst()) {eoB = true;}
        if((eoA == false) && (eoB == true)) {return true;}
    }while((eoA != true) && (eoB != true));
    return false;
}
bool List::operator>=(class List listB) {
    bool eoA = false, eoB = false;
    class Element *elementA = this -> getFirst();
    class Element *elementB = listB.getFirst();
    do {
        elementA = elementA -> getNext();
        elementB = elementB -> getNext();
        if(elementA == this -> getFirst()) {eoA = true;}
        if(elementB == listB.getFirst()) {eoB = true;}
        if(eoB == true) {return true;}
    }while(eoA != true);
    return false;
}
bool List::operator==(class List listB) {
    bool eoA = false, eoB = false;
    class Element *elementA = this -> getFirst();
    class Element *elementB = listB.getFirst();
    do {
        elementA = elementA -> getNext();
        elementB = elementB -> getNext();
        if(elementA == this -> getFirst()) {eoA = true;}
        if(elementB == listB.getFirst()) {eoB = true;}
        if((eoB == true) && (eoA == true)) {return true;}
    }while((eoA == false) && (eoB == false));
    return false;
}
//METODY USUWANIA ELEMENTOW
void List::delByValue (int value) {
    class Element *tempElement = first;
    class Element *prev;
    if(first -> getValue() == value) {
        first = first -> getNext();
        delete tempElement;
        return;
    }
    else {
        prev = tempElement;
        tempElement = tempElement -> getNext();
    }
    while(tempElement != NULL) {
        if(tempElement -> getValue() == value){
            prev -> setNext(tempElement -> getNext());
            delete tempElement;
            return;
        }
        prev = tempElement;
        tempElement = tempElement -> getNext();
    }
    std::cout << "Nie znaleziono elementu do usuniecia" << std::endl;
}
void List::delByValue(int minimum, int maximum) {
    class Element *tempElement = first;
    class Element *prev;
    while((first != NULL)&&(first -> getValue() <= maximum)&&(first -> getValue() >= minimum)) {
        first = first -> getNext();
        delete tempElement;
        tempElement = first;
    }
    prev = tempElement;
    tempElement = tempElement -> getNext();
    while(tempElement != NULL) {
        if((tempElement -> getValue() <= maximum)&&(tempElement -> getValue() >= minimum)){
            prev -> setNext(tempElement -> getNext());
            delete tempElement;
            tempElement = prev -> getNext();
        }
        else{
            prev = tempElement;
            tempElement = tempElement -> getNext();
        }
    }
}
void List::delByIndex(int index) {
    class Element *tempElement = first;
    class Element *prev = NULL;
    for(int i = 1; (i <= index) && (tempElement != NULL); i++) {
        prev = tempElement;
        tempElement = tempElement -> getNext();
    }
    if((tempElement != NULL) && (prev != NULL)){
        prev -> setNext(tempElement -> getNext());
        delete tempElement;
    }
    if((tempElement == first)){
        first = first -> getNext();
        delete tempElement;
    }
}
void List::delDuplicates() {
    class Element *prev, *actual, *next;
    actual = first;
    prev = first;
    next = actual -> getNext();
    do {
            do {
            if(next -> getValue() == actual -> getValue()){
                prev -> setNext(next -> getNext());
                delete &next;
                next = prev -> getNext();
            }
            else {
                prev = next;
                next = next -> getNext();
            }
        } while(next != first);
        if(actual -> getNext() != NULL){
            actual = actual -> getNext();
            prev = actual;
            next = actual -> getNext();
        }
        else
            actual = NULL;
    } while(actual != first);

}
//METODY DODAWANIA ELEMENTOW
void List::addElement (int value) {
    class Element *temp;
    if(first == NULL) {
        first = new Element();
        first -> setValue(value);
        last = first;
    }
    else {
        temp = last;
        last = new Element();
        last -> setValue(value);
        last -> setNext(first);
        temp -> setNext(last);
    }
}
void List::addElement (class Element *original) {
    if(original != NULL) {
        int value = original -> getValue();
        class Element *temp;
        if(first == NULL) {
            first = new Element();
            first -> setValue(value);
            last = first;
        }
        else {
            temp = last;
            last = new Element();
            last -> setValue(value);
            last -> setNext(first);
            temp -> setNext(last);
        }
    }
}
void List::addElement(int value, int indexValue) {
    class Element *prev, *next, *temp;
    if(first == NULL) {
        first = new Element();
        first -> setValue(value);
        last = first;
    }
    else {
        if(indexValue == 0) {
            temp = first;
            first = new Element;
            first -> setNext(temp);
            first -> setValue(value);
            return;
        }
        next = first -> getNext();
        prev = first;
        for(int i = 1; (i < indexValue) && (prev != NULL); i++){
            prev = next;
            next = next -> getNext();
        }
        if(prev != NULL){
            temp = new Element;
            temp -> setNext(next);
            prev -> setNext(temp);
            temp -> setValue(value);
        }
    }
}
void List::addElementAfter(int value, int cmpValue) {
    class Element *prev, *next, *temp;
    if(first == NULL) {
        first = new Element();
        first -> setValue(value);
        last = first;
    }
    else {
        next = first -> getNext();
        prev = first;
        while(next != NULL) {
            if(prev -> getValue() == cmpValue) {
                temp = new Element;
                temp -> setNext(next);
                prev -> setNext(temp);
                temp -> setValue(value);
                return;
            }
            prev = next;
            next = next -> getNext();
        }
        if(prev -> getValue() == cmpValue) {
            temp = new Element;
            temp -> setValue(value);
            last -> setNext(temp);
            last = temp;
        }
    }
}
//SETERY I GETERY
void List::setFirst(class Element *temp) {
    first = temp;
}
int List::getIndex() {
    return index;
}
class Element *List::getFirst() {
    return first;
}
class Element *List::getLast() {
    return last;
}
void *List::setLast(class Element *tempElement) {
    last = tempElement;
}
class Element *List::getByIndex(int index) {
    class Element *tempElement = first;
    for(int i = 1; (i <= index) && (tempElement != NULL); i++) {
        tempElement = tempElement -> getNext();
    }
    return tempElement;
}
class Element *List::getByValue(int value) {
    class Element *tempElement = first;
    while(tempElement != NULL) {
        if(tempElement -> getValue() == value)
            return tempElement;
        tempElement = tempElement -> getNext();
    }
    return tempElement;
}

Element::Element()
    : next(NULL) {}

List::List(int valueOfIndex)
    : first(NULL)
    , last(NULL)
    , index(valueOfIndex) {}

List::List(int valueOfIndex, class List &listToCopy) { //Konstruktor sluzacy do kopiowania obiektu List
    class Element *temp = listToCopy.getFirst();
    index = valueOfIndex;
    if(temp != NULL) {
        addElement(temp);
        temp = temp -> getNext();
    }
    while(temp != listToCopy.getFirst()) {
        addElement(temp);
        temp = temp -> getNext();
    }

}
