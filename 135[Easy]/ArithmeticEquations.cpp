#include <iostream>
#include <cstdlib>
#include <string>
/*
Unix , the famous multitasking and multi-user operating system, has several standards that defines Unix commands, system calls, subroutines, files, etc. Specifically within Version 7 (though this is included in many other Unix standards), there is a game called "arithmetic". To quote the Man Page[4] :
Arithmetic types out simple arithmetic problems, and waits for an answer to be typed in. If the answer
is correct, it types back "Right!", and a new problem. If the answer is wrong, it replies "What?", and
waits for another answer. Every twenty problems, it publishes statistics on correctness and the time
required to answer.
Your goal is to implement this game, with some slight changes, to make this an [Easy]-level challenge. You will only have to use three arithmetic operators (addition, subtraction, multiplication) with four integers. An example equation you are to generate is "2 x 4 + 2 - 5".
*/

/*
TODO:
Add way to evaluate expression w/o Shunting yard and postfix
Add statistics on user input
Add while loop
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
    return 0;
}
