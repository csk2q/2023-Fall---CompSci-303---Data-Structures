#include <iostream>

#include "Question1.h"

using namespace std;

int counter = 0;

///Get string input after posting message to cout.
string getInput(const string& msg)
{
    cout << msg;
    if (cin.peek() == '\n')
        cin.ignore();
    string input;
    getline(cin, input);
    return input;
}

int main()
{
    cout << "THIS IS QUESTION 1!\nTo run question 2 open the solution file in the folder \"Question2\"\n\n";
    
    std::cout << "Greetings user! (Close the window to exit.)" << std::endl;
    
    //Continusuly parse untill program exits
    while(true)
    {
        try
        {
            //Get infix expression from user
            string infix = "a+b*(c/d-e)/(f+g*h)-i";
            infix = getInput("\nInfix expression to convert to postfix: ");

            //Check if braces are balanced and report if they are not balanced
            if (!Question1().isBalanced(infix))
                cout << "Braces are not balanced. Cannot convert to postfix.";
            else
                //Convert infix expression to postfix and return to user.
                cout << "Postfix: " << Question1().convertInfixToPostfix(infix) << "\n";;
        }
        catch (const std::exception& e)
        {   //Report any errors and continue.
            cout << "\nFailed to convert!\n" << e.what() << "\n\n";
        }
    }
    
    return 0;
}
