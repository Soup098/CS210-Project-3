/* Alex Surprenant
* CS 210
* Project 3
* 3/3/2024
*/


#include <fstream>
#include <iostream>
#include <string>
#include "GroceryItem.h"

using namespace std;

/*GroceryItems Class constructor with implementation of
* file opening and closing. Stores file data in items map
* 
*/
GroceryItems::GroceryItems(string filename){
	ifstream inputFS;

	cout << "Opening file Inventory.txt" << endl;
	cout << endl;

	inputFS.open(filename);// open file and check if open correctly
	if (!inputFS.is_open()) {
		cout << "could not open file Inventory.txt" << endl;
		return;
	}
	string item;
	/*while loop that gets contents
	* i dont think getline was necessary, but it was the only way i could
	* get the while loop to work correctly
	*/
	while (getline(inputFS, item)) {//while loop that gets contents and stores them in the items map
		items[item]++;
	}
	inputFS.close();
	
}

//mainMenu() function for the main program loop to give user menu options
int GroceryItems::mainMenu() {
	int userChoice = 0;
	
	while (userChoice != 4) {
		cout << "Please choose an option number and hit enter:  " << endl;
		cout << "1. Search for specific item frequency" << endl;
		cout << "2. Print all item frequencies" << endl;
		cout << "3. Print all item histogram" << endl;
		cout << "4. exit program" << endl;
		cin >> userChoice;

		if (cin.fail() || userChoice < 1 || userChoice > 4) {
			cout << "Invalid input" << endl;
			cin.clear();
			cin.ignore();
		}
		else if (userChoice == 1) {// get item from user and output quantity
			string name = getName();
			if (items.find(name) != items.end()) {
				cout << name << " " << items[name] << endl;
				cout << endl;
			}
			else {//
				cout << "item not found" << endl;
			}
		}
		else if (userChoice == 2) {
			printItemFrequencies(items);
		}
		else if (userChoice == 3) {
			printItemHistogram(items);
		}
	}
	return 0;
}
// getName function for user choice 1. gets user input for name of item and returns it.
string GroceryItems::getName() {
	string name;
	cout << "Enter item name: " << endl;
	cin >> name;

	return name;
}
// printItemFrequencies function for printing out all of the items in the file and their frequencies
void GroceryItems::printItemFrequencies(const map<string, int>& items) {//Take the map as a const reference to avoid copying of the map
	cout << "Items and their frequencies: " << endl;
	cout << endl;
	for (const auto pair : items) {//outputs items from map based on key value
		cout << pair.first << " " << pair.second << endl;
	}
	cout << endl;
}
// printItemHistogram to output items with an astrisk based on item quantity.
void GroceryItems::printItemHistogram(const map<string, int> items) {//Take the map as a const reference to avoid copying of the map
	cout << "Frequency histogram: " << endl;
	cout << endl;
	for (const auto pair : items) {
		cout << pair.first << " ";
		for (int i = 0; i < pair.second; ++i) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
}