/*Name: Prnav Shivkumar
Title: Binary Strings*/

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//Function Prototype
int countBinStr(int n, int last_dig);

int countBinStr(int n, int last_dig)
{

	//for 0 bit, answer is 0
	if (n == 0)
		return 0;

	//if only 1 digit is left, 0 can have only 1 to be placed while 1 can have 0 or 1 placed.
	if (n == 1)
	{
		if (last_dig)
			return 2;
		else
			return 1;
	}

	//if the last digit is 1, append either 1 or 0, decrement n and call again
	if (last_dig == 1)
		return countBinStr(n - 1, 0) + countBinStr(n - 1, 1);

	else
		//if last digit is 0, only append 1, decrement n and call again
		return countBinStr(n - 1, 1);

}
int main()
{
	int n;

	cout << "Enter the length of the string: ";
	cin >> n;
	cout<< endl << "Number of binary strings without consecutive 0s is: "<< countBinStr(n, 1);
	cout << endl;
	return 0;
}