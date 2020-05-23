/*Name: Pranav Shivkumar
Title: Matrix Operations */

#include<iostream>
#include<iomanip>
using namespace std;

//Global variables
int a[10][10], b[10][10];

//Function Prototypes

void input(int [][10], int m1, int n1);
void display(int[][10], int m1, int n1);
void add(int [][10], int [][10], int m1, int n1, int m2, int n2);
void sub(int [][10], int [][10], int m1, int n1, int m2, int n2);
void mult(int [][10], int [][10], int m1, int n1, int m2, int n2);
float det(int [][10], int m1,  int n1);
void trans(int [][10], int m1, int n1);
void inv(int [][10], int m1, int n1);

void input(int a[][10], int m1, int n1)
{
	int i, j;
	cout << "Enter the elements of the matrix:" << endl;
	for (i = 0; i < m1; i++)
		for (j = 0; j < n1; j++)
			cin >> a[i][j];

	return;
}

void display(int a[][10], int m1, int n1)
{
	int i, j;

	cout << "The elements of the matrix are: " << endl;
	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < n1; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}

	return;
}

void add(int a[][10], int b[][10], int m1, int n1, int m2, int n2)
{
	int i, j;
	int sum[10][10];

	for (i = 0; i < m1; i++)
		for (j = 0; j < n1; j++)
			sum[i][j] = 0;

	if ((m1 == m2) && (n1 == n2))
	{
		for (i = 0; i < m1; i++)
			for (j = 0; j < n1; j++)
				sum[i][j] = a[i][j] + b[i][j];

		cout << "The sum of the two matrices is:" << endl;
		display(sum, m1, n1);
	}

	else
		cout << "The input matrices are not compatible for addition." << endl;

	return;
}

void sub(int a[][10], int b[][10], int m1, int n1, int m2, int n2)
{
	int i, j;
	int diff[10][10];

	for (i = 0; i < m1; i++)
		for (j = 0; j < n1; j++)
			diff[i][j] = 0;

	if ((m1 == m2) && (n1 == n2))
	{
		for (i = 0; i < m1; i++)
			for (j = 0; j < n1; j++)
				diff[i][j] = a[i][j] - b[i][j];

		cout << "The difference of the two matrices is:" << endl;
		display(diff, m1, n1);
	}

	else
		cout << "The input matrices are not compatible for subtraction." << endl;

	return;
}

void mult(int a[][10], int b[][10], int m1, int n1, int m2, int n2)
{
	int i, j, k;
	int prod[10][10];

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

	return;
}

float det(int a[][10], int m1, int n1)
{
	int i;
	float d = 0;

	for (i = 0; i < 3; i++)
		d += a[0][i] * ((a[1][(i + 1) % 3] * a[2][(i + 2) % 3]) - (a[1][(i + 2) % 3] * a[2][(i + 1) % 3]));

	cout << "The determinant of the matrix is: " << d << endl;

	return d;
}

void trans(int a[][10], int m1, int n1)
{
	int i, j;
	int tr[10][10];

	for (i = 0; i < n1; i++)
		for (j = 0; j < m1; j++)
			tr[i][j] = 0;

	for (i = 0; i < m1; i++)
		for (j = 0; j < n1; j++)
			tr[i][j] = a[j][i];

	cout << "The transpose of the matrix is: " << endl;
	display(tr, m1, n1);

	return;
}

void inv(int a[][10], int m1, int n1)
{
	int i, j;
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

	return;
}


int main()
{
	int val;
	int m1, n1, m2, n2;

	while (1)
	{
		cout << "Menu" << endl;
		cout << "1: Matrix Addition" << endl;
		cout << "2: Matrix Subtraction" << endl;
		cout << "3: Matrix Multiplication" << endl;
		cout << "4: Determinant of the Matrix" << endl;
		cout << "5: Transpose of the Mattrix" << endl;
		cout << "6: Inverse of the Matrix" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> val;

		switch (val)
		{
		case 1: cout << "You have chosen the operation - Matrix Addition.\n";
				cout << "Enter the number of rows in the matrix: ";
				cin >> m1;
				cout << "Enter the number of columns in the matrix: ";
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
				cout << "Enter the number of rows in the matrix: ";
				cin >> m2;
				cout << "Enter the number of columns in the matrix: ";
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
				break;

		case 2: cout << "You have chosen the operation - Matrix Subtraction\n";
				cout << "Enter the number of rows in the matrix: ";
				cin >> m1;
				cout << "Enter the number of columns in the matrix: ";
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
				cout << "Enter the number of rows in the matrix: ";
				cin >> m2;
				cout << "Enter the number of columns in the matrix: ";
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
				break;

		case 3: cout << "You have chosen the operation - Matrix Multiplication\n";
				cout << "Enter the number of rows in the matrix: ";
				cin >> m1;
				cout << "Enter the number of columns in the matrix: ";
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
				cout << "Enter the number of rows in the matrix: ";
				cin >> m2;
				cout << "Enter the number of columns in the matrix: ";
				cin >> n2;
				if ((m2 > 10) || (n2 > 10))
					cout << "Please enter again.\n";
				else
				{
					input(b, m2, n2);
					display(b, m2, n2);
				}
				mult(a, b, m1, n1, m2, n2);
				break;

		case 4: cout << "You have chosen the operation - Determinant of a Matrix \n";
				cout << "Enter the number of rows in the matrix: ";
				cin >> m1;
				cout << "Enter the number of columns in the matrix: ";
				cin >> n1;
				if ((m1 != 3) && (n1 != 3))
					cout << "The determinant cannot be computed.\n";
				else
				{
					input(a, m1, n1);
					display(a, m1, n1);
				}
				det(a, m1, n1);
				break;

		case 5: cout << "You have chosen the operation - Transpose of a Matrix\n";
				cout << "Enter the number of rows in the matrix: ";
				cin >> m1;
				cout << "Enter the number of columns in the matrix: ";
				cin >> n1;
				if ((m1 > 10) || (n1 > 10))
					cout << "Please enter again.\n";
				else
				{
					input(a, m1, n1);
					display(a, m1, n1);
				}
				trans(a, n1, m1);
				break;

		case 6: cout << "You have chosen the operation - Inverse of a Matrix \n";
				cout << "Enter the number of rows in the matrix: ";
				cin >> m1;
				cout << "Enter the number of columns in the matrix: ";
				cin >> n1;
				if ((m1 != 3) && (n1 != 3))
					cout << "The determinant cannot be computed.\n";
				else
				{
					input(a, m1, n1);
					display(a, m1, n1);
				}
				inv(a, m1, n1);
				break;

		case 7: cout << "Exiting the program." << endl;
				exit(0);
				break;

		default: cout << "Invalid option. Please choose again.\n";
				 break;
		}
	}

	return 0;
}

