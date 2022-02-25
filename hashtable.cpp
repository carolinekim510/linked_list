/*********************
# Name: Caroline Kim
# Data Structure
# Coding Asg 06 - hashtable.cpp
# Purpose: Hash Tables parting with "seperate chaining"
# Creating a hash tanle object with seperate chaining linekd list.
**********************/

#include "hashtable.h"

Hashtable::Hashtable(){count = 0;}

Hashtable::~Hashtable(){clearHashtable();}


int Hashtable::hash(int id) {
    return id % HASHTABLESIZE;
}


// inserting data to hashtable
bool Hashtable::insertEntry(int id, string stringData) {
    bool inserted = false;
    int position = hash(id);

    if ((id > 0) && !stringData.empty())
    {
        cout << "Hashtable position: " << position << endl;
        inserted = hashtable[position].addNode(id, &stringData);
        if(inserted) { count++; }
    }
    return inserted;
}


// removing data from hashtable
bool Hashtable::removeEntry(int id) {
    bool removed = false;
    int position = hash(id);
    if (id > 0) {
        removed = hashtable[position].deleteNode(id);
        if (removed) { count--; }
    }
    return removed;
}



string Hashtable::getData(int id) {
    string tempData = "";
    Data copyData;
    int position = hash(id);
    if (id > 0)
    {
        hashtable[position].getNode(id, &copyData);
        tempData = copyData.data;
    }
    return tempData;
}



int Hashtable::getCount() {
    return count;
}



void Hashtable::printTable() {
    for (int i = 0; i < HASHTABLESIZE; i++){
        cout << "Hashtable " << i+1 << ": ";
        hashtable[i].printList(false);
        cout << endl;
    }

}

void Hashtable::clearHashtable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        hashtable[i].clearList();
    }
}
