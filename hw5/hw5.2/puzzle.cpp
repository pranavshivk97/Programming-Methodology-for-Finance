/*Name: Pranav Shivkumar
Title: Puzzle*/

#include<iostream>
#include<vector>

using namespace std;

//Function Prototypes
bool solve_puzzle(int index, vector<int>& puzzle);
bool solve(int index, vector<int>& puzzle, vector<bool> res);

//Function Definitions
bool solve_puzzle(int index, vector<int>& puzzle) {
	vector<bool> res;
	for (int i = 0; i < puzzle.size(); i++) {
		res.push_back(true);
	}
	return(solve(index, puzzle, res));
}

bool solve(int index, vector<int>& puzzle, vector<bool> res) {

	// if the index is the rightmost element, goal achieved
	if (index == puzzle.size())
		return true;


	// recursive case: try moving left or right, unless that would exceed the 
	// vector bounds, or go back to an already-stepped-on square.

	// try moving to left if move is valid, true
	int left = index - puzzle[index - 1];
	if (left > 0 && res[left - 1]) 
	{
		res[left - 1] = false;
		if (solve(left, puzzle, res))
			return true;
	}

	// try moving to right if move is valid, true
	int right = index + puzzle[index - 1];
	if (right <= puzzle.size() && res[right - 1]) 
	{
		res[right - 1] = false;
		if (solve(right, puzzle, res)) 
			return true;
	}

	return false;

}
int main()
{
	vector<int> puzzle;
	int num;

	//entering the elements of the puzzle 
	cout << "Enter the puzzle: ";	//enter a non integer to terminate
	while (cin >> num)
		puzzle.push_back(num);

	if (solve_puzzle(1, puzzle))	//with index = 1, if true, solved. else can't be solved
		cout << "The puzzle can be solved." << endl;
	else
		cout << "The puzzle cannot be solved." << endl;

	return 0;
}