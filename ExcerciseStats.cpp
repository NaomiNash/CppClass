
// -----------------------------------------------------------------------
//   Exercise Stats - Performs some calculations for a personal trainer
//       Naomi Nash - Saint Leo University - February 10, 2021
// -----------------------------------------------------------------------

#include <iostream>
#include <string> // Lets us use the string library, useful for using getline command
using namespace std;

int main() {
    string customerName;
    int customerAge, customerWeight, customerHeight;
    double maximumHeartRate, aerobicRate, BMI;

    // Part 1. Enter Customer Data

    cout << "Please enter the customer name. ";
    getline(cin, customerName); // Reads over the spaces in a string/Reads the whole line entered by user

    cout << "Please enter the customer's age in years. ";
    cin >> customerAge;

    cout << "Please enter the customer's height in inches. ";
    cin >> customerHeight;

    cout << "Please enter the customer's weight in pounds. ";
    cin >> customerWeight;

    // Echo Input

    cout << "Report for : " << customerName << endl;

    cout << "Customer Name : " << customerName << endl;

    cout << setw(10) << " " << setw(8) << left << "Age" << setw(3) << " : " << setw(5) << customerAge << endl;

    cout << setw(10) << " " << setw(8) << left << "Height" << setw(3) << " : " << setw(5) << customerHeight << endl;

    cout << setw(10) << " " << setw(8) << left << "Weight" << setw(3) << " : " << setw(5) << customerWeight << endl;

    cout << "End of Report.";
    return 0;

}