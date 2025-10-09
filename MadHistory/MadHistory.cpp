// MadHistory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int askNumber(int high, int low = 2);

//bool askBoolean()
//{
//
//}
//
//string askText()
//{
//	
//}



void tellhistory()
{
	
}

int main()
{
	int number = askNumber(5);
	cout << "You entered number: " << number << endl;

	number = askNumber(10, 5);
}

int askNumber(int high, int low)
{
	int num;

	do {
		cout << "Please enter a number" << " (" << low <<" - " << high << "): ";
		cin >> num;
	} while (num > high || num < low);

	return num;
}