// -----------------------------------------------------------------------
//           Matrix.cpp -- implements Matrix Multiplication
//          Naomi Nash - Saint Leo University - 5 April 2021
// -----------------------------------------------------------------------

#include <iostream>
#include <iomanip>     // used to set column width
using namespace std;

// -----------------------------------------------------------------------

int A[3][3] = { {4,9,2}, {3,5,7}, {8,1,6} };
int I[3][3] = { {1,0,0}, {0,1,0}, {0,0,1} };
int B[3][3] = { {1,0,2}, {0,3,0}, {4,0,5} };
int C[3][3];

// -----------------------------------------------------------------------
// void printMatrix(int myPointer[3][3]) -- print the matrix
// -----------------------------------------------------------------------

void printMatrix(int myPointer[3][3]) {
	int i, j;  // Loop counters
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			// Set i to be row and j ot be columns
			cout << setw(5) << myPointer[i][j];
		}
		cout << endl;
	}
}

// -----------------------------------------------------------------------
// void multipleABintoC(int x[3][3], int y[3][3], int z[3][3]) -- 
//		multiplies two matricies together to make a new matrix
// -----------------------------------------------------------------------

void multipleABintoC(int x[3][3], int y[3][3], int z[3][3]) {
	int i, j, k; // Loop Counters
	for (i = 0; i < 3; i++) {
	// i selects row in x
		for (j = 0; j < 3; j++) {
		// j selects col in y
			z[i][j] = 0;
			for (k = 0; k < 3; k++) {
				z[i][j] = z[i][j] + (x[i][k] * y[k][j]);
			}

		}
	}
}

// -----------------------------------------------------------------------
// Main Program
// -----------------------------------------------------------------------

int main(int arc, char** argv) {
	cout << "Matrix A" << endl;
	printMatrix(A);
	cout << endl << "Matrix B" << endl;
	printMatrix(B);

	cout << endl << "Multiply A and B into C" << endl;
	multipleABintoC(A, B, C);

	cout << endl << "Matrix C = A * B" << endl;
	printMatrix(C);

	cout << endl << "Matrix I" << endl;
	printMatrix(I);

	cout << endl << "Multiply A and I into C" << endl;
	multipleABintoC(A, I, C);

	cout << endl << "Matrix C = A * I" << endl;
	printMatrix(C);

	return 0;
}

//------------------------------------------------------------------------