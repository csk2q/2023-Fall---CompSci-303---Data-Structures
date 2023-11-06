#ifndef QUESTION1_QUESTION1_H
#define QUESTION1_QUESTION1_H

#include <stack>
#include <string>

using namespace std;

class Question1
{
private:
    const string openBrackets = "{([";
    const string closeBrackets = "})]";
    const string opList = "+-*/%";

    stack<char> opStack;
    string postfix = "";
    
    //Returns the index or -1
    int getIndex(string text, char character);
    //Processes the operator
    void processOperator(char op);
    //Returns the precedence of the passed in token
    int precedence(char token);
    bool isOpenBracket(char token);
    bool isCloseBracket(char token);
    bool isOperator(char token);
    
public:
    //Returns a bool indicating if the braces of the given text is balanced
    bool isBalanced(string text);

    /*
    * Returns the given infix expression as post or throws invalid_argument on failure. 
    * PRECONDITION: Operands must be a single character and be alphanumeric. Eg: Valid:{ 1, b, 9, X} Invalid:{ 21, 2.35, 6X}
    */
    string convertInfixToPostfix(string text);
};


#endif //QUESTION1_QUESTION1_H
