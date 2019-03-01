/*
Christian Medina
This program is mean to create a square using a desired value
Prompt user for how many values are to be shown
Prompt user for how many rows desired
Prompt user for how many columns desired
Prompt user for which value to be printed
Print square to user
*/
#include <iostream>
using namespace std;
int main3()
{
	int row = 0;
	int col = 0;
	int num = 0;
	int many = 0;
	int counter = 0;
	cout << "How Many: ";//prompt user
	cin >> many;//accept input for how many values are to be shown
	cout << "Rows: ";//prompt user
	cin >> row;//accept input for how many rows desired
	cout << "Columns: ";//prompt user
	cin >> col;//accept input for how many columns desired
	cout << "What numer to print: ";//prompt user
	cin >> num;//accept input for which value is to be printed
	for (int i = 0; i <= row; i++)//controls the amount of rows displayed
	{
		for (int k = 0; k <= col; k++)//controls the amount of columns displayed
		{
			cout << num << " ";//prints desired value 
		}
		cout << endl;
	}
	system("pause");
	return 0;
}