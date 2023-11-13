#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <iomanip>
using namespace std;

int LineCount() {

	//open text file
	fstream file;
	string filename = "Record.txt";
	file.open(filename, ios::in);

	// Count the number of lines in the file
	int lineCount = 1;
	string line;
	while (getline(file, line)) {
		lineCount++;
	}
	file.close();

	return lineCount;
}

void Record() {

	system("CLS");
	
	// Variables for loop
	bool Exit = false;
	char Change_Date;

	time_t now = time(0);

	tm* ltm = localtime(&now);

	// Variables for User input

	string Date, Category, Note, InOrEx;
	float Amount;

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
	
	// Open text file
	fstream file;
	string filename = "Record.txt";
	file.open(filename, ios::in | ios::out | ios::app);

	if (!file.is_open()) {
		//File doesn't exist, createa new file
		file.open(filename, ios::out);
		if (!file.is_open()) {
			std::cerr << "Failed to create or open the file." << endl;
		}
	}

	file << Date << "," << Amount << "," << Category << "," << Note << endl;
	system("cls");
	cout << "Adding...";

	// close file
	file.close();
	cout << "Record written into file" << endl;


}

// Function to split a string based on a delimiter
vector<string> split(const string& str, char delimiter) {
	vector<string> tokens;
	size_t start = 0, end = 0;
	while ((end = str.find(delimiter, start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(str.substr(start));
	return tokens;
}

// Function for edit()
void Edit() {

	fstream file("Record.txt");
	// Show the array
	string Date, Category, Note;
	int Amount;
	int Count = 0;

	string tempAmount;
	string Line;

	// Print out Array
	cout << "\n==================================================" << endl;
	cout << "\t\tList of Records" << endl;
	cout << "==================================================" << endl;
	cout << "No." << "\t" << "Date" << "\t\t" << "Amount" << "\t" << "Category" << "\t" << "Note";

	while (getline(file, Line)) {
		stringstream ss(Line);
		getline(ss, Date, ',');
		Date = Date.substr(0, 4) + "-" + Date.substr(5, 2) + "-" + Date.substr(8, 2);
		getline(ss, tempAmount, ',');
		Amount = stoi(tempAmount);
		getline(ss, Category, ',');
		getline(ss, Note);
		// The array itself
		cout << "\n" << (Count + 1) << "\t" << Date << "\t\t" << Amount << "\t" << Category << "    " << Note;
		Count++;
	}
	file.close();


	// The User input
	string filename = "Record.txt"; // Replace with your file name
	int rowNumber, fieldIndex;
	string newValue;
	char InOrEx;

	cout << "\nEnter the record number to update: ";
	cin >> rowNumber;

	cout << "Enter the field index to update (1: Date, 2: Amount, 3: Category, 4: Note): ";
	cin >> fieldIndex;

	switch (fieldIndex) {
		case 1:
			cout << "\n Enter new date(YYYY-MM-DD) : ";
			cin.ignore(); // Clear the newline character from the buffer
			getline(cin, newValue);
			break;
		case 2:
			cout << "Enter new amount : ";
			cin.ignore();
			getline(cin, newValue);
			break;
		case 3:
			cout << "Change category to Income or Expenses(I/E) : ";
			cin >> InOrEx;
			if(InOrEx == 'I' || InOrEx == 'i') {
				newValue = "Income";
			}
			if (InOrEx == 'E' || InOrEx == 'e') {
				newValue = "Expenses";
			}
			break;
		case 4:
			cout << "Enter new Note: ";
			cin.ignore(); // Clear the newline character from the buffer
			getline(cin, newValue);
			break;
	}

	cout << newValue << endl;

	// THe Process 
	ifstream fileIn(filename);
	ofstream fileOut("temp.txt"); // Temporary file to store modified data

	if (!fileIn || !fileOut) {
		cerr << "Error opening files." << endl;
		return;
	}

	string line;
	int currentRow = 0;
	fieldIndex--;
	while (getline(fileIn, line)) {
		if (currentRow == (rowNumber - 1)) {
			vector<string> fields = split(line, ',');

			// Update the specified field
			if (fieldIndex >= 0 && fieldIndex < fields.size()) {
				fields[fieldIndex] = newValue;
			}
			else {
				cerr << "Invalid field index." << endl;
				return;
			}

			// Reconstruct the modified line
			string updatedLine = fields[0];
			for (size_t i = 1; i < fields.size(); ++i) {
				updatedLine += "," + fields[i];
			}

			fileOut << updatedLine << endl;
		}
		else {
			fileOut << line << endl;
		}

		currentRow++;
	}

	fileIn.close();
	fileOut.close();

	// Replace the original file with the temporary file
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());

	cout << "Field updated successfully." << endl;
}

// Delete() Function

void Delete() {

	//Loop through file to get number of rows
	// Number of rows store into lineCount
	// get which column user want to delete = j
	// use array[lineCount][j] to find the position 

	// Open text file
	fstream file("Record.txt");
	/*string filename = "Record.txt";*/
	/*file.open(filename, ios::in);*/
	if (!file.is_open()) {
		cout << "No Data present";
		file.close();
	}
	else{

		string Date, Category, Note;
		int Amount;
		int Count = 0;

		string tempAmount;
		string Line;

		// Print out Array
		cout << "\n==================================================" << endl;
		cout << "\t\tList of Records" << endl;
		cout << "==================================================" << endl;
		cout << "No."<< "\t" << "Date" << "\t\t" << "Amount" << "\t" << "Category" << "\t" << "Note";
		
		while (getline(file, Line)) {
			stringstream ss(Line);
			getline(ss, Date, ',');
			Date = Date.substr(0, 4) +"-"+ Date.substr(5, 2) + "-" + Date.substr(8, 2);
			getline(ss, tempAmount, ',');
			Amount = stoi(tempAmount);
			getline(ss, Category, ',');
			getline(ss, Note);
			// The array itself
			cout << "\n" << (Count + 1)<< "\t" << Date << "\t\t" << Amount << "\t" << Category << "    " << Note;
			Count++;
		}
		file.close();
	}

	 //Get user response on which record

	cout << "\n\nEnter the number of the following Record you would like to Delete : ";
	int ResponseNum;
	cin >> ResponseNum;

	// Delete a line
	fstream read_file;

	read_file.open("Record.txt");

	if (read_file.fail()) {
		cout << "Error opening file." << endl;
	}

	vector <string> lines;
	string line;

	while (getline(read_file, line))
		lines.push_back(line);

	read_file.close();

	if (ResponseNum > line.size()) {
		cout << "Line" << ResponseNum;
		cout << "not in file" << endl;

		cout << "File has " << lines.size();
		cout << "lines." << endl;

	}

	ofstream write_file;
	write_file.open("Record.txt");

	if (write_file.fail()) {
		cout << "Error opening file" << endl;
	}

	ResponseNum--;
	for (int i = 0; i < lines.size(); i++)
		if (i != ResponseNum)
			write_file << lines[i] << endl;

	write_file.close();
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
				system("CLS");
				continue;
			case '1':
				// Jump to Function Record()
				Record();
				break;
			case '2':
				Edit();
				system("CLS");
				break;
			case '3':
				Delete();
				system("CLS");
				break;
			case '4':
				cout << "Case 4" << endl;
				system("CLS");
				break;
			default:
				cout << "\nInvalid function please enter again: " << endl;
				system("CLS");
				continue;
		}
	}
}
