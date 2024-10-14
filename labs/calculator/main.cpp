/**
* Done by:
 * Student Name: Stanislav Buket
 * Student Group: 121
 * Calculator
 */
#include <iostream>
#include <string>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int x) {
    if(top >= MAX_SIZE - 1) {
        std::cout << "Stack Overflow" << std::endl;
        exit(1);
    }
    top++;
    stack[top] = x;
}

int pop() {
    if(top < 0) {
        std::cout << "Stack Underflow" << std::endl;
        exit(1);
    }
    int x = stack[top];
    top--;
    return x;
}

int isEmpty() {
    if(top < 0)
        return 1;
    return 0;
}

int peek() {
    if(top < 0) {
        std::cout << "Stack is Empty" << std::endl;
        exit(1);
    }
    return stack[top];
}

int precedence(char op) {
    //determine operator precedence
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

std::string infixToPostfix(std::string expression) {
    //convert infix expression to postfix
    char opStack[MAX_SIZE];
    int opTop = -1;
    std::string postfix;
    int i = 0;
    while(i < expression.length()) {
        if(expression[i] >= '0' && expression[i] <= '9') {
            //read full number and add to postfix
            std::string number;
            while(i < expression.length() && expression[i] >= '0' && expression[i] <= '9') {
                number += expression[i];
                i++;
            }
            postfix += number + ' ';
        }
        else if(expression[i] == '+' || expression[i] == '-' ||
                expression[i] == '*' || expression[i] == '/') {
            //process operators
            char currentOp = expression[i];
            while(opTop >= 0 && precedence(opStack[opTop]) >= precedence(currentOp)) {
                postfix += opStack[opTop];
                postfix += ' ';
                opTop--;
            }
            opTop++;
            opStack[opTop] = currentOp;
            i++;
        }
        else if(expression[i] == ' ') {
            //skip spaces
            i++;
        }
        else {
            //invalid character
            std::cout << "Invalid character in expression" << std::endl;
            exit(1);
        }
    }
    //pop remaining operators
    while(opTop >= 0) {
        postfix += opStack[opTop];
        postfix += ' ';
        opTop--;
    }
    return postfix;
}

int performOperation(char operation, int operand1, int operand2) {
    //perform arithmetic operation
    if(operation == '+')
        return operand1 + operand2;
    if(operation == '-')
        return operand1 - operand2;
    if(operation == '*')
        return operand1 * operand2;
    if(operation == '/') {
        if(operand2 == 0) {
            std::cout << "Division by zero" << std::endl;
            exit(1);
        }
        return operand1 / operand2;
    }
    std::cout << "Invalid operator" << std::endl;
    exit(1);
}

int evaluatePostfix(std::string expression) {
    //evaluate postfix expression
    int operandStack[MAX_SIZE];
    int operandTop = -1;
    int i = 0;
    while(i < expression.length()) {
        if(expression[i] >= '0' && expression[i] <= '9') {
            //read full number and push onto stack
            std::string number = "";
            while(i < expression.length() && expression[i] >= '0' && expression[i] <= '9') {
                number += expression[i];
                i++;
            }
            operandTop++;
            operandStack[operandTop] = atoi(number.c_str());
        }
        else if(expression[i] == '+' || expression[i] == '-' ||
                expression[i] == '*' || expression[i] == '/') {
            //perform operation with top two operands
            if(operandTop < 1) {
                std::cout << "Invalid postfix expression" << std::endl;
                exit(1);
            }
            int operand2 = operandStack[operandTop];
            operandTop--;
            int operand1 = operandStack[operandTop];
            operandTop--;
            int result = performOperation(expression[i], operand1, operand2);
            operandTop++;
            operandStack[operandTop] = result;
            i++;
        }
        else if(expression[i] == ' ') {
            //skip spaces
            i++;
        }
        else {
            //invalid character
            std::cout << "Invalid character in postfix expression" << std::endl;
            exit(1);
        }
    }
    if(operandTop != 0) {
        std::cout << "Invalid postfix expression" << std::endl;
        exit(1);
    }
    return operandStack[operandTop];
}

int main() {
    // Read infix expression from user
    std::string infixExpression;
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infixExpression);
    //convert infix to postfix
    std::string postfixExpression = infixToPostfix(infixExpression);
    //evaluate postfix expression
    int result = evaluatePostfix(postfixExpression);
    //output the result
    std::cout << "Result: " << result << std::endl;

    /* Example usage:
        Enter an infix expression: 3 + 4 * 2
        Result: 11

        Enter an infix expression: 8 + 6 / 3 - 2
        Result: 8

        Enter an infix expression: 10 * 2 + 6
        Result: 26
    */

    return 0;
}