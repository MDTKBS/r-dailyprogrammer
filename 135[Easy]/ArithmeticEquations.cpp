#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <vector>
#include <cctype>

//Test if character is an operator
bool isOp(std::string token)
{
    return token == "+" || token == "-" || token == "*";
}

//get precedence of an operator
int precedence(std::string token)
{
    if (token == "*")
    {
        return 2;
    }
    if (token == "+")
    {
        return 1;
    }
    if (token == "-")
    {
        return 1;
    }
}

//compare precedence of operators
int comparePrecedence(std::string token1, std::string token2)
{
    return precedence(token1) - precedence(token2);
}

//Convert infix expression to postfix 
//Very simplified shunting yard algorithm
std::vector<std::string> infixToPostfix(std::vector<std::string> expression)
{
    //holds output of shunting yard algorithm
    std::vector<std::string> output;
    //stack to implement shunting yard algorithm
    std::stack<std::string> stk;
    //loop through the expression
    for (auto itr = expression.begin(); itr != expression.end(); ++itr)
    {
        //if operator
        if ( isOp(*itr) )
        {
            //non-empty stack
            while( !stk.empty() )
            {
                //if operator in expression has less or equal precedence than
                //operator on top of stack, pop operators on stack and add
                //to output until operator of expression has higher //precedence then push operator from expression //on stack
                if( comparePrecedence( *itr, stk.top() ) <= 0 )
                {
                    output.push_back( stk.top() );
                    stk.pop();
                    continue;
                }
                break;
            }
            stk.push(*itr);
        }
        //if number, add to output
        else output.push_back(*itr);
    }
    //after going through expression, pop any remaining operators
    //off stack and add to output
    while(!stk.empty())
    {
        output.push_back( stk.top() );
        stk.pop();
    }
    return output;
}

//evaluate postfix expression
//simple postfix algorithm
int eval(std::vector<std::string> expression) 
{
    //stack to implement postfix algorithm
    std::stack<std::string> stk;
    //loop through expression
    for (auto itr = expression.begin(); itr != expression.end(); ++itr)
    {
        //if number, push on stack
        if( !isOp(*itr) )
        {
            stk.push(*itr);
        }
        //if operator, pop 2 numbers off stack and evaluate
        //using the operator
        else
        {
            int b = atoi(stk.top().c_str());
            stk.pop();
            int a = atoi(stk.top().c_str());
            stk.pop();
            int result;
            if( *itr == "+")
            {
                result = a + b;
            }
            if( *itr == "-")
            {
                result = a - b;
            }
            if( *itr == "*")
            {
                result = a * b;
            }
            //push result back on stack
            stk.push( std::to_string(result) );
        }
    }
    //after going through expression, there should only be 1 number on stack
    int result = atoi( stk.top().c_str() );
    return result;

}
//generate random numbers for expression 
int generateNumbers(int low, int high)
{
    int range = high - low;
    return rand() % range + low;
}
//generate random operators for expression
char generateOperators(char ops[])
{
    return ops[rand() % 3];
}


int main()
{
        //Add code for while loop
        //While user input != quit, continue with loop
        //If right answer, generate new expression
        //If wrong answer, print out same expresion
        int low, high;
        //Ask user for range of integers
        std::cout << "Enter two integers representing the inclusive range: "      << std::endl; 
        std::cin >> low >> high;
        //Checking if range is valid
        if(low > high)
        {
            std::cout << "Invalid range." << std::endl;
            exit(-1);
        }
        char operators[3] = {'+','-','*'};
        //Generate random numbers and operators for expression
        std::string exprNumbers[4];
        for (int i = 0; i < 4; ++i)
        {
           exprNumbers[i] = std::to_string( generateNumbers(low,high) );
        }
        std::string exprOps[3];
        for (int j = 0; j < 3; ++j)
        {
           exprOps[j] = generateOperators(operators);
        }
        //a vector to hold the expression
        std::vector<std::string> expression; 
        //adding the random operators and numbers to the vector
        for (int k = 0; k < 4; ++k)
        {
            expression.push_back(exprNumbers[k]);
            if (k < 3)
            {
                expression.push_back(exprOps[k]);
            }
        }
        //Print expression to screen
        for (auto itr = expression.begin(); itr != expression.end(); ++itr)
        {
            std::cout << *itr << " ";
        }
        //formatting
        std::cout << std::endl;
        //ask user for input
        std::cout << "Enter your answer: " << std::endl;
        std::string userAnswerStr;
        std::cin >> userAnswerStr;
        if(userAnswerStr == "quit")
        {
            return 0;
        }
        int userAnswer = atoi(userAnswerStr.c_str());
        std::vector<std::string> postfixExpr = infixToPostfix(expression);
        //Compute expression from postfix
        int answer = eval(postfixExpr);
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