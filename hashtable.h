/*********************
# Name: Caroline Kim
# Data Structure
# Coding Asg 06 - hashtable.cpp
# Purpose: Hash Tables parting with "seperate chaining"
# Creating a hash tanle object with seperate chaining linekd list.
**********************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "data.h"
#include "linkedlist.h"
#include <iostream>

using std::cout;
using std::endl;

#define HASHTABLESIZE 15

class Hashtable {

public:

    Hashtable();
    ~Hashtable();

    bool insertEntry(int, string);
    bool removeEntry(int);

    string getData(int);
    int getCount();

    void printTable();

private:
    LinkedList hashtable[HASHTABLESIZE];
    int hash(int);
    int count;

    void clearHashtable();
};

#endif //HASHTABLE_H