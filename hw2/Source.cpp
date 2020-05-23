/*Name: Pranav Shivkumar
Title: Monte Carlo Simulation*/
#include<iostream>
#include<time.h>
#include<fstream>
#include<math.h>
#define pi 3.14
using namespace std;
int main()
{
	int i, n, arc = 0, out = 0;
	double val1, val2, res;
	cout << "Enter the number of iterations:  ";
	cin >> n;

	srand(time(0));

	//Open file and write data to the file
	ofstream file;
	file.open("val.txt");

	if (file.is_open())
	{
		for (i = 0; i < n; i++)
		{
			val1 = double (rand() % (n + 1)) / n;
			val2 = double (rand() % (n + 1)) / n;
			file << val1 << ", " << val2 << endl;
			
			double d = (val1 * val1) + (val2 * val2);

			if (d <= 1)
				arc++;
			out++;
		}
		cout << "Printed numbers to file val.txt" << endl;
		file.close();
	}
	else
		cout << "Unable to open file."<<endl;

	cout << "Arc: " << arc << endl;
	cout << "Out: " << out << endl;

	 res = float(4 * arc) / out;
	cout << "The actual value of pi is: " << pi << endl;
	cout << "The observed value of pi is: " << res << endl;
	return 0;
	
}