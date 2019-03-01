// 131 Project 2 try 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;


int main(int argc, char *argv[]) 
{
	string filename;
	if (argc >= 2) 
	{
		filename = argv[1]; // command line arguments are given. The first argument is the filename
	}
	else 
	{
		cout << "Enter name of file to check: ";
		cin >> filename;
	}
	cout << "File to check:" << filename << endl;
	ifstream infile(filename);
	if (!infile) 
	{
		cout << "That file does not exist" << endl;
		return (-1); // end the program
	}
	string line;
	stack<char> brackets;
	bool valid = true;
	int lineNumber = 0;
	int columnNumber = 0;
	char c1;
	bool comment = false;
	while (getline(infile, line))
	{
		int length = line.length();
		lineNumber++;
		columnNumber = 0;
		if (length > 2)//no comments
		{
			char first_char = line.at(0);
			char second_char = line.at(1);
			if (first_char == '\'' && second_char == '\'')
			{
				continue;
			}
		}
		for (int i = 0; i < length; i++)
		{
			char c = line.at(i);
			columnNumber++;
			for (int i = 0; i < length; i++)   // from Proff Panangadan
			{
				if (line.at(i) == '"')
				{
					comment = !comment;
				}
				if (comment)
				{
					line[i] = ' ';
				}
			}
			if (c == '(' || c == '[' || c == '{')//opener
			{
				brackets.push(c);
			}
			else if ((c == ')' || c == ']' || c == '}'))//closer
			{
				if (brackets.empty())
				{
					cout << "Mismatch at line " << lineNumber << " and column " << columnNumber << endl;
					valid = false;
				}
				else
				{
					c1 = (char)brackets.top();
					brackets.pop();
					if (c == ')' && c1 != '(')
					{
						cout << "Mismatch at line " << lineNumber << " and column " << columnNumber << endl;
						valid = false;
					}
					else if (c == ']' && c1 != '[') {
						cout << "Mismatch at line " << lineNumber << " and column " << columnNumber << endl;
						valid = false;
					}
					else if (c == '}' && c1 != '{')
					{
						cout << "Mismatch at line " << lineNumber << " and column " << columnNumber << endl;
						valid = false;
					}
				}
			}
		}
	}
	if (valid)
	{
		cout << "No Parenthesization errors." << endl;
	}
		
	infile.close();
	system("pause");
	return(0);
}