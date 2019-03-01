// leprechauns.cpp : Defines the entry point for the console application.
// @author christian.medina@csu.fullerton.edu  Christian Medina

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <map>

using namespace std;

class RandomNumberGenerator {
public:
	RandomNumberGenerator(int x) :generator(x) {};
	// return a double between -1 and 1
	double randomBetween1and2() {
		return (2.0*generator()) / generator.max() - 1.0;
	}
private:
	minstd_rand0 generator;
};

int N;
// Use a constant random number seed so behavior is consistent from run to run.
int RANDOM_SEED;

int main()
{
	cout << fixed;
	cout << "Enter seed for random number generator: ";
	cin >> RANDOM_SEED;
	RandomNumberGenerator rng(RANDOM_SEED);

	cout << "Enter number of leprechauns: ";
	cin >> N;

	long playtime;
	cout << "Enter game play time (seconds): ";
	cin >> playtime;
	playtime = playtime * 1000; // convert to milliseconds
	double Score = 0;
	int nTrapped = 0;
	double x;//location
	int lGoldInitial = 1000 * 1000;
	double lGold;//currect gold
	int GoldHelper = 0;//follows leprechauns gold amount
					   //
					   // CODE FOR INITIALIZING DATA STRUCTURES GOES HERE
					   //
	map<int, double> MyMap;
	for (int i = 1; i <= N; i++)//setting leprechauns
	{
		GoldHelper++;
		lGold = lGoldInitial;
		MyMap.insert(pair<int, double>(GoldHelper, lGold));
		x = i * 1000;
		MyMap.insert(pair<int, double>(i, x));
	}

	int t = 0; // keep track of number of iterations
	auto start_time0 = chrono::high_resolution_clock::now();
	auto timeSinceStartMS = 0;
	do {
		for (int i = 1; i <= N; i++)
		{
			GoldHelper++;
			double r = rng.randomBetween1and2();
			x = x + r*lGold;//jump
			MyMap.insert(pair<int, double>(i, x));
			if (x>=-1000 && x<=1000)//pit catcher
			{
				Score = Score + lGold;
				N--;
				nTrapped++;
				MyMap.erase(i);
				cout << "t=" << t << ": Caught a Leprechaun!! Score = " << setprecision(2)<< Score << endl;
			}
		}


		//
		// CODE FOR A SINGLE ITERATION GOES HERE
		//

		//// You can use the random number generator like so:
		//	double r = rng.randomBetween1and2();
		//  x = x + r*gold;


		t++;
		// code to measure run time
		auto end_time = std::chrono::high_resolution_clock::now();
		auto timeSinceStart = end_time - start_time0;
		timeSinceStartMS = chrono::duration_cast<chrono::milliseconds>(timeSinceStart).count();
	} while (timeSinceStartMS < playtime);

	cout << "Number of iterations = " << t << endl;
	cout << "Number of trapped leprechauns = " << nTrapped << endl;
	cout << "Score = " << (long)Score << endl;
	return 0;
}