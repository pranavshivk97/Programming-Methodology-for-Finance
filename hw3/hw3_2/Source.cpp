#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

//Function Prototypes
void input(vector<vector<int> >& a, int m1, int n2);
void display(vector<vector<int> >& a, int m1, int n1);
void add(vector<vector<int> >& a, vector<vector<int> >& b, int m1, int n1, int m2, int n2);
void sub(vector<vector<int> >& a, vector<vector<int> >& b, int m1, int n1, int m2, int n2);
void mult(vector<vector<int> >& a, vector<vector<int> >& b, int m1, int n1, int m2, int n2);
float det(vector<vector<int> >& a, int m1, int n1);
void trans(vector<vector<int> >& a, int m1, int n1);
void inv(vector<vector<int> >& a, int m1, int n1);

void input(vector<vector<int> >& a, int m1, int n1)
{
	size_t i;
	size_t j;

	int num;
	
	cout << "Enter the elements of the vector: ";
	for (i = 0; i < m1; i++)
	{
		vector<int> l;
		for ( j = 0; j < n1; j++)
		{
			cin >> num;
			l.push_back(num);
		}
		a.push_back(l);
	}
}

void display(vector<vector<int> >& a, int m1, int n1)
{
	size_t i;
	size_t j;
	
	for (i = 0; i < a.size(); i++)
	{
		for (j = 0; j < a[i].size(); j++)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
}

void add(vector<vector<int> >& a, vector<vector<int> >& b, int m1, int n1, int m2, int n2)
{
	size_t i;
	size_t j;

	vector<vector<int> > sum(m1, vector<int> (n1, 0));	

	if ((m1 == n1) && (m2 == n2))
	{
		for (i = 0; i < m1; i++)
		{
			for (j = 0; j < n1; j++)
			{
				sum[i][j] = a[i][j] + b[i][j];
			}
		}

		cout << "The sum of the vectors is: " << endl;
		display(sum, m1, n1);
	}
	else
		cout << "The vectors are not compatible with addition." << endl;
}

void sub(vector<vector<int> >& a, vector<vector<int> >& b, int m1, int n1, int m2, int n2)
{
	size_t i;
	size_t j;

	vector<vector<int> > diff(m1, vector<int>(n1, 0));

	if ((m1 == n1) && (m2 == n2))
	{
		for (i = 0; i < m1; i++)
		{
			for (j = 0; j < n1; j++)
			{
				diff[i][j] = a[i][j] - b[i][j];
			}
		}

		cout << "The difference of the vectors is: " << endl;
		display(diff, m1, n1);
	}
	else
		cout << "The vectors are not compatible with addition." << endl;
}

void mult(vector<vector<int> >& a, vector<vector<int> >& b, int m1, int n1, int m2, int n2)
{
	size_t i;
	size_t j;
	size_t k;

	vector<vector<int> > prod(m1, vector<int>(n1, 0));

	for (i = 0; i < m1; i++)
		for (j = 0; j < n2; j++)
			prod[i][j] = 0;

	if (m1 != n2)
		cout << "The input matrices are not compatible with multiplication." << endl;
	else
	{
		for (i = 0; i < m1; i++)
		{
			for (j = 0; j < n2; j++)
			{
				for (k = 0; k < n1; k++)
				{
					prod[i][j] += a[i][k] * b[k][j];
				}
			}

		}

		cout << "The product of the matrices is:" << endl;
		display(prod, m1, n2);
	}
}

float det(vector<vector<int> >& a, int m1, int n1)
{
	size_t i;
	float d = 0;

	for (i = 0; i < 3; i++)
		d += a[0][i] * ((a[1][(i + 1) % 3] * a[2][(i + 2) % 3]) - (a[1][(i + 2) % 3] * a[2][(i + 1) % 3]));

	cout << "The determinant of the matrix is: " << d << endl;

	return d;
}

void trans(vector<vector<int> >& a, int m1, int n1)
{
	size_t i;
	size_t j;

	vector<vector<int> > tr(m1, vector<int> (n1, 0));

	for (i = 0; i < m1; i++)
		for (j = 0; j < n1; j++)
			tr[i][j] = a[j][i];

	cout << "The transpose of the matrix is: " << endl;
	display(tr, n1, m1);
}

void inv(vector<vector<int> >& a, int m1, int n1)
{
	size_t i;
	size_t j;
	
	float D;

	D = det(a, m1, n1);

	if (D == 0)
		cout << "The  inverse does not exist for this matrix." << endl;
	else
	{
		cout << "The inverse of the matrix is:" << endl;
		for (i = 0; i < n1; i++)
		{
			for (j = 0; j < n1; j++)
			{
				cout << setprecision(2) << setw(4) << ((a[(j + 1) % 3][(i + 1) % 3] * a[(j + 2) % 3][(i + 2) % 3]) - (a[(j + 1) % 3][(i + 2) % 3] * a[(j + 2) % 3][(i + 1) % 3])) / D;
				cout << setw(4);
			}
			cout << endl;
		}
	}
}
int main()
{
	int val;
	int m1 = 0, n1 = 0, m2 = 0, n2 = 0;
	vector<vector<int> > a(m1, vector<int>(n1, 0));
	vector<vector<int> > b(m2, vector<int>(n2, 0));

	while (1)
	{
		cout << "Menu" << endl;
		cout << "Choice 1: Addition" << endl;
		cout << "Choice 2: Subtraction" << endl;
		cout << "Choice 3: Multiplication" << endl;
		cout << "Choice 4: Determinant" << endl;
		cout << "Choice 5: Transpose" << endl;
		cout << "Choice 6: Inverse" << endl;
		cout << "Choice 7: Exit." << endl;
		cout << "Enter your choice: ";
		cin >> val;

		switch (val)
		{
		case 1: cout << "You have chosen the operation - Matrix Addition.\n";
			cout << "Enter the number of rows in the vector: ";
			cin >> m1;
			cout << "Enter the number of columns in the vector: ";
			cin >> n1;
			if ((m1 > 10) || (n1 > 10))
			{
				cout << "Please enter again.\n";
				break;
			}
			else
			{
				input(a, m1, n1);
				display(a, m1, n1);
			}
			cout << "Enter the number of rows in the vector: ";
			cin >> m2;
			cout << "Enter the number of columns in the vector: ";
			cin >> n2;
			if ((m2 > 10) || (n2 > 10))
			{
				cout << "Please enter again.\n";
				break;
			}
			else
			{
				input(b, m2, n2);
				display(b, m2, n2);
			}
			add(a, b, m1, n1, m2, n2);

			a.clear();
			b.clear();
			break;

		case 2:cout << "You have chosen the operation - Matrix Subtraction\n";
			cout << "Enter the number of rows in the vector: ";
			cin >> m1;
			cout << "Enter the number of columns in the vector: ";
			cin >> n1;
			if ((m1 > 10) || (n1 > 10))
			{
				cout << "Please enter again.\n";
				break;
			}
			else
			{
				input(a, m1, n1);
				display(a, m1, n1);
			}
			cout << "Enter the number of rows in the vector: ";
			cin >> m2;
			cout << "Enter the number of columns in the vector: ";
			cin >> n2;
			if ((m2 > 10) || (n2 > 10))
			{
				cout << "Please enter again.\n";
				break;
			}
			else
			{
				input(b, m2, n2);
				display(b, m2, n2);
			}
			sub(a, b, m1, n1, m2, n2);

			a.clear();
			b.clear();
			break;
			
		case 3: cout << "You have chosen the operation - Matrix Multiplication\n";
			cout << "Enter the number of rows in the vector: ";
			cin >> m1;
			cout << "Enter the number of columns in the vector: ";
			cin >> n1;
			if ((m1 > 10) || (n1 > 10))
			{
				cout << "Please enter again.\n";
				break;
			}
			else
			{
				input(a, m1, n1);
				display(a, m1, n1);
			}
			cout << "Enter the number of rows in the vector: ";
			cin >> m2;
			cout << "Enter the number of columns in the vector: ";
			cin >> n2;
			if ((m2 > 10) || (n2 > 10))
				cout << "Please enter again.\n";
			else
			{
				input(b, m2, n2);
				display(b, m2, n2);
			}
			mult(a, b, m1, n1, m2, n2);

			a.clear();
			b.clear();
			break;

		case 4: cout << "You have chosen the operation - Determinant of a Matrix \n";
			cout << "Enter the number of rows in the vector: ";
			cin >> m1;
			cout << "Enter the number of columns in the vector: ";
			cin >> n1;
			if ((m1 != 3) && (n1 != 3))
				cout << "The determinant cannot be computed.\n";
			else
			{
				input(a, m1, n1);
				display(a, m1, n1);
			}
			det(a, m1, n1);
			a.clear();
			break;

		case 5: cout << "You have chosen the operation - Transpose of a Matrix\n";
			cout << "Enter the number of rows in the vector: ";
			cin >> m1;
			cout << "Enter the number of columns in the vector: ";
			cin >> n1;
			if ((m1 > 10) || (n1 > 10))
				cout << "Please enter again.\n";
			else
			{
				input(a, m1, n1);
				display(a, m1, n1);
			}
			trans(a, n1, m1);

			a.clear();
			break;

		case 6: cout << "You have chosen the operation - Inverse of a Matrix \n";
			cout << "Enter the number of rows in the vector: ";
			cin >> m1;
			cout << "Enter the number of columns in the vector: ";
			cin >> n1;
			if ((m1 != 3) && (n1 != 3))
				cout << "The determinant cannot be computed.\n";
			else
			{
				input(a, m1, n1);
				display(a, m1, n1);
			}
			inv(a, m1, n1);

			a.clear();
			break;

		case 7: exit(0);
			break;

		default: cout << "Invalid choice. Please choose again." << endl;
			break;
		}
	}

	return 0;
}