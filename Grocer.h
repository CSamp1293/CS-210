#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

// Creation of Grocer class
class Grocer {
public:	// Public data members
	int grocerMenu();
	int openFile();
	int menuOption = 0;

private:	// Private data members
	string item;
	int frequency = 0;
	map<string, int> itemFreq;
};

// Menu display function
int Grocer::grocerMenu() {
	do {	// Do-while loop for menu
		cout << "~~~~~Corner Grocer~~~~~" << endl;
		cout << "1. Search for an item" << endl;
		cout << "2. Display item frequencies" << endl;
		cout << "3. Display item histogram" << endl;
		cout << "4. Exit application" << endl;
		cout << endl;
		cout << "Please enter a command: ";
		cin >> menuOption;
		cout << endl;

		// Switch/case for each menu option
		switch (menuOption) {
		case 1: {	// Item search option
			string itemSearch;
			cout << "Please enter the item name: ";
			cin >> itemSearch;
			cout << endl;

			if (itemFreq.count(itemSearch) > 0) {
				cout << itemSearch << " " << itemFreq[itemSearch] << endl;
			}
			else {
				cout << "Item was not found." << endl;
			}
			cout << endl;
			break;
		}
		case 2: {	// Item frequencies display
			for (auto&& item : itemFreq) {
				cout << item.first << " - " << item.second << endl;
			}
			cout << endl;
			break;
		}
		case 3: {	// Histogram display
			for (auto&& item : itemFreq) {
				cout << item.first << " ";
				for (int i = 1; i <= item.second; ++i) {
					cout << "*";
				}
				cout << endl;
			}
			cout << endl;
			break;
		}
		case 4: {	// Exit application
			cout << "Closing application..." << endl;
			break;
		}
		default: {	// Default case for invalid input
			cout << "Invalid input, please enter a valid option." << endl;
		}
		}
	}
		while (menuOption != 4);
		ofstream outFS;	// Outputs file stream

		// Opens file "frequency.dat"
		outFS.open("frequency.dat");
		if (!outFS.is_open()) {	// Checks if file is opened
			cout << "Failed to open file frequency.dat" << endl;
			return 1;
		}

		// For loop to write to file
		for (auto&& item : itemFreq) {
			outFS << item.first << " - " << item.second << endl;
		}

		// Closes file when done
		outFS.close();
	}
	
	// Open file function
	int Grocer::openFile() {
		ifstream inputFile("CS210_Project_Three_Input_File.txt");
		if (!inputFile) {
			cout << "An error occured while attempting to open the file." << endl;
			return 1;
		}

		// Variables used to process each line and word
		string line;
		string word;

		// Processes each line
		while (getline(inputFile, line)) {
			istringstream iss(line);

			// Processes each word
			while (iss >> word) {
				itemFreq[word]++;
			}
		}
	}
