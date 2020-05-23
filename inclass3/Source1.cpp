#include<iostream>
using namespace std;

const int stud = 20;
const int cand = 5;

int main()
{
	int i, vote, count = 0;
	int counter[cand] = { 0 };
	int candidate_num[cand] = { 1, 2, 3, 4, 5};
	cout << "0 - Candidate 1\n1 - Candidate 2\n2 - Candidate 3\n3 - Candidate 4\n4 - Candidate 5\n";

	for (i = 0; i < stud; i++)
	{
		do
		{
			cout << "Polled student number " << i + 1 << ", enter your choice: ";
			cin >> vote;
		} while (vote < 0 || vote > 4);
		counter[vote]++;
	}

	for (i = 0; i < cand; i++)
		cout << "Candidate " << i + 1 << " -> " << counter[i] << endl;

	int largest = 0;

	for (i = 0; i < cand; i++)
		if (counter[i] > counter[largest])
			largest = i;

	for (i = 0; i <= cand - 1; i++)
	{
		if (counter[largest] == counter[i])
			count++;
	}

	if (count > 1)
		cout << "There is no winner" << endl;
	else
		cout << "Candidate " << candidate_num[largest] << " is the RSC apprentice." << endl;

	return 0;
}