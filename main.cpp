/*********************
# Name: Caroline Kim
# Data Structure
# Coding Asg 06 - hashtable.cpp
# Purpose: Hash Tables parting with "seperate chaining"
# Creating a hash tanle object with seperate chaining linekd list.
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    Hashtable hashtable;

    // show it is empty by calling getCount and printTable
    cout << "1 --------------------------- Calling empty table with counts" << endl;
    cout << "There are " << hashtable.getCount() << " elements in the table." << endl;
    cout << "Printing Hashtable : (empty)" << endl;
    hashtable.printTable();
    cout << endl;


    // try and put ALL the test data into the table and show what happens
    cout << "2 --------------------------- Inserting Test Data..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        if (hashtable.insertEntry(ids[i], strs[i])) {
            cout << "Success --- entry inserted    " << ids[i] << ":" << strs[i] << endl;
            cout << "Inserted counts: " << hashtable.getCount() << endl;
            cout << endl;
        } else {
            cout << "Fail    --- data invalid" << endl;
            cout << endl;
        }
    }


    // Printing the table per index of the hashtable
    cout << endl;

    cout << "3 --------------------------- Getting data by location of index..." << endl;
    hashtable.printTable();


    // Printing the data from hashtable
    cout << endl;
    cout << "4 --------------------------- Retriving ALL data from Hashtable..." << endl;
    string copyData = "";
    for (int i = 0; i < testdatasize; i++) {
        copyData = hashtable.getData(ids[i]);
        if(!copyData.empty()){
            cout << ids[i] << ": " << copyData << endl;
        } else {
            cout << "failed: Data Invalid" << endl;
            cout << endl;
        }
    }


    // continue using and testing your table, add and remove data,
    cout << "5 --------------------------- Table before remove" <<  endl;
    hashtable.printTable();
    cout << endl;

    cout << "6 --------------------------- Now removing... " <<  endl;
    cout << ids[testdatasize - 4] << ": " <<hashtable.getData(ids[testdatasize - 4]) << endl;
    if (hashtable.removeEntry(ids[testdatasize - 4])){
        cout << "-- success" << endl;
    } else {
        cout << "-- data invalid" << endl;
    }
    cout << ids[testdatasize / 2] << ": " <<hashtable.getData(ids[testdatasize / 2]) << endl;
    if (hashtable.removeEntry(ids[testdatasize/2])){
        cout << "-- success" << endl;
    } else {
        cout << "-- data invalid" << endl;
    }

    cout << endl;
    cout << "7 --------------------------- Table after" <<  endl;
    hashtable.printTable();



    // clearing the hashtable for the testing cases
    cout << "8 --------------------------- Removing all elements from hashtable" <<  endl;
    for(int i = 0; i < testdatasize; i++) {
        hashtable.removeEntry(ids[i]);
    }
    cout << endl;
    cout << endl;




    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    // robusting the test with cases
    cout << "/*******************************/" << endl;
    cout << endl;
    cout << "     START Random testing ..." << endl;
    cout << endl;
    cout << "/*******************************/" << endl;
    for (int i = 0; i < RANDOM_TRIES; i++) {
        int choice = rand() % CHOICES + 1;
        int idx = rand() % testdatasize / 2;
        string copyData = "";
        switch (choice){
            case 1:
            case 2:
                // inserting data
                cout << "\nStart inserting" << endl;
                if (hashtable.insertEntry(ids[idx], strs[idx])) {
                        cout << "Success --- entry inserted    " << ids[idx] << ":" << strs[idx] << endl;
                        cout << "Inserted counts: " << hashtable.getCount() << endl;
                        cout << endl;
                    } else {
                        cout << "Fail    --- data invalid" << endl;
                        cout << endl;
                    }
                break;
            case 3:
                // counting data
                cout << "\nCounting elements" << endl;
                cout << "Total inserted elements counts: " << hashtable.getCount() << endl;
                break;
            case 4:
                // getting data
                cout << "\nGetting data" << endl;
                cout << ids[idx] << ": " << hashtable.getData(ids[idx]) << copyData << endl;
                if (!hashtable.getData(ids[idx]).empty()){
                    //cout << ids[idx] << ": " << hashtable.getData(ids[idx]) << copyData << endl;
                    cout << "   success retrive data" << endl;
                } else {
                    cout << "   failed retrive data" << endl;
                }
                break;
            case 5:
                // removing data
                cout << "\nRemoving data" << endl;
                cout << ids[idx] << ": " <<hashtable.getData(ids[idx]) << endl;
                if (hashtable.removeEntry(ids[idx])){
                    cout << "-- success" << endl;
                } else {
                    cout << "-- data invalid" << endl;
                }
                break;
            case 6:
                // printing table
                cout << "\nPrinting hashtable" << endl;
                hashtable.printTable();
                cout << endl;
                break;
        }
    }


    return 0;
}
