// -----------------------------------------------------------------------
//     FileIO -- Assigns random grades to students in a new file
//          Naomi Nash - Saint Leo University - 7 April 2021
// -----------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

string NAMES[] = { "Alice", "Bob", "Carla", "Dave", "Eve", "Fred", "Gina" };

// -----------------------------------------------------------------------
// void writeDataFile(const char* fileName) -- create a file with random
//		grades for each name in NAMES[]
// -----------------------------------------------------------------------

void writeDataFile(const char* fileName) {
	int i;
	ofstream myTargetFile; // ofstream = output file stream

	// Initialize random number generator
	srand(time(0));

	// Attempt to open the file to write
	myTargetFile.open(fileName);

	if (myTargetFile.is_open()) {
		myTargetFile << left << setw(10) << "Name" << left << setw(10)
			<< "Grade" << endl;

		myTargetFile << left << setw(10) << "---------" << left << setw(10)
			<< "---------" << endl;
		for (i = 0; i < 7; i++) {
			myTargetFile << left << setw(10) << NAMES[i];
			myTargetFile << left << setw(10) << (51 + rand() % 50) << endl;
		}

		myTargetFile << left << setw(10) << "=========" << left << setw(10)
			<< "=========" << endl;

		myTargetFile.close();
	}
	else {
		cout << "ERROR: Could not open " << fileName << endl;
	}
}

// -----------------------------------------------------------------------
// void readAndPrintFile(const char* fileName) -- read the file and print
//		it through cout
// -----------------------------------------------------------------------

void readAndPrintFile(const char* fileName) {
	ifstream mySourceFile;    // ifstream = input file stream
	string myLineOfData;
	string name;
	int grade;
	int i;

	mySourceFile.open(fileName);
	if (mySourceFile.is_open()) {
		while (!(mySourceFile.eof())) {
			getline(mySourceFile, myLineOfData);
			cout << myLineOfData << endl;
		}
		mySourceFile.close();
	}
	else {
		cout << "ERROR: Could not open " << fileName << endl;
	}
}

// -----------------------------------------------------------------------
// Main Program
// -----------------------------------------------------------------------

int main(int argc, char** argv) {
	writeDataFile("grades.txt");
	writeDataFile("grades.txt");
	return 0;
}

// -----------------------------------------------------------------------