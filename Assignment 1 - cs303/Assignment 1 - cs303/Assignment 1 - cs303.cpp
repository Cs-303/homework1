// Assignment 1 - cs303.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <fstream>
#include "Functions.h"
using namespace std;

int main() {
    int list[102];
    int maxSize = 102, size = 0;
    int oldValue, newValue;
    bool replace = false;
    char choice;

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
    

    
    //while loop until user quit. gives 5 options of what user what to do with array
    do {
        showList(list, size, maxSize);
        cout << "---Options---\n" 
            << "1 - find the index of value within array\n" 
            << "2 - modify a Value within array\n" 
            << "3 - add a value to end of list\n"
            << "4 - replace a value with 0 or remove value completely\n" 
            << "Q - Quit\n";
        cout << "What choice would you like to pick? ";
        cin >> choice;

        switch (toupper(choice)) {
        case '1':
            //function to find the index of value
            findValue(list, maxSize);
            break;

        case '2':
            //function to modify value of the index. grabs old value and new value
            modifyValue(list, size, oldValue, newValue);
            break;

        case '3':
            //function to add new value at the end of list.
            addValue(list, size, maxSize);
            break;

        case '4':
            //function to replace value with 0 or remove the integer completely from list
            replaceOrRemoveValue(list, size, replace);
            break;

        case 'Q':
            //press q to quit
            cout << "You entered Q. Closing Program.";
            break;
        }
        cout << "\n\n\n";
    } 
    while (toupper(choice) != 'Q');

    
    









}
