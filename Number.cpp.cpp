
// -----------------------------------------------------------------------
//   Number.cpp - Prompts the user to enter an integer and then reports
//                    some properties of the number.
//            Naomi Nash - Saint Leo University - Feb 8, 2021
// -----------------------------------------------------------------------

#include <iostream>
using namespace std;

int main() {
	int userInput;        // Declares the integer userInput so it can be used in the code
	int digitalRoot;      // Declares the integer digitalRoot so it can be used in the code 

	// Part 1. Get an Integer from the user

	cout << "Please enter a whole number ";         // Asks fot the user to input a whole number
	cin >> userInput;                               // Assigns this number to userInput
	cout << "You entered " << userInput << endl;    // Prints the whole number that the user entered

	// Part 2. Zero, negative, or positive?

	if (userInput == 0) {     // Checks to see if input is equal to 0
		cout << "The value is zero." << endl;     // Prints only if value is equal to 0
	} else {
		if (userInput < 0) {      // Checks to see if the userInput is less than 0 (i.e. negative)
			cout << "The value is negative." << endl;    // Prints that the input is negative if it is less than 0
		} else {
			cout << "The value is positive." << endl;    // Prints that the input is positive if it is more than 0
		}
	}

	// Part 3. Even or odd?

	if ( (userInput%2) == 0) {       // Uses modular math on the userInput (by 2)
		cout << "The value is even." << endl;      // States input is even if mod 2 equals 0
	} else {
		cout << "The value is odd." << endl;       // States input to odd if mod 2 does not equal 0 (i.e. 1)
	}

	// Part 4. Compute the digital Root

	digitalRoot = userInput;       // Sets digitalRoot equal to userInput
	
	if (digitalRoot < 0) digitalRoot = digitalRoot * -1;     // Sets the number to be positive if it is negative
	// Curly braces don't have to be used all the time as shown in the above statement
	digitalRoot = digitalRoot % 9;     // Uses modular math to find the digital input

	if (digitalRoot == 0) digitalRoot = 9;     // Sets the digitalRoot to 9 if it's modular remainder is 0

	cout << "The Digital Root of the value is " << digitalRoot << endl;    // Prints digitalRoot value

	return 0;
}