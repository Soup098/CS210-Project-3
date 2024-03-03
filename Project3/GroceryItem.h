/* Alex Surprenant
* CS 210
* Project 3
* 3/3/2024
*/


#pragma once
#include <map>
#include <string>

using namespace std;
//GroceryItems class declaration
class GroceryItems
{
	public:
		GroceryItems(string filename);
	
		int mainMenu();
		string getName();
		void printItemFrequencies(const map<string, int>& items);
		void printItemHistogram(const map<string, int> items);

	private:
		map<string, int> items;
};