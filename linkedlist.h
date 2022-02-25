/*********************
# Name: Caroline Kim
# Data Structure
# Coding Asg 05 - linkedlist.h
# Purpose: Linked List ADT
# NO MODIFICATION ON THIS FILE
**********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include <iostream>

using std::cout;
using std::endl;

class LinkedList {

public:

    LinkedList();
    ~LinkedList();

    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);

    void printList(bool = false);
    int getCount();

    bool clearList();
    bool exists(int);

private:

    Node *head;

    // add nodes (head, tail and middle)
    bool addHead(Node*, Node*);
    bool addTail(Node*, Node*);
    bool addMiddle(Node*, Node*);

    // delete nodes (head, tail and middle)
    bool deleteHead(Node*);
    bool deleteTail(Node*);
    bool deleteMiddle(Node*);

};

#endif