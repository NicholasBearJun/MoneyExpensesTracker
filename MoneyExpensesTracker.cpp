#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <stdio.h>
using namespace std;


void Record() {

	
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
		else{
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

		if (InOrEx == "I" || InOrEx == "i") {
			Category = "Income";
		}
		else{
			Category = "Expenses";
		}

		cin.ignore(256, '\n');
		cout << "\nNote: " << endl;
		getline(cin, Note);
	}

	// Create or Open a text File
	// Open the text file and loop the total of rows
	
	// Convert float type to string type variable
	ostringstream ss;
	ss << Amount;
	string s(ss.str());

	// Create Array
	string records[4];
	records[0] = Date;
	records[1] = s;
	records[2] = Category;
	records[3] = Note;

	string filename = "Record.txt";

	// Open text file
	fstream file;
	file.open(filename, ios::in | ios::out | ios::app);

	if (!file.is_open()) {
		//File doesn't exist, createa new file
		file.open(filename, ios::out);
		if (!file.is_open()) {
			std::cerr << "Failed to create or open the file." << endl;
		}
	}
	file.close();

	// Count the number of lines in the file
	int lineCount = (0 / 4);
	string line;
	while (getline(file, line)) {
		lineCount++;
	}
	cout << lineCount << endl;


	// Add into text file
	file.open(filename, ios::app);
	for (int i = 0; i < 4; i++) {
		file << records[i] << '\n';
		file.flush();
		cout << "Adding....... " << endl;
	}

	// Close Text File
	file.close();
	cout << "Record written into file" << endl;


}

void Edit() {

	// Open and read file
	// Loop through all record
	// Set an "Abstarct ID" using division by 4 to get i
	// List out the 2D array[i][j] following [Date, Amount, Category, Note]

	ifstream file("Record.txt");

	// Check if file Exist, if not jump back to selection page
	if (!file.is_open()) {
		std::cerr << "Failed to create or open the file." << endl;
	}

	int count = 1;
	for (string line; getline(file, line);) {
		
		if (count % 4 == 0) {
			cout << line << "\n";
			count ++;
		}
		else {
			cout << line << " ";
			count ++;
		}
	}

	file.close();

}

int main()
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
			case '0':
				cout << "\nWhy is this happening???" << endl;
				continue;
			case '1':
				// Jump to Function Record()
				Record();
				break;
			case '2':
				Edit();
				break;
			case '3':
				cout << "Case 3" << endl;
				break;
			case '4':
				cout << "Case 4" << endl;
				break;
			default:
				cout << "\nInvalid function please enter again: " << endl;
				continue;
		}
	}
}
