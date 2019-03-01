/*
Christian Medina
This program is meant to print the first 3 powers of a user input value
Prompt user to input an integer
Calculate the power of input
Print for the user
*/
#include <iostream>
#include <cmath>
using namespace std;
int main2()
{
	int input = 0;
	int value = 0;
	cout << "Please enter an integer ";//prompt user
	cin >> input;//accept input to be raised to a power
	for (int i = 0; i <= 3; i++)
	{
		value = pow(input, i);//sets value to desired power
		cout << i << " power: " << value << endl;//prints for the user
	}
	system("pause");
	return 0;
}