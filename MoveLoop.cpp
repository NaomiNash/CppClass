// -----------------------------------------------------------------------
//        MoveLoop.cpp - simulates movement on a 2D grid
//		  Naomi Nash - Saint Leo UNiversity - 26 Feb 2021
// -----------------------------------------------------------------------

#include <iostream>
#include <cctype>
using namespace std;

// -----------------------------------------------------------------------
// void printLocation (int x, int y) -- report user location
// -----------------------------------------------------------------------

void printLocation(int x, int y) {   // prints original location
	cout << "You are at location (" << x << ", " << y << ")." << endl;
}

// -----------------------------------------------------------------------
// void printHelp() -- print out a list of valid commands
// -----------------------------------------------------------------------

void printHelp() {   // shares commands if the user does not know them
	cout << "Valid Commands: ? = Help; N = North; S = South; ";
	cout << "E = East, W = West; Q = Quit" << endl;
}
// -----------------------------------------------------------------------
//bool isValidCommand (char inLetter) -- return true if inLetter is a
//		valid command code
// -----------------------------------------------------------------------
bool isValidCommand(char inLetter) {   // == is equal to, || is or
	return ((inLetter == 'Q') || (inLetter == 'N') || (inLetter == 'S') 
		|| (inLetter == 'E') || (inLetter == 'W') || (inLetter == '?'));
}

// -----------------------------------------------------------------------
//char getCommand() -- prompt the user until they enter a valid
//		command code, and give an error message when they fail to do so,
//		return the valid command codes
// -----------------------------------------------------------------------
char getCommand() {   // returns a charactor
	char userInput = '*';

	while (!(isValidCommand(userInput))) {

		cout << "Please enter a command.";
		cin >> userInput;
		userInput = char(toupper(userInput));

		if (isValidCommand(userInput)) {
			cout << "You entered the command '" << userInput << "'." << endl;
		} else {
			cout << "Invalid command '" << userInput << "'." << endl;
			printHelp();
		}
	}
	
	return userInput;
}
// -----------------------------------------------------------------------
// Main Program
// -----------------------------------------------------------------------
int main() {
	char userCommand = '*';
	int myX = 0;
	int myY = 0;

	while (userCommand != 'Q') {
		printLocation(myX, myY);
		userCommand = getCommand();
		cout << "You entered the command '" << userCommand << "'." << endl;

		switch (userCommand) {
			case 'N': myY = myY + 1; break;
			case 'S': myY = myY - 1; break;
			case 'E': myX = myX + 1; break;
			case 'W': myX = myX - 1; break;
			case '?': printHelp(); break;
			default: break;
		}
	}

	return 0;
}
// -----------------------------------------------------------------------