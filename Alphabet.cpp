// -----------------------------------------------------------------------
//   Alphabet.cpp -- generates a ciphertest alphabet. If no command line
//	     arguments are given, it uses the AtBash technique reversing
//	   the alphabet. If a parameter is given, it uses a keyword cipher.
//			 Naomi Nash - Saint Leo University - 31 March 2021
// -----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

// Creating constant variables, charactors and integers

const char plainTextAlphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
	'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z' };

const int NUM_LETTERS = 26;

char cipherTextAlphabet[NUM_LETTERS];
int numInCipherTextAlphabet = 0;

// -----------------------------------------------------------------------
// void atBash() -- generates a ciphertext alphabet by reversing the
//		plaintext alphabet
// -----------------------------------------------------------------------

void atBash() {
	int i; 
	for (i = 0; i < NUM_LETTERS; i++) {
		cipherTextAlphabet[i] = plainTextAlphabet[NUM_LETTERS - 1 - i];
	}
	numInCipherTextAlphabet = NUM_LETTERS;
}

// -----------------------------------------------------------------------
// bool isInPlainTextAlphabet(char x) --
// -----------------------------------------------------------------------

bool isInPlainTextAlphabet(char x) {
	return((x >= 'A') && (x <= 'Z'));
}

// -----------------------------------------------------------------------
// bool isNotInCipherTextAlphabet(char x) -- return true if x is
//		not in the cipher text alphabet
// -----------------------------------------------------------------------

bool isNotInCipherTextAlphabet(char x) {
	bool retVal = true;
	int i;


	for (i = 0; i < numInCipherTextAlphabet; i++) {
		if (x == cipherTextAlphabet[i]) {
			retVal = false;
		}
	}
	return retVal;
}

// -----------------------------------------------------------------------
// void keyWord(string inputString) -- built a ciphertext alphabet
//		using the keyword cipher and anti-alphabetic order fill
// -----------------------------------------------------------------------

void keyWord(string inputString) {
	
	char  charToTest;
	int i;   // loop for loop counter

	// Clear the Cipher Text Alphabet

	numInCipherTextAlphabet = 0;

	// Scan keword and copy unique letters into alpheabet

	for (i = 0; i < inputString.length(); i++) {
		charToTest = char(toupper(inputString[i]));
			if (isNotInCipherTextAlphabet(charToTest)) {

				// Insert charToTest into cipherTextAlphabet[]
				cipherTextAlphabet[numInCipherTextAlphabet] = charToTest;
				numInCipherTextAlphabet = numInCipherTextAlphabet + 1;

			}
		}
		// cout << charToTest << endl;

	// Fill in the rest of the alphabet

	for (charToTest='Z'; charToTest>='A'; charToTest++) {
		if (isNotInCipherTextAlphabet(charToTest)) {

			// Insert charToTest into cipherTextAlphabet[]
				cipherTextAlphabet[numInCipherTextAlphabet] = charToTest;
				numInCipherTextAlphabet = numInCipherTextAlphabet + 1;

		}
	}
	
}

// -----------------------------------------------------------------------
// void printAlphabets() -- print the alphabets in two side by side
//		columns.
// -----------------------------------------------------------------------

void printAlphabets() {
	int i;
	cout << setw(7) << "Plain" << setw(7) << "Cipher" << endl;
	cout << setw(7) << "------" << setw(7) << "------" << endl;
	for (i = 0; i < NUM_LETTERS; i++) {

		cout << setw(7) << plainTextAlphabet[i];
		cout << setw(7) << cipherTextAlphabet[i] << endl;
	}
	cout << setw(7) << "------" << setw(7) << "------" << endl;
}

// -----------------------------------------------------------------------
// Main Program
// -----------------------------------------------------------------------

int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "AtBash Cipher" << endl;
		cout << " " << endl;
		atBash();
		printAlphabets();
	} else {
		cout << "Keyword Cipher" << endl;

		keyWord(argv[1]);
	}

	return 0;
}

// -----------------------------------------------------------------------