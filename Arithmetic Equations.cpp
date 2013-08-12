#include <iostream>
#include <cstdlib>

/*
TODO:
1. Change initialization of expression into a function.
2. Add loop for program to continue until user enters "quit".
3. Add loop for program to generate new expression if user answers correctly.
4. Add loop to print out same expression if user is incorrect.
*/


 
int generateNumbers(int low, int high)
{
    int range = high - low;
    return rand() % range + low;
}
 
char generateOperators()
{
    char operators[3] = {'+','-','*'};
    return operators[rand() % 3];
}

//Really lazy expression evaluator
int eval(int numbers[4], char ops[3]) 
{
    for (int i = 0; i < 3; ++i)
    {
        //multiplication
        if(ops[i] == '*')
        {
            int result = numbers[i]*numbers[i+1];
            numbers[i+1] = result;
        }
        //addition
        if(ops[i] == '+')
        {
            int result = numbers[i]+numbers[i+1];
            numbers[i+1] = result;
        }
        //subtraction
        if(ops[i] == '-')
        {
            int result = numbers[i]-numbers[i+1];
            numbers[i+1] = result;
        }
    }
    
    return numbers[3];
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
    //Generate numbers and operators for expression
    int exprNumbers[4];
    for (int i = 0; i < 4; ++i)
    {
       exprNumbers[i] = generateNumbers(low,high);
    }
    char exprOps[3];
    for (int j = 0; j < 3; ++j)
    {
       exprOps[j] = generateOperators();
    }
    //Print out expression
    for (int k = 0; k < 3; ++k)
    {
        std::cout << exprNumbers[k] << " " << exprOps[k] << " ";
    }
    std::cout << exprNumbers[3] << std::endl;
    //Ask user for answer
    std::cout << "Enter your answer: " << std::endl;
    int userAnswer;
    std::cin >> userAnswer;
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
    
    return 0;
}
