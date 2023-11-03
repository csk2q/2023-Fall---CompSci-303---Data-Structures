#include <iostream>
#include <stack>
#include <exception>
#include <string>
#include <vector>


#include "Question1.h"

using namespace std;

bool Question1::isBalanced(std::string text)
{
	//Use a stack, reference slides/textbook
	stack<char> s;

	//Ch5 slide 38
	for (int i = 0; i < text.length(); ++i)
	{
		//is open bracket
		if (openBrackets.find(text[i]) != string::npos)
			s.push(text[i]);
		//is close bracket
		else if (closeBrackets.find(text[i]) != string::npos)
		{
			if (s.empty())
				return false;

			char top = s.top();
			s.pop();
			int topIndex = getIndex(openBrackets, top);
			int closeIndex = getIndex(closeBrackets, text[i]);

			if (topIndex == -1 || closeIndex == -1 || topIndex != closeIndex)
				return false;
		}
	}

	return s.empty();
}

string Question1::convertInfixToPostfix(string text)
{
	//Use a stack, reference slides/textbook
	//TODO see Ch5 slide 80

	//Set begining states
	postfix = "";
	while (!opStack.empty())
		opStack.pop();

	//For all input characters
	for (char token : text)
	{
		//If Operand
		if (isalnum(token))
		{
			postfix += token;
			postfix += " "; //May need removed?
		}
		//If operator
		else if (precedence(token) > -1)
		{//Process
			processOperator(token);
		}
		else if (isspace(token))
		{
			//Ignore whitespace
		}
		else //Unexpected characters
		{
			throw invalid_argument(string("Unexpected character \"") + token + string("\" encountered!"));
		}

	}

	//Empty the stack onto postfix
	while (!opStack.empty())
	{
		postfix += opStack.top();
		postfix += " ";
		opStack.pop();
	}

	return postfix;
}

void Question1::processOperator(char token)
{
	//If the stack is empty or an open bracket
	if (opStack.empty() || isOpenBracket(token))
	{
		//Pushing a closed bracket onto an empty stack is incorrect
		if (isCloseBracket(token))
			throw invalid_argument("Unmatched close parenthesis found!");

		//Push onto the stack
		opStack.push(token);
	}
	else //The stack is not empty and token is NOT an opening bracket
	{
		//If the current token has a higher precedence than the token on the stack
		if (precedence(token) > precedence(opStack.top()))
		{
			//Push current token onto the stack
			opStack.push(token);
		}
		else //Process the operators in the stack
		{
			//Pop all operators with equal or higher precedence than the current token
			//Stop when the stack is empty or a open bracket is found
			while (!opStack.empty() && !isOpenBracket(opStack.top())
				&& precedence(token) <= precedence(opStack.top()))
			{
				//Add top of stack to postfix and pop
				postfix += opStack.top();
				postfix += " ";
				opStack.pop();
			}

			//If the current toke is a closing bracket
			if (isCloseBracket(token))
			{
				//Try to pop a matching opening bracket off the stack
				if (!opStack.empty() && getIndex(openBrackets, opStack.top()) == getIndex(closeBrackets, token))
					opStack.pop();
				else
					throw invalid_argument("Unmatched close parenthesis found!");
			}
			else //Push the token onto the stack
			{
				opStack.push(token);
			}
		}
	}
}

int Question1::precedence(char token)
{
	//},),],{,(,[,+,-,*,/,%
	//0,0,0,1,1,1,2,2,3,3,4

	vector<char> tokens = { '}', ')', ']', '{', '(', '[', '+', '-', '*', '/', '%' };
	const int value[] = { 0,0,0,1,1,1,2,2,3,3,4 };

	//Find matching token and return precedence
	for (int i = 0; i < tokens.size(); i++)
	{
		if (token == tokens[i])
			return value[i];
	}

	return -1;
}

bool Question1::isOpenBracket(char token)
{
	return getIndex(openBrackets, token) != -1;
}

bool Question1::isCloseBracket(char token)
{
	return getIndex(closeBrackets, token) != -1;
}

bool Question1::isOperator(char token)
{
	return getIndex(opList, token) != -1;
}

int Question1::getIndex(string text, char character)
{
	for (int i = 0; i < text.length(); ++i)
		if (text[i] == character)
			return i;

	return -1;
}
