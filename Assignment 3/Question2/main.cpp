#include <iostream>
#include <string>

#include "MyQueue.h"

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
	if (cin.peek() == '\n')
		cin.ignore();
	string input;
	getline(cin, input);
	return input;
}


//--main--//

int main()
{
	cout << "THIS IS QUESTION 2!\nTo run question 1 open the solution file in the folder \"Question1\"\n\n";

	MyQueue queue;

	//Run commands until user chooses to quit
	bool done = false;
	while (!done)
	{
		//List commands to the user
		cout << "\nWhat method would you like to run?\n"
			<< "1. enqueue.\n"
			<< "2. dequeue.\n"
			<< "3. top.\n"
			<< "4. empty.\n"
			<< "5. count.\n"
			<< "0. Quit.\n";


		//Get user input
		int choice = getInputInt("Enter a number 0-5: ");
		cout << "\n";

		//Run command based on user choice
		switch (choice)
		{
		case (1): //enqueue
		{
			string input = getInput("Enter a value: ");
			queue.enqueue(input);
			cout << "Method \"enqueue\" executed.\n";
		}
		break;

		case (2): //dequeue
		{
			cout << "The item \"" << queue.dequeue() << "\" was removed from the front of the queue.\n";
		}
		break;

		case (3): //top
			if (queue.isEmpty())
				cout << "Cannot peek at the top item as the queue is empty.\n";
			else
				cout << "The top most item is \"" << queue.top() << "\"\n";
			break;

		case (4): //empty
			if (queue.isEmpty())
				cout << "The queue is empty.\n";
			else
				cout << "The queue is NOT empty.\n";
			break;

		case (5): //count
			cout << "The queue has " << queue.getCount() << " items.\n";
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
