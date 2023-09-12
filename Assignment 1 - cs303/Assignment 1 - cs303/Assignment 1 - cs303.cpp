// Assignment 1 - cs303.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <fstream>
#include "Functions.h"
using namespace std;

int main() {
    int list[999];
    int maxSize = 999, size = 0;
    int oldValue, newValue;
    bool replace = false;

    //open file. if it doesnt exist, exits program
    ifstream inFile;
    inFile.open("data.txt");
    if (!inFile.is_open()) {
        cout << "Input file invalid\n";
        exit(0);   
    }

    //inputs integers from file to list. Also grabs the current size of the list
    int integers;
    while (inFile >> integers) {
        list[size] = integers;
        size += 1;
    }
    

    //shows array list containing integers
    showList(list, size);



    //----------------------------------------------------------------------------
    //function to find the index of value
    findValue(list, maxSize);
    showList(list, size);

    //function to modify value of the index. grabs old value and new value
    modifyValue(list, maxSize, oldValue, newValue);
    showList(list, size);
        

    //function to add new value at the end of list.
    addValue(list, size, maxSize);
    showList(list, size);

    //function to replace value with 0 or remove the integer completely from list
    replaceOrRemoveValue(list, size, replace);
    showList(list, size);
    
    


    
    









}
