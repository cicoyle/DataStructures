//
// Created by Cassandra Coyle on 4/4/2018.
// (used/altered Greg's provided code)
//

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <exception>
#include "PostFixTreeBuilder.h"
//added this in--used string buffer
using std::stringstream;
using std::cout;
using std::endl;

//same
//Implementation of the constructor from the NumericElementNode class
inline NumericElementNode::NumericElementNode(double val) :
        number(val)
{
}

//same
//Implementation of the "value" method from the NumericElementNode class
inline double NumericElementNode::value()
{
 return number;
}


//same
//Implementation of the constructor form the BinaryOperation Node class
inline BinaryOperationNode::BinaryOperationNode(char op, ExpressionElementNode *l, ExpressionElementNode *r) :
        binary_op(op), left(l), right(r)
{
}

//same
double BinaryOperationNode::value()
{
    // To get the value, compute the value of the left and
    // right operands, and combine them with the operator.
    double leftVal = left->value();

    double rightVal = right->value();

    double result;

    switch (binary_op)
    {

        case '+':
            result = leftVal + rightVal;
            break;

        case '-':
            result = leftVal - rightVal;
            break;

        case '*':
            result = leftVal * rightVal;
            break;

        case '/':
            result = leftVal / rightVal;
            break;
    }

    return result;
}

//same
int BinaryExpressionBuilder::precedence(char op)
{
    enum
    {
        lowest, mid, highest
    };

    switch (op)
    {

        case '+':
        case '-':
            return mid;

        case '/':
        case '*':
            return highest;

        default:
            return lowest;
    }
}

//same except calls converttoInfix function
// Input: +, -, /, or *
// creates BinaryOperationNode's from all preceding
// *********************  PARSE ***************************
//

BinaryOperationNode *BinaryExpressionBuilder::parse(std::string& str)
throw (NotWellFormed)
{
    //call function to convert the string to infix!
    convertToInfix(str);
    std::istringstream istr(str);
    char token;

    while (istr >> token)
    {

        switch (token)
        {

            case '+':
            case '-':
            case '*':
            case '/':
                processOperator(token);
                break;

            case ')':
                processRightParenthesis();
                break;

            case '(':
                operatorStack.push(token);
                break;

            default:
                // If it is not an operator, it must be a number.
                // Since token is only a char in width, we put it back,
                // and get the complete number as a double.
                istr.putback(token);
                double number;

                istr >> number;

                NumericElementNode *newNode = new NumericElementNode(number);
                operandStack.push(newNode);

                continue;
        } // end switch
    } // end while

    while (!operatorStack.empty())
    {

        doBinary(operatorStack.top());
        operatorStack.pop();
    }

    // Invariant: At this point the operandStack should have only one element
    //     operandStack.size() == 1
    // otherwise, the expression is not well formed.
    if (operandStack.size() != 1)
    {

        throw NotWellFormed();
    }

    ExpressionElementNode *p = operandStack.top();

    return static_cast<BinaryOperationNode *> (p);
}

void BinaryExpressionBuilder:: validateStack(int size) {
    if(2>size) {std:: cout << "ERROR!" << std:: endl; }
        return;

}


//***************************************//
//added to code provided to convert string to infix//
//***************************************//
void BinaryExpressionBuilder::convertToInfix(std::string &postfixline) {

    //vars
    std :: stack <std::string> CassieStack;

    //single char
    char inputChar;
    std:: string error = "ERROR!";
    //use string buffer
    stringstream sstr;
    std :: istringstream istr(postfixline);

    //go through while loop evaluating each char
    //if it is not operator Or Slash (meaning it is a #) we want to push it to CassieStack
    while(istr >> inputChar) {
        if(inputChar != '-' && inputChar != '/' && inputChar != '+' && inputChar != '*') {
            std :: string charToString;
            sstr << inputChar;
            sstr >> charToString;
            //clear the buffer
            sstr.clear();
            //push the value
            CassieStack.push(charToString);

        }/* if the char is a + - * /  */
        else if(inputChar == '-' || inputChar == '+' || inputChar == '*' || inputChar == '/'){
            int size1 = CassieStack.size();
            validateStack(size1);



            std::string charToMath;
            sstr << inputChar;
            sstr >> charToMath;
            //clear the buffer
            sstr.clear();

            //pop from stack
            std::string pop1 = CassieStack.top();
            CassieStack.pop();
            std::string pop2 = CassieStack.top();
            CassieStack.pop();

            int pop1size = pop1.length();
            int pop2size = pop2.length();

            if(1 < pop1size) {pop1 = std::string("(") + pop1 + std::string(")");}
            if(1 < pop2size) {pop2 = std::string("(") + pop2 + std::string(")");}

            std::string entireString = pop2 + charToMath + pop1;

            CassieStack.push(entireString);
        }
    }

    int stackSize = CassieStack.size();
    if(1 == stackSize) {
        std:: cout << "\nPostfix: " << postfixline << std::endl;
        postfixline = CassieStack.top();
        std:: cout << "Infix: " << postfixline << std:: endl << std:: endl;
    } else {
        printf("%s\n", error);
        return;
    }
}

//same
void BinaryExpressionBuilder::processOperator(char op)
{
    // pop operators with higher precedence and create their BinaryOperationNode
    int opPrecedence = precedence(op);

    while ((!operatorStack.empty()) && (opPrecedence <= precedence(
            operatorStack.top())))
    {

        doBinary(operatorStack.top());
        operatorStack.pop();
    }

    // lastly push the operator passed onto the operatorStack
    operatorStack.push(op);
}

//same
void BinaryExpressionBuilder::processRightParenthesis()
{
    while (!operatorStack.empty() && operatorStack.top() != '(')
    {

        doBinary(operatorStack.top());
        operatorStack.pop();
    }

    operatorStack.pop(); // remove '('
}

//same
// Creates a BinaryOperationNode from the top two operands on operandStack
// These top two operands are removed (poped), and the new BinaryOperation
// takes their place on the top of the stack.
void BinaryExpressionBuilder::doBinary(char op)
{
    ExpressionElementNode *right = operandStack.top();

    operandStack.pop();

    ExpressionElementNode *left = operandStack.top();

    operandStack.pop();

    BinaryOperationNode *p = new BinaryOperationNode(operatorStack.top(), left,
                                                     right);

    operandStack.push(p);
}