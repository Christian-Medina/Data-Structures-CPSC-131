/*
Christian Medina
This program is meant to draw a diamond of asterisks based on the users input of the height
Prompt user for an integer for height
Draw the top half of the diamond
Draw the bottom half of the diamond
*/
#include <iostream>
using namespace std;
int main()
{
	int height = 0;
	int i = 0;
	cout << "Please enter the height ";//prompt user
	cin >> height;//accpet input for the height of the diamond
	for (i = 0; i < height; i++)//create the top half of the diamond
	{
		for (int k = height; k > i; k--)
		{
			cout << " ";
		}
		for (int j = 0; j < i; j++)
		{
			cout << " *" ;
		}
		cout << endl;
	}
	for (i = height; i > 0; i--)//create the bottom half of the diamond
	{
		for (int k = height; k > i; k--)
		{
			cout << " ";
		}
			for (int j = 0; j < i; j++)
		{
			cout << " *";
		}	
		cout << endl;
	}
	system("pause");
	return 0;
}