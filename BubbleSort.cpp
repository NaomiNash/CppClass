// -----------------------------------------------------------------------
//				BubbleSort.cpp -- implements bubble sort
//			Naomi Nash - Saint Leo University - 15 March 2021
// -----------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Global Variables

const int MAX_NUMBER_ITEMS = 8;

int myData[MAX_NUMBER_ITEMS];

// -----------------------------------------------------------------------
// void initializeMyData() -- populate myData[] with random ints
//		between 0 and 99
// -----------------------------------------------------------------------

void initializeMyData() {
	int i;
	srand(time(0)); // Gets the time from the system clock (on computer)
	for (i = 0; i < MAX_NUMBER_ITEMS; i++) {
		myData[i] = rand() % 100; // Gets random numbers between 0 and 99
	}
}

// -----------------------------------------------------------------------
// void printMyData() -- print out the contents of myData 
// -----------------------------------------------------------------------

void printMyData() {
	int i;
	for (i = 0; i < MAX_NUMBER_ITEMS; i++) {
		cout << "+------";
	}
	cout << "+" << endl;

	for (i = 0; i < MAX_NUMBER_ITEMS; i++) {
		cout << "|" << setw(6) << myData[i];
	}
	cout << "|" << endl;

	for (i = 0; i < MAX_NUMBER_ITEMS; i++) {
		cout << "+------";
	}
	cout << "+" << endl;
}

// -----------------------------------------------------------------------
// bool isOutOfOrder(int A, int B) -- return true if B should be before A
// -----------------------------------------------------------------------

bool isOutOfOrder(int A, int B) {
	return (B < A);
}

// -----------------------------------------------------------------------
// void swap(int* A, int* B) --  swap the values pointed at by A and B
// -----------------------------------------------------------------------

void swap(int* A, int* B) {  // Designates pointers
	int temp = *A;  // The temporary value = A pointer
	*A = *B;  // A pointer = B pointer
	*B = temp;  // The B pointer = the temporary value
}

// -----------------------------------------------------------------------
// void bubbleSort() -- sort the contents of myData[] into increasing
//		order
// -----------------------------------------------------------------------

void bubbleSort() {
	int i, j; // Loop Counters
	for (i = 0; i < MAX_NUMBER_ITEMS - 1; i++) {
		for (j = MAX_NUMBER_ITEMS - 1; j > i; j--) {
			if (isOutOfOrder(myData[i], myData[j])) {
				// cout << "Swapping " << myData[i] << " and " << myData[j]
					<< endl;
				swap(&myData[i], &myData[j]);
				// printMyData();
			}
		}
	}
}

// -----------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------

int main() {

	int x = 10;
	int y = 6;

	initializeMyData();
	printMyData();
	bubbleSort();
	printMyData();

	return 0;
}

// -----------------------------------------------------------------------