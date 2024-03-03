/* Alex Surprenant
* CS 210
* Project 3
* 3/3/2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "GroceryItem.h"

using namespace std;

/*  **TODO**
*	Comment all functions and code
*	create backup file
*	add name and date to main file
*	
*/

//main program loop function
int main() {
	GroceryItems inventory("Inventory.txt");
	
	inventory.mainMenu();
		
	return 0;
}



