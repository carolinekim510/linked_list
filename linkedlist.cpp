/*********************
# Name: Caroline Kim
# Data Structure
# Coding Asg 05 - linkedlist.cpp
# Purpose: Linked List ADT
# NO MODIFICATION ON THIS FILE
**********************/

#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = nullptr; // list is empty
}

LinkedList::~LinkedList() {clearList();}

// printing list
void LinkedList::printList(bool printing)
{
    Node *current = head;
    if (!printing) {
        while(current)
        {
            cout << current->data.id << ": " << current->data.data << " ";
            current = current->next;
        }
    } else {
        while(current->next != nullptr)
        {
            current = current->next;            // --> going all the way to the end
        }
        while(current != nullptr)
        {
            cout << current->data.id << ": " << current->data.data << endl;
            current = current->prev;
        }
    }
}


// dynamically adding node
bool LinkedList::addNode(int id, string* stringData)
{
    bool result = false;
    if ((id >= 0) && !stringData->empty())          // checking id and data isn't negative or empty string
        {
            Node *current = head;                   //  setting the pointer of the location
            if (current == nullptr)                 // inserting NEW head in EMPTY list
            {
                Node *newNode;
                newNode = new Node;
                newNode->data.id = id;
                newNode->data.data = *stringData;
                newNode->prev = newNode->next = nullptr;
                head = newNode;
                result = true;

            } else {        // checking the EXISTING head and new insert to the list
                // while loop through checking lower id than prev and next is not the nullptr
                while(current->next != nullptr && id > current->data.id){
                    current = current->next;  // finding the spot where it's going to go
                }

                // Checking for DUPLICATES
                if(id != current->data.id)
                {
                    Node *newNode;
                    newNode = new Node;
                    newNode->data.id = id;
                    newNode->data.data = *stringData;
                    // object -- always to create an object before the break
                    if (current->prev == nullptr && id < current->data.id)          //head node
                    {
                        result = addHead(current, newNode);
                    }
                    else if (current->next == nullptr && id > current->data.id)     //tail node
                    {
                        result = addTail(current, newNode);
                    } else {                                                        // middle node
                        result = addMiddle(current, newNode);
                    }
                 }
            }
        }
    return result;
}



// add node: head, middle and tail
// head:
bool LinkedList::addHead(Node *current, Node *newNode) {
    newNode->prev = nullptr;
    newNode->next = current;
    current->prev = newNode;
    head = newNode;
    return true;
}

// tail:
bool LinkedList::addTail(Node *current, Node *newNode) {
    current->next = newNode;
    newNode->prev = current;
    newNode->next = nullptr;
    return true;
}

// middle:
bool LinkedList::addMiddle(Node *current, Node *newNode) {
    Node *copyNode = current->prev;
    current->prev = newNode;
    newNode->next = current;
    newNode->prev = copyNode;
    copyNode->next = newNode;
    return true;
}




// counting list
int LinkedList::getCount() {
    int nodeCount = 0;
    Node *current = head;
    while(current)
    {
        current = current->next;
        nodeCount++;
    }
    return nodeCount;
}




// getting NODE
bool LinkedList::getNode(int id , Data *stringData) {       // need to grab this string data and crete place to value inside.
    bool gotNode = false;
    Node *current = head;
    stringData->id = -1;
    stringData->data = "";
    while(current != nullptr){
        if(id == current->data.id){
            stringData->id = current->data.id;
            stringData->data = current->data.data;
            gotNode = true;
        }
        current = current->next;
    }
    return gotNode;
}


// deleting node
bool LinkedList::deleteNode(int id) {
    bool deleted = false;
    Node *current = head;

    if (current) {           // taking cares the empty list
        while (current && id != current->data.id)
        {
            current = current->next;
        }
        if (current) {          // current != is not null pointer node to be deleted
            if (current->prev == nullptr)       // checking only element from the list
            {
                deleted = deleteHead(current);
            } else if (current->next == nullptr)    // removing tail node id
            {
                deleted = deleteTail(current);
            } else {
                deleted = deleteMiddle(current);
            }
        }
    }
    return deleted;
}





// delete node (head, tail, middle)
// head:
bool LinkedList::deleteHead(Node *current) {
    if (current->next == nullptr) {
        head = nullptr;         // linking the pointer to the null, since there is only one element left in the list
        delete current;
        return true;
    } else {
        head = current->next;
        current->next->prev = nullptr;
        delete current;
        return true;
    }
}

// tail:
bool LinkedList::deleteTail(Node *current) {
    current->prev->next = nullptr;
    delete current;
    return true;
}

// middle:
bool LinkedList::deleteMiddle(Node *current) {
    Node *copyNode = current->next;
    current->prev->next = copyNode;
    copyNode->prev = current->prev;
    delete current;
    return true;
}





// checking exisitings
bool LinkedList::exists(int id) {
    bool existedNode = false;
    Node *current = head;
    while (current)
    {
        if (id == current->data.id){
            existedNode = true;
        }
        current = current->next;
    }
    return existedNode;
}





// clearning the list
bool LinkedList::clearList() {
    bool cleared = false;
    Node *current = head;  //starting with null
    while (current){     //newNode-- is like a room that is trying to sent to.
        current = current->next;    //setting the pointer to the next pointer
        delete head;
        head = current;
    }
    cleared = true;
    return cleared;
}

