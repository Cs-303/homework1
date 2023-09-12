#include "Functions.h"

void findValue(int array[], int maxSize) {
	int input;
	cout << "Enter the value you want to find: ";
	cin >> input;

	//catches error for string input. must be a number for value.
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input received, you must enter a number.";
		return;
	}

	bool found = false;
	//Outputs the index of input value if available in array. if not, outputs that it doesnt exist
	for (int i = 0; i < maxSize; i++) {
		if (array[i] == input) {
			cout << "Value is at index " << i;
			found = true;
		}
	}
	if (!found) cout << "Value does not exist within array.";
};



void modifyValue(int array[], int size,	int& oldValue, int& newValue) {
	try {
		//input for index
		int index;
		cout << "Enter the index you want to modify: ";
		cin >> index;

		//catches error for string input. must be a number for index.
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw runtime_error("Invalid input received, you must enter a number.");
		}

		//if index is outside the boundary of array, throws out of range error for illegal index outside of array
		if (index >= 0 && index < size) {
			//enter input for newValue
			int input;
			cout << "Enter the value you want to replace with: ";
			cin >> input;

			//catches error for string input. must be a integer.
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw runtime_error("Invalid input received, you must enter a integer.");
			}

			//newValue and oldValue is updated. index value get replaced with newValue
			newValue = input;
			oldValue = array[index];
			array[index] = newValue;

			cout << "Old Value is " << oldValue << "\nNew Value is " << newValue;
		}
		else throw out_of_range("Index is outside of bound of array. Out of range");  //throws out of bound error
	}
	//catches error
	catch (out_of_range e) { cout << e.what(); }
	catch (runtime_error e) { cout << e.what(); }
	catch (...) { cout << "Exception Error"; }
};



void addValue(int array[], int& size, int maxSize) {
	try {
		//if current array size matches the maximum array size, throws out of range error as current size cannot get higher than array maximum size
		if (size >= maxSize) throw out_of_range("Array size cannot get any higher. Out of range");
		else {
			//input for the integer you want to add in end of list.
			int input;
			cout << "Enter the value you want to add at end of list: ";
			cin >> input;

			//catches error for string input. must be a integer.
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw runtime_error("Invalid input received, you must enter a number.");
			}

			array[size] = input; //value is added to end of list
			size += 1; //size increase by 1
			cout << input << " is added to end of list";
		}
	}
	//catches error
	catch (out_of_range e) { cout << e.what(); }
	catch (runtime_error e) { cout << e.what(); }
	catch (...) { cout << "Exception Error"; }
};



void replaceOrRemoveValue(int array[], int& size, bool& replace) {
	//input for index
	int index;
	cout << "Enter the index you want to replace or remove: ";
	cin >> index;

	//catches error for string input. must be a number for index.
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input received, you must enter a number.";
		return;
	}

	//detects if index is outside the boundary of array
	if (index >= 0 && index < size) {
		//input for bool replace
		cout << "Enter 1 to replace or 0 to remove: ";
		cin >> replace;

		if (replace) { //if replace option is true, it will replace the index array value with a 0
			array[index] = 0;
			cout << "value at index " << index << " is now replaced with 0";
		}
		else { // if replace option is false, it will remove the integer and index completely from the array.
			for (int i = index; i < size - 1; i++) array[i] = array[i + 1]; //index is the starting point of forloop. from that point, every integer will become the next right integer in array
			size -= 1; //array size decrease by 1

			cout << "value at index " << index << " is now removed from the list";
		}
	}
	else cout << "Index is outside the bound of array"; //error message if index is invalid
};



void showList(int array[], int size, int maxSize) {
	//forloop function that shows the whole list of integers.
	cout << "current size: " << size << " | max size: " << maxSize << endl;
	for (int i = 0; i < size; i++) cout << array[i] << " ";
	cout << "\n\n";
};