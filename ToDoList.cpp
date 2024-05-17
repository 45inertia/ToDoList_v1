// ToDoList.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// The purpose of this program is a to-do list manager. The functionality includes:
// 1) Creating an array [10] for strings
// 2) Adding a string to the array
// 3) Displaying the array to the user
// 3) Removing an item from the array
// 
// This is the first iteration of a to-do list. All functionality will be performed in the main function.
// 

#include <iostream>
#include <string>

int main() {
	/*
	std::string firstString{"This is my first string"};
	*/
	std::string itemArray[10]; // initialise the array
	int endCheck{ 1 };
	int menuNum{};
	int numItems{0};
	int itemsToAdd{};
	int removeChoice{};
	while (endCheck == 1) {
		std::cout << "\n(1) View List\n";
		std::cout << "(2) Add items to list\n";
		std::cout << "(3) Remove item from list\n";
		std::cout << "(4) Exit Program\n";
		std::cout << "\nPlease select your option: ";
		std::cin >> menuNum;

		switch (menuNum) {
			case 1:
				if (numItems == 0) {
					std::cout << "\nList is empty.\n";
				}
				else {
					std::cout << "\nYour list:\n";
					for (int i = 0; i < numItems; i++) {
						std::cout << "\n" << i + 1 << " " << itemArray[i];
					}
					std::cout << "\n";
				}
				break;
			case 2:
				
				std::cout << "\nHow many items would you like to add: ";
				std::cin >> itemsToAdd;
				std::cin.ignore(); // ignores the newline character left in the buffer ??

				if (numItems + itemsToAdd > 10) {
					std::cout << "Cannot add that many items. Maximum capacity is 10.\n";
				}
				else {
					for (int i = 0; i < itemsToAdd; i++) {
						std::cout << "\nPlease enter a string: ";
						std::getline(std::cin, itemArray[numItems]); // look into "std::getline"
						numItems++;
					}
				}
				break;
			case 3:
				if (numItems == 0) {
					std::cout << "\nList is empty, nothing to remove.\n";
				}
				else {
					std::cout << "\nYour list:\n";
					for (int i = 0; i < numItems; i++) {
						std::cout << "\n" << i + 1 << " " << itemArray[i];
					}
					std::cout << "\n\nWhich item would you like to remove: ";
					std::cin >> removeChoice;
					if (removeChoice < 1 || removeChoice > numItems) {
						std::cout << "Invalid Choice.\n";
					}
					else {
						// Shifting items to the left
						for (int i = removeChoice - 1; i < numItems - 1; i++) {
							itemArray[i] = itemArray[i + 1];
						}
						itemArray[numItems - 1].clear();
						numItems--;
					}
				}
				break;
			case 4:
				endCheck = 0;
				break;
			default:
				std::cout << "Please enter a number from 1-4.";
				break;
		}	
	}

	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
