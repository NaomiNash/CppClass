// -----------------------------------------------------------------------
//		 Day in Year - Validates a date in the Gregorian calender,
//		  and if the date is valid it will compute the number of 
//				    days that date is into the year
//		   Naomi Nash - Saint Leo University - 1 March 2021
// -----------------------------------------------------------------------

using namespace std;
#include <iostream>
#include <iomanip>

// -----------------------------------------------------------------------

bool isValidYear(int myYear) {
	return(myYear > 0);
}

bool isValidMonth(int myMonth) {
	return((myMonth >= 1) && (myMonth <= 12));
}

// -----------------------------------------------------------------------

bool isLeapYear(int myYear) {
	bool retVal = false; 
	if ((myYear % 4) == 0) {
		retVal = true;
		if (((myYear % 100) == 0) && ((myYear % 400) != 0)) {
			retVal = false;
		}
	}
	return retVal;
}

// -----------------------------------------------------------------------

int daysInMonth(int myYear, int myMonth) {
	int retVal = 31;
	if ((myMonth == 9) || (myMonth == 4) || (myMonth == 6) || (myMonth == 11)) {
		retVal = 30;
	} else {
		if (myMonth == 2) {
			if (isLeapYear(myYear)) {
				retVal = 29;
			} else {
				retVal = 28;
			}
		}
	}
	return retVal;
}

bool isValidDate(int myYear, int myMonth, int myDay) {
	return ((isValidYear(myYear)) && isValidMonth(myMonth) && (myDay > 0) && (myDay <= daysInMonth(myYear, myMonth)));
}

int main() {
	int tDay, tMonth, tYear;
	cout << "Please enter the year: ";
	cin >> tYear;
	cout << "Please enter the month: ";
	cin >> tMonth;
	cout << "Please enter the day: ";
	cin >> tDay;
	cout << "You entered: (YYYY/MM/DD)" << tYear << "/" << tMonth << "/" << tDay << endl;
	cout << boolalpha << isValidDate(tYear, tMonth, tDay) << endl;
	return 0;
}
