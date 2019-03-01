// experimental.cpp
//
// Group member names: TODO: Christian Medina

// Project 3, CPSC 131, Spring 2016, CSU Fullerton
//
// Template code written in 2016 by Kevin Wortman (kwortman@fullerton.edu)
//
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any
// warranty. You should have received a copy of the CC0 Public Domain
// Dedication along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
//

#include "stdafx.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <forward_list>
#include <list>
#include <vector>

using namespace std;

// Use a constant random number seed so behavior is consistent from run to run.
const int RANDOM_SEED = 0xC0DE;

// int value that is different from all randomly-generated ints.
const int DISTINCT_INT = -1; // Random ints are always non-negative.

							 // std::forward_list does not have a push back function, so we have to write
							 // our own.
void forward_list_push_back(forward_list<int>& the_list, int n, int element) {
	forward_list<int>::iterator ptr = the_list.begin();
	for (int i = 0; i < (n - 1); ++i)
		++ptr;
	the_list.insert_after(ptr, element);
}

int main()
{
	// Seed the random number generator.
	srand(RANDOM_SEED);

	// Query user for structure size n.
	int millions;
	for (bool done = false; !done;) {
		cout << "Enter a positive integer n, in units of millions: ";
		cin >> millions;
		if (cin && (millions > 0)) {
			done = true;
		}
		else {
			cout << "Invalid entry, try again." << endl;
		}
	}
	const int n = millions * 1000000;

	// Build a master forward_list, list, and vector, each containing the
	// same collection of elements, that will be reused for each trial.
	// These data structures are declared const to make sure we don't modify
	// them by mistake.
	cout << "Creating data structures with n=" << millions << " million...";
	vector<int> randoms;
	for (int i = 0; i < n; ++i) {
		randoms.push_back(rand());
	}
	const forward_list<int> master_forward_list(randoms.begin(), randoms.end());
	const list<int> master_list(randoms.begin(), randoms.end());
	const vector<int> master_vector(randoms.begin(), randoms.end());
	randoms.clear();
	cout << "done" << endl;

	// Each of the following trials is in its own anonymous scope, between the
	// { } braces. This makes it so that each trial's local temp variable does
	// not interfere with any of the other trials' code.

	{
		cout << "Add to front - singly linked list" << endl;
		forward_list<int> temp = master_forward_list;
		temp.push_front(DISTINCT_INT);
	}
	{
		cout << "Add to front - doubly linked list" << endl;
		list<int> temp = master_list;
		temp.push_front(DISTINCT_INT);
	}
	{
		cout << "Add to front - vector" << endl;
		vector<int> temp = master_vector;
		temp.insert(temp.begin(), DISTINCT_INT);
	}
	{
		cout << "Add to back - singly linked list" << endl;
		forward_list<int> temp = master_forward_list;
		forward_list_push_back(temp, n, DISTINCT_INT);
	}
	{
		cout << "Add to back - doubly linked list" << endl;
		list<int> temp = master_list;
		temp.push_back(DISTINCT_INT);
	}
	{
		cout << "Add to back - vector" << endl;
		vector<int> temp = master_vector;
		temp.push_back(DISTINCT_INT);
	}
	{
		cout << "Clear - singly linked list" << endl;
		forward_list<int> temp = master_forward_list;
		temp.clear();
	}
	{
		cout << "Clear - doubly linked list" << endl;
		list<int> temp = master_list;
		temp.clear();
	}
	{
		cout << "Clear - vector" << endl;
		vector<int> temp = master_vector;
		temp.clear();
	}
	return 0;
}

