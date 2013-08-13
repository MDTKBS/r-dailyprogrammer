#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>

/*
TODO:
Add way to evaluate expression w/o Shunting yard and postfix
Figure out while loop for user input
Fuck this is harder than I thought it would be
*/


 
int generateNumbers(int low, int high)
{
    int range = high - low;
    return rand() % range + low;
}
 
char generateOperators(char ops[])
{
    return ops[rand() % 3];
}


int eval(int numbers[], char ops[]) 
{
    //figure out how to implement easily
}
//Print out expression
void printExpression(int numbers[], char ops[])
{        
    for (int i = 0; i < 3; ++i)
    {
         std::cout << numbers[i] << " " << ops[i] << " ";
    }
    std::cout << numbers[3] << std::endl;
}
int main()
{
    //Add code for while loop
    //While user input != quit, continue with loop
    //If right answer, generate new expression
    //If wrong answer, print out same expresion
    int low, high;
    //Ask user for range of integers
    std::cout << "Enter two integers representing the inclusive range: " << std::endl; 
    std::cin >> low >> high;
    //Checking if range is valid
    if(low > high)
    {
        std::cout << "Invalid range." << std::endl;
        exit(-1);
    }
    char operators[3] = {'+','-','*'};
    //Generate numbers and operators for expression
    int exprNumbers[4];
    for (int i = 0; i < 4; ++i)
    {
       exprNumbers[i] = generateNumbers(low,high);
    }
    char exprOps[3];
    for (int j = 0; j < 3; ++j)
    {
       exprOps[j] = generateOperators(operators);
    }
    printExpression(exprNumbers, exprOps);
    //Ask user for answer
    std::cout << "Enter your answer: " << std::endl;
    std::string userAnswerStr;
    std::cin >> userAnswerStr;
    if(userAnswerStr == "quit")
    {
        return 0;
    }
    int userAnswer = atoi(userAnswerStr.c_str());
    //Compute expression
    int answer = eval(exprNumbers, exprOps);
    //Check user answer against computed answer
    if(userAnswer == answer)
    {
        std::cout << "Correct!" << std::endl;
    }
    else
    {
        std::cout << "Try Again!" << std::endl;
    }   
    }
    
    return 0;
}