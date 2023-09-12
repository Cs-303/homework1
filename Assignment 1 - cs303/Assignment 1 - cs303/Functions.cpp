#include "Functions.h"

void findValue(int array[], int maxSize) {
	int input;
	cout << "Enter the value you want to find: ";
	cin >> input;

	bool found = false;
	//Outputs the index of value if available in array. if not, say it doesnt exist
	for (int i = 0; i < maxSize; i++) {
		if (array[i] == input) {
			cout << "Value is at index " << i << endl;
			found = true;
		}
	}
	if (!found) cout << "Value does not exist within array.\n";
};


void modifyValue(int array[], int maxSize, int& oldValue, int& newValue) {
	try {
		//input for index
		int index;
		cout << "Enter the index you want to modify: ";
		cin >> index;

		//if index is outside the boundary of array, throws out of range error for illegal index within array
		if (index >= 0 && index < maxSize) {
			int input;

			//enter input for newValue
			cout << "Enter the value you want to replace with: ";
			cin >> input;

			//newValue and oldValue is updated. index value get replaced with newValue
			newValue = input;
			oldValue = array[index];
			array[index] = newValue;

			cout << "Old Value is " << oldValue << "\nNew Value is " << newValue << "\n";
		}
		else throw out_of_range("Index is outside of bound of array\n");  //throws out of bound error
	}
	catch (out_of_range e ) { //catches out of range error
		cerr << e.what();
	}
};


void addValue(int array[], int& size, int maxSize) {
	try {
		//if current array size matches the maximum array size, throws out of range error as current size cannot get higher than array maximum size, else out of bound
		if (size >= maxSize) throw out_of_range("Array size cannot get any higher\n\n");
		else {

			//input for the integer you want to add in end of list. size also increase
			int input;
			cout << "Enter the value you want to add at end of list: ";
			cin >> input;
			array[size] = input;
			size += 1;

			cout << input << " is added to end of list\n";
		}
	}
	catch (out_of_range e) { //catches out of range error
		cout << e.what();
	}
};

void replaceOrRemoveValue(int array[], int& size, bool& replace) {
	//input for index
	int index;
	cout << "Enter the index you want to replace or remove: ";
	cin >> index;

	//detects if index is outside the boundary of array
	if (index >= 0 && index < size) {
		//input for bool replace
		cout << "Enter 1 to replace integer or 0 to remove integer completely: ";
		cin >> replace;

		if (replace) { //if replace option is true, it will replace the index array value with a 0
			array[index] = 0;
			cout << "value at index " << index << " is now replaced with 0\n";
		}
		else { // if replace option is false, it will remove the integer and index completely from the array.
			for (int i = index; i < size - 1; i++) array[i] = array[i + 1]; //index is the starting point of forloop. from that point, it will keep grabbing the value of next index
			size -= 1; //array size decrease

			cout << "value at index " << index << " is now removed from the list\n";
		}
	}
	else cout << "Index is outside the bound of array";
};


void showList(int array[], int size) {
	//forloop function that shows the whole list of integers.
	cout << "current size: " << size << endl;
	for (int i = 0; i < size; i++) cout << array[i] << " ";
	cout << "\n\n\n";
};
