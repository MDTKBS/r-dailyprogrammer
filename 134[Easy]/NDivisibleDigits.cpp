/*
Write a program that takes two integers, N and M, and find the largest integer composed of N-digits that is evenly divisible by M. N will always be 1 or greater, with M being 2 or greater. Note that some combinations of N and M will not have a solution.
Example: if you are given an N of 3 and M of 2, the largest integer with 3-digits is 999, but the largest 3-digit number that is evenly divisible by 2 is 998, since 998 Modulo 2 is 0. Another example is where N is 2 and M is 101. Since the largest 2-digit 
integer is 99, and no integers between 1 and 99 are divisible by 101, there is no solution.
*/
#include <iostream>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
	//checking for correct number of arguments
	if (argc != 3)
	{
		std::cout << "Incorrect number of parameters." << std::endl;
		return -1;
	}

	//number of digits n
	unsigned int n = atoi(argv[1]);
	//divisor m
	unsigned int m = atoi(argv[2]);

	//checking for valid input
	if (n < 1 || n > 9 || m < 1 || m > 999999999)
	{
		std::cout << "Parameters are outside of valid range." << std::endl;
		return -1;
	}

	//largest n-digit number is 10^n - 1
	unsigned int upperLimit = pow(10,n) - 1;

	//Checking to make sure a solution exists
	if(m > upperLimit)
	{
		std::cout << "There is no solution." << std::endl;
		return -1;
	}

	unsigned int result = 0;

	//finding largest n-digit integer that is divisible by m
	std::cout << upperLimit - (upperLimit % m);
	return 0;
}