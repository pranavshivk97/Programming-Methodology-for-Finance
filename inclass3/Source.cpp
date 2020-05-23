/*Name: Pranav Shivkumar
Title: RSC Poll (In Class Assignment 3)*/

#include<iostream>
#include<iomanip>
using namespace std;

class poll
{
public:
	const int stud = 3;
	const int cand = 2;
	int vote;
};

void out(poll* arr)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			sum += arr[i].vote;
		}
	}

	cout << "Election Result:" << endl;
	cout << "Candidate Number" << "\tNumber of Votes" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << i << "\t\t\t";
			cout << arr[i].vote << "\t\t";

		}
	}

	int max = INT_MIN, count = 0;
	int ind[5] = { 0 };

	for (int i = 0; i < 5; i++)
	{

	}

}