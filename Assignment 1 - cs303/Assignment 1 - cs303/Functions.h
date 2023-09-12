#pragma once
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void findValue(int array[], int maxSize);

void modifyValue(int array[], int size, int& oldValue, int& newValue);

void addValue(int array[], int& size, int maxSize);

void replaceOrRemoveValue(int array[], int& size, bool& replace);

void showList(int array[], int size, int maxSize);