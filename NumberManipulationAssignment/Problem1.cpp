/*
Christian Medina
This program is meant to sum up all the odd values up to a certain input value
Prompt user for an integer
Check if the value is odd
	if value is odd then the value is added to the total sum
	if value is even then reset loop
*/
#include <iostream>
using namespace std;
int main1()
{
	int sum = 0;
	int input = 0;
	int counter = 0;
	cout << "Please enter an integer ";//prompt user
	cin >> input;//accept input for the sum's limit
	for (counter; counter <= input; counter++)
	{
		if (counter % 2 == 1)//checks if the value is odd
		{
			sum = sum + counter;//if true then addes to total sum
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}