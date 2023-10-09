//Author csk2q
#include <iostream>
#include <string>

#include "Single_Linked_List.h"

using namespace std;


//--Helper methods--//

///Get int input after posting message to cout.
int getInputInt(string msg)
{
	while (true)
	{
		try
		{
			cout << msg;
			string input;
			cin >> input;
			return stoi(input);
		}
		catch (exception)
		{
			cout << "Unable to parse input as an integer.\n";
		}
	}
}

///Get string input after posting message to cout.
string getInput(string msg)
{
	cout << msg;
	string input;
	cin >> input;
	return input;
}


//--main--//

int main()
{
	cout << "THIS IS QUESTION 1!\nTo run question 2 open the solution file in the folder \"Question2\"\n\n";


	Single_Linked_List<string> list;
	cout << "This program can run the methods of Single Linked List.\n"
		<< "This example uses the item type of string for simplicity though the underlying class is a template and can use any provided type.\n";


	//Prefill the list with data
	if (getInput("Would you like to prefill the list with debug data? (y/n): ") == "y")
	{
		list.push_back("first");
		list.push_back("second");
		list.push_back("third");
		list.push_back("fourth");
		list.push_back("fifth");
		list.push_back("sixth");
		cout << "List was filled with debug data.\n";
		list.display();
	}
	else
		cout << "Debug data was not filled into the list.\n";


	//Run commands until user chooses to quit
	bool done = false;
	while (!done)
	{
		//List commands to the user
		cout << "\nWhat method would you like to run?\n"
			<< "1.  push_front.\n"
			<< "2.  push_back.\n"
			<< "3.  pop_front.\n"
			<< "4.  pop_back.\n"
			<< "5.  front.\n"
			<< "6.  back.\n"
			<< "7.  empty.\n"
			<< "8.  insert.\n"
			<< "9.  remove.\n"
			<< "10. find.\n"
			<< "11. display list.\n"
			<< "0.  Quit.\n";


		//Get user input
		int choice = getInputInt("Enter a number 0-11: ");
		cout << "\n";

		//Run command based on user choice
		switch (choice)
		{
		case (1): //push_front
		{
			string input = getInput("Enter a value: ");
			list.push_front(input);
			cout << "Method \"push_front\" executed.\n";
			list.display();
		}
			break;

		case (2): //push_back
		{
			string input = getInput("Enter a value: ");
			list.push_back(input);
			cout << "Method \"push_back\" executed.\n";
			list.display();
		}
			break;

		case (3): //pop_front
			list.pop_front();
			cout << "Method \"pop_front\" executed.\n";
			list.display();
			break;

		case (4): //pop_back
			list.pop_back();
			cout << "Method \"pop_back\" executed.\n";
			list.display();
			break;

		case (5): //front
			if (list.empty())
				cout << "The list is empty and has no front most item.\n";
			else
				cout << "The front most item is: " << list.front() << "\n";
			break;

		case (6): //back
			if (list.empty())
				cout << "The list is empty and has no back most item.\n";
			else
				cout << "The back most item is: " << list.back() << "\n";
			break;

		case (7): //empty
			if (list.empty())
				cout << "The list is empty.\n";
			else
				cout << "The list is NOT empty.\n";
			break;

		case (8): //insert
		{
			string item = getInput("Value to insert: ");
			int index = getInputInt("Index to insert at: ");
			while (index < 0)
				index = getInputInt("Please enter an non-negative number.\nIndex to insert at: ");
			list.insert(index, item);
			cout << "Method \"insert\" executed.\n";
			list.display();
		}
		break;

		case (9): //remove
		{
			int index = getInputInt("Index of item to remove remove: ");
			while (index < 0)
				index = getInputInt("Please enter an non-negative number.\nIndex of item to remove remove: ");
			cout << "Method \"remove\" was executed ";
			if (list.remove(index))
				cout << "successfully.\n";
			else
				cout << "unsuccessfully.\nProvided index is out of range.\n";
			list.display();
		}
			break;

		case (10): //find
		{
			string input = getInput("Value to look for: ");
			cout << "Item \"" << input << "\" was found at index " << list.find(input) << ".\n"
				<< "Note that if the item was not found the size of the list is returned.\n";
		}
			break;

		case (11): //display
			cout << "List:\n";
			list.display();
			break;

		default: // Input invalid.
			cout << "Input was invalid.\n";
			break;
		case (0): //quit
			cout << "Shutting down...\n";
			done = true;
			break;
		}
	}
	return 0;
}


