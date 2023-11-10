#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
using namespace std;

void finance();
void login();
void registration();
void forgot();
void Record();

int main()
{
	int c;
	cout << "______________________________________________________________________________\n\n\n";
	cout << "                           WELCOME TO LOGIN PAGE\n\n\n";
	cout << "______________________________________________________________________________\n\n";
	cout << "                           Press 1 | LOGIN\n";
	cout << "                           Press 2 | REGISTER\n";
	cout << "                           Press 3 | Forgot Password\n";
	cout << "                           Press 4 | EXIT\n\n";
	cout << "                           Please Select your choice: ";
	cin >> c;
	cout << "\n";

	switch (c)
	{
	case 1:
		login();
		break;
	case 2:
		registration();
		break;
	case 3:
		forgot();
		break;
	case 4:
		cout << "                           THANK YOU!\n";
		break;
	default:
		system("cls");
		cout << "Please select from the option given above... \n\n";
		main();
	}
}

void finance()
{

	while (true)
	{
		char response;

		// Main Page loop that jumps between functions AFTER login()
		// Allow user to choose their function using numbers

		cout << "\n              Money Expense Tracker               " << endl;
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
			break;
		case '3':
			cout << "Case 3" << endl;
			break;
		case '4':
			cout << "Case 4" << endl;
			break;
		default:
			cout << "Invalid function please enter again: " << endl;
			continue;
		}
	}
}

void login()
{
	int Pass = 0;
	string User_ID, Password, Record_User_ID, Record_Password;
	system("cls");
	cout << "Please enter the username and pasword:  " << endl;
	cout << "USERNAME: ";
	cin >> User_ID;
	cout << "PASSWORD: ";
	cin >> Password;
	cout << endl;

	ifstream input("login.txt");

	while (input >> Record_User_ID >> Record_Password)
	{
		if (Record_User_ID == User_ID && Record_Password == Password)
		{
			Pass = 1;
		}
	}
	input.close();

	if (Pass == 1)
	{
		system("cls");
		cout << "Login Sucessful!\n\n";
		finance();

	}
	else
	{
		system("cls");
		cout << "Login Error! \nPlease check your username and password.\n\n";
		login();
	}
}

void registration()
{
	string R_User_ID, R_Password, Record_User_ID, Record_Password;
	system("cls");
	cout << "Enter the username: ";
	cin >> R_User_ID;
	cout << "Enter the password: ";
	cin >> R_Password;

	ofstream f1("login.txt", ios::app);
	f1 << R_User_ID << " " << R_Password << endl;
	system("cls");
	cout << "Registration is successful! \n";
	main();
}

void forgot()
{
	int option;
	system("cls");
	cout << "You forgot the password?\n";
	cout << "Press 1 | Search your ID by username" << endl;
	cout << "Press 2 | Main Menu" << endl;
	cout << "\nEnter your option: ";
	cin >> option;

	switch (option)
	{
		case 1:
		{
			int Pass = 0;
			string Record_User_ID, Record_Password, F_User_ID;
			cout << "\nEnter the username which you remebered: ";
			cin >> F_User_ID;

			ifstream f2("login.txt");
			while (f2 >> Record_User_ID >> Record_Password);
			{
				if (F_User_ID == Record_User_ID)
				{
					Pass = 1;
				}
			}
			f2.close();
			if (Pass == 1)
			{
				cout << "\n\nYour account is found!";
				cout << "\nYour password: " << Record_Password << endl;
				main();
			}
			else
			{
				cout << "\n\nSorry! Your account is not found!\n";
				forgot();
			}
			break;
		}

		case 2:
		{
			main();
		}

		default:
		{
			cout << "Wrong choice! Please try again!" << endl;
			forgot();
		}
	}
}

void Record()
{

	// Variables for loop
	bool Exit = false;
	char Change_Date;
	string InOrEx;

	time_t now = time(0);

	tm* ltm = localtime(&now);

	// Variables for User input

	string Date;
	float Amount;
	string Category;
	string Account;
	string Note;

	int year = (1900 + ltm->tm_year);
	int month = (1 + ltm->tm_mon);
	int day = (ltm->tm_mday);

	// Get user input for Date, Amount, Category and Note
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
		cout << "\nDate : " << year << "-" << month << "-" << day << " [Correct date?](Y/N) : ";
		cin >> Change_Date;

		// Cheack if users want to change the date. If so 
		if (Change_Date == 'Y' || Change_Date == 'y') {

			string temp = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
			Date = temp;
		}
		else {
			cout << "You have chosen to change the date." << endl;
			cout << "Enter your Date (YYYY-MM-DD): ";
			cin >> Date;
		}

		cout << "\nAmount (RM): " << endl;
		cin >> Amount;

		// Category Income or Expenses
		// Cheack if users want to store as income or expenses
		cout << "\nCategory [Income or Expenses?](I/E): ";
		cin >> InOrEx;

		while (InOrEx != "I" && InOrEx != "i" && InOrEx != "E" && InOrEx != "e")
		{
			cout << "\nInvalid input, Choose between Income or Expenses (I/E): ";
			cin >> InOrEx;
		}

		if (InOrEx != "I" || InOrEx != "i") {
			Category = "Income";
		}
		else {
			Category = "Expenses";
		}

		cout << "\nNote: " << endl;
		cin >> Note;
	}

	// Create or Open a text File
	// Open the text file and loop the total of rows

	// Create Array
	string records[4];
	records[0] = Date;
	records[1] = Amount;
	records[2] = Category;
	records[3] = Note;

	string filename = "Record.txt";

	// Open text file
	fstream file;
	file.open(filename, std::ios::in | std::ios::out);

	if (!file.is_open()) {
		//File doesn't exist, createa new file
		file.open(filename, std::ios::out);
		if (!file.is_open()) {
			std::cerr << "Failed to create or open the file." << endl;
		}
	}

	// Count the number of lines in the file
	int lineCount = (0 / 4);
	string line;
	while (getline(file, line)) {
		lineCount++;
	}
	cout << lineCount << endl;

	// Add into text file
	file.open("Record.txt", ios::app);

	for (int i = 0; i < 4; i++) {
		file << records[i] << '\n';
		file.flush();
	}

	// Close Text File
	file.close();
	system("cls");
	cout << "Record written into file" << endl;
}

