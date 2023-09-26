#include <iostream>
#include <iomanip>
using namespace std;

const int NUMCOLUMNS = 10;    // const assigns it a value that should never change, and if you try to do so you will get an error
const int COLWIDTH = 5;
const int NUMDIGITS = 3;

// -----------------------------------------------------------------------
// -----------------------------------------------------------------------

void printLine(char myChar) {       // void is a helper fuction which is used inside the main program that helps print the multiplication table columns
	int i, j; // Loop Counters
	
	for (i = 0; i <= NUMCOLUMNS; i++) {
		for (j = 0; j < COLWIDTH; j++) { // Sets j to 0; prints as long as j is less than COLWIDTH (5); adds 1 to j each time
			cout << myChar;
		}
		cout << "+";
	}
	cout << endl;

}

// -----------------------------------------------------------------------
// -----------------------------------------------------------------------

int main() {
	int row, col; //Loop Counters


	//
	printLine('=');    // Prints heading of multiplication table
	cout << setw(5) << right << "*" << "|";
	for (col = 1; col <= NUMCOLUMNS; col++) {
		cout << setw(5) << right << col << "|";
	}
	cout << endl;
	printLine('=');  // Calling printLine helper function programmed above

	for (row = 1; row <= NUMCOLUMNS; row++) {
		cout << setw(5) << right << row << "|";

		cout << endl;
		printLine("-");
	}

	return 0;
}
