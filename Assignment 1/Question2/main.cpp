//Author csk2q

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <cassert>

#include "Question2.h"

using namespace std;

int main()
{
	cout << "THIS IS QUESTION 2!\nTo run question 1 right click on project \"Question 1\" in visual studio and click \"Set as Startup Project\"!\n\n";

	Question2 NumArray = Question2(10);

    //Get path to file to load
	string txtName = ""; //"D:/Test/TestNum.txt";
	bool validFile = false;
	while (!validFile)
	{
		cout << "Please enter the path to the text file to load. Eg: D:/Test/TestNum.txt\n> ";
		cin >> txtName;

		//This requires c++17 to function
		if (!filesystem::exists(txtName))
		{
			validFile = false;
			cout << "That file does not exist. Please enter a valid path.\n";
		}
		else
		{
			validFile = true;
			cout << "Loading File...";
		}
	}

	//! ASK professor for a better way to read an entire text file.
	//Load text from file
	ifstream txtFile;
	txtFile.open(txtName);
	string text = "";
	string line = "";
	while (!txtFile.eof())
	{
		txtFile >> line;
		text += line + "\n";
		line = "";
	}
	txtFile.close();

	//Parse text & load numbers
	string numString;
	for (int i = 0; i < text.length(); i++)
	{
		if (isdigit(text[i])) //If digit, then add to buffer
        {
            numString += text[i];
        }
        else if (text[i] == '-') //If negative sign
        {
            if (numString.length() == 0) //Add to buffer if buffer is empty
                numString += text[i];
            else if(numString.length() > 1) //Parse the existing string then add to buffer
            {
                if (numString != "-") //If the buffer is not just a negative sign
                {
                    //Parse & store the number
                    int number = stoi(numString);
                    NumArray.AddToEnd(number);
                }
                //Clear & add to the buffer
                numString = text[i];
            }
        }
		else if (numString.length() > 0) //If buffer is not empty parse the number
		{
			if (numString != "-") //Do not parse if it is only a negative sign
			{
                //Parse & store the number
				int number = stoi(numString);
				NumArray.AddToEnd(number);
			}
            //Clear the buffer
			numString = "";
		}
	}
	cout << "Done.\n";

    //Run commands until user chooses to quit
	bool done = false;
	while (!done)
	{
        //List commands to the user
		cout << "\nWhat would you like to do?\n"
			<< "1. Check for a number.\n"
			<< "2. Modify a value.\n"
			<< "3. Add a new value.\n"
			<< "4. Remove a value.\n"
			<< "5. Quit.\n"
			<< "Enter a number 1-5: ";

        //Get user input
		string input;
		int choice;
		try
		{
			cin >> input;
			choice = stoi(input);
		}
		catch (std::exception ex)
		{
			cout << "Input invalid.\n";
			continue;
		}

		cout << "\n";

        //Run command based on user choice
		switch (choice)
		{
		case (1): // Check for a number.
		{
            //Get user input
			cout << "What number would you like to check for?\n> ";
			cin >> input;
			int number = stoi(input);
            
            //Check for the number and display result
			int index = NumArray.Contains(number);
			if (index != -1)
				cout << "The given number exists at index " << index << ".\n";
			else
				cout << "The given number does not exist in the array.\n";
		}
		break;

		case (2): // Modify a value. Modified for Question 2
		{
			//Get user input
			int index = -1;
			int newNumber = -1;
			try
			{
				cout << "Index to modify: ";
				cin >> input;
				index = stoi(input);
				cout << "New number: ";
				cin >> input;
				newNumber = stoi(input);
			}
			catch (std::invalid_argument ex)
			{
				cout << "Input could not be parsed as an int. Ending request.\n";
				break;
			}

			//Attempt to modify the number
			int* result = NumArray.Modify(index, newNumber);

            //Display result to user
			if (result == nullptr)
				cout << "Modification failed.\n";
			else
			{
				cout << "Modification succeeded.\n"
					<< "Old value: " << result[0] << "\nNew value: " << result[1] << "\n";
				delete[] result;
			}
		}
		break;

		case (3): // Add a new value. Modified for Question 2
		{
			//Get user input
			int newNumber;
			try
			{
				cout << "New value: ";
				cin >> input;
				newNumber = stoi(input);
			}
			catch (std::exception ex)
			{
				cout << "Input invalid.\n";
				break;
			}

			//Add value to array
			NumArray.AddToEnd(newNumber);
			cout << "Number added to array.\n";
		}
		break;

		case (4): // Remove a value.
		{
            //Get user input
			cout << "Number to remove: ";
			cin >> input;
			int num = stoi(input);
            
            //Attempt to remove the number and display result
			if (NumArray.Remove(num))
				cout << "Number was successfully removed.\n";
			else
				cout << "Failed to remove number. The number was not found in the array.\n";
		}
		break;

		default: // Input invalid. Exit.
			cout << "Input invalid.\n";
		case (5): // Quit.
			cout << "Shutting down...\n";
			done = true;
			break;
		}
	}
}
