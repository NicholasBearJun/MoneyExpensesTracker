#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;


void Record() {
	// Variables for loop
	char response;
	bool Exit = false;

	time_t now = time(0);

	tm* ltm = localtime(&now);

	// Variables for User input

	float fAmount;
	string sCategory;
	string sAccount;
	string sNote;

	// Get a response on recording Income or Expenses or Exit?
	if (Exit == true) {
		// Display a message notifying the users they exited and jump back to main function selection page
		cout << "\n==================================================" << endl;
		cout << "You have choosen to exit the Record() Function" << endl;
		cout << "==================================================" << endl;
	}

	else
	{
		cout << "\n==================================================" << endl;
		cout << "Enter the following info to be recorded" << endl;
		cout << "==================================================" << endl;
		cout << "\nDate: " << (1900 + ltm->tm_year) << "-" << (1 + ltm->tm_mon) << "-" << (ltm->tm_mday) << endl;
		cout << "Amount: " << endl;
		cout << "Category: " << endl;
		cout << "Account: " << endl;
		cout << "Note: " << endl;

	}
}



int main()
{
	char response;

	// Main Page loop that jumps between functions AFTER login()
	// Allow user to choose their function using numbers

	cout << "              Money Expense Tracker               " << endl;
	cout << "==================================================" << endl;
	cout << "Please choose a function below" << endl;
	cout << "1. Record a new input" << endl;
	cout << "2. Edit a record" << endl;
	cout << "3. Delete a record" << endl;
	cout << "4. Display a report" << endl;
	cout << "==================================================" << endl;
	cout << "Enter your function: ";
	cin >> response;

	//Jump to respective function
	//Save in Header Files???
	switch (response) {
	case '1':
		// Jump to Function Record()
		Record();
		break;
	case '2':
		cout << "Case 2" << endl;
	case '3':
		cout << "Case 3" << endl;
	case '4':
		cout << "Case 4" << endl;
	default:
		cout << "Invalid function please enter again: " << endl;
		break;
	}


	return 0;
}
