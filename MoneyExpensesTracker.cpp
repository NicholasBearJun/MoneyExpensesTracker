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

	file.close();

	/*ofstream file("Record.txt", ios::app);
	file << Date << "," << Amount << "," << Category << "," << Note << endl;
	system("cls");
	cout << "Adding...";*/

	//--------------- Old Record Code ----------------------
	//// lineCount function
	//int lineCount = LineCount();
	//
	//// Convert float type to string type variable
	//ostringstream ss;
	//ss << Amount;
	//string s(ss.str());

	////allocate the array
	//string** record = new string* [lineCount];
	//for (int i = 0; i < lineCount; i++)
	//	record[i] = new string[4];

	//// use the array
	//// Add into text file
	//file.open(filename, ios::app);
	//for (int i = 0; i < lineCount; i++) {

	//	record[i][0] = Date;
	//	record[i][1] = s;
	//	record[i][2] = Category;
	//	record[i][3] = Note;

	//	for (int j = 0; j < 4; j++) {
	//		file << record[i][j];
	//		if (j != 3) {
	//			file << ",";
	//		}
	//		else{
	//			file << "\n";
	//		}
	//	}
	//	/*file.flush();*/
	//	cout << "Adding....... " << endl;
	//}

	////deallocate the array
	//for (int i = 0; i < lineCount; i++)
	//	delete[] record[i];
	//delete[] record;
	//---------------------------------------------------

	// Close Text File
	file.close();
	cout << "Record written into file" << endl;


}

//
//// ---------------------------------------------------------------Entire Edit()
//
//// Function for edit()
//// Make Records
//typedef struct {
//	string recordNum;
//	string date;
//	int amount; 
//	string category;
//	string note;
//}Record;
//
//void printTable(const vector<Record>& records) {
//	vector<Record> Records;
//
//	// Print table header
//	cout << setw(6) << "Record Number"
//		<< setw(8) << "Date"
//		<< setw(8) << "Amount"
//		<< setw(8) << "Category"
//		<< "Note\n";
//
//	// Print each record with index
//	for (size_t i = 0; i < (records.size()); ++i) {
//		const Record& record = records[i];
//		cout << setw(6) << i + 1
//			<< setw(8) << record.date
//			<< setw(8) << record.amount
//			<< setw(8) << record.category
//			<< record.note << "\n";
//	}
//}
//
//
//void Edit() {
//
//	//Initialize
//
//
//	// Open and read file
//	// Loop through all record
//	/*
//	fstream file;
//	string filename = "Record.txt";
//	file.open(filename, ios::in);
//
//	// Count the number of lines in the file
//	int lineCount = 1;
//	string line;
//	while (getline(file, line)) {
//		lineCount++;
//	}
//	*/
//
//	// Display The elements inside the record
//	std::ifstream inputFile("Record.txt");
//
//	if (!inputFile) {
//		std::cerr << "Error opening the file." << std::endl;
//	}
//
//	vector<Record> records;
//	string line;
//
//	while (getline(inputFile, line)) {
//		istringstream iss(line);
//		string token;
//
//		Record record;
//
//		// Read and split the line using ',' as delimiter
//		getline(iss, token, ',');
//		record.date = token;
//
//		std::getline(iss, token, ',');
//		record.amount = std::stoi(token);
//
//		std::getline(iss, token, ',');
//		record.category = token;
//
//		std::getline(iss, token, ',');
//		record.note = token;
//
//		records.push_back(record);
//	}
//
//	// Close the file after reading
//	inputFile.close();
//
//	// Print the transactions in table form with index
//	printTable(records);
//	
//
//	/*ifstream file("Record.txt");
//
//	// Check if file Exist, if not jump back to selection page
//	if (!file.is_open()) {
//		std::cerr << "Failed to create or open the file." << endl;
//	}
//
//	// Loop through all lines using count to seperate the rows
//	int count = 1;
//	int RecordCout = 1;
//	string templine;
//
//	cout << "\nRecord " << RecordCout << " : ";
//	for (string line; getline(file, line);) {
//		
//		templine = file.eof();
//
//		if (count % 4 == 0 && line != templine) {
//			RecordCout++;
//			cout << line << "\n";
//			count++;
//			cout << "Record " << RecordCout << " : ";
//		}
//
//		else {
//			cout << line << " ";
//			count ++;
//		}
//
//	}
//
//	file.close();
//	*/
//
//
//	// Get user response on which record
//	int ResponseNum;
//	int WhichArray;
//
//	cout << "\n==================================================" << endl;
//	cout << "Enter the number of the following line you would like to edit" << endl;
//	cout << "==================================================" << endl;
//	cout << "Which record number : ";
//	cin >> ResponseNum;
//
//
//	cout << "\n==================================================" << endl;
//	cout << "What would you like to change ?";
//	cout << "==================================================" << endl;
//	cout << "1. Date";
//	cout << "2. Amount";
//	cout << "3. Category";
//	cout << "4. Note" << endl;
//	cin >> WhichArray;
//
//
//}
//// ---------------------------------------------------------------Entire Edit()


// Delete() Function

// For single character delimiter
std::vector<std::string> split(const std::string& s, char delim) {
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}


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

		// Loop through all lines using count to seperate the rows
		/*int RecordCout = 1;
		string templine;


		int lineCount = LineCount();*/

		//// Count the number of lines in the file
		//int lineCount = 1;
		//string line;
		//while (getline(file, line)) {
		//	lineCount++;
		//}

		////allocate the array
		//string** record = new string * [lineCount];
		//for (int i = 0; i < lineCount; i++)
		//	record[i] = new string[4];


		//// Use the array
		//int j = 0;
		//for (string line; getline(file, line);) {
		//	templine = file.eof();

		//	string str = line;
		//	vector <string> v = split(str, ',');

		//	for (auto e : v) record[lineCount][j] = e;
		//	j++;
		//}

		////deallocate the array
		//for (int i = 0; i < lineCount; i++)
		//	delete[] record[i];
		//delete[] record;

		//// Close file
		//file.close();
		//cout << "Record written into array......" << endl;

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
			Date = Date.substr(0, 4) +"-"+ Date.substr(5, 2) + "-" + Date.substr(9, 2);
			getline(ss, tempAmount, ',');
			Amount = stoi(tempAmount);
			getline(ss, Category, ',');
			getline(ss, Note);
			// The array itself
			cout << "\n" << Count<< "\t" << Date << "\t\t" << Amount << "\t" << Category << "    " << Note;
			Count++;
		}
		file.close();

		/*for (int i = 0; i < lineCount - 1; i++) {
			cout << "\nRecord " << RecordCout << " : ";
			for (int j = 0; j < 4; j++) {
				cout << record[i][j] << "\t";
			}
			RecordCout++;
		}*/

	}

	 //Get user response on which record

	cout << "\n\nEnter the number of the following Record you would like to Delete : ";
	int ResponseNum;
	cin >> ResponseNum;




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
				cout << "case 2";
				//Edit();
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
