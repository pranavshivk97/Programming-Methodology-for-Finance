/*Name: Pranav Shivkumar
Title: Polynomial Class Definition*/

#include<iostream>
#include<iomanip>

using namespace std;

#include "polynomial_pranav.h"				//including the defined header file 

//defining the constructor
polynomial :: polynomial()		//definition of the default constructor
{
	for (int i = 0; i < max_size; i++)
		poly[i] = 0;			//setting all terms of the polynomial to 0 initially
}

polynomial::~polynomial()	
{
	//destructor 
}		

int polynomial::getnterm() const
{
	return nterms;		//return number of terms in the polynomial
}

void polynomial::setnterm(int m)
{
	nterms = m;		//set number of terms inputted by the user
	return;
}



bool polynomial::isEmpty(const polynomial& p) const
{
	//function to check if the polynomial is empty or not

	for (int i = 0; i < p.max_size; i++)
	{
		if (p.poly[i] != 0)
		{
			return 0;		//if polynomial is 0, return 0
		}
	}
}

void polynomial::input()
{
	int n;
	do
	{
		cout << "Enter the number of polynomial terms: ";
		if (!(cin >> n))
			cout << "Invalid entry. Please enter again: ";
		else
			if (n < 1)
				cout << "Invalid number. Please enter again.\n";
	} while (n < 1);
	setnterm(n);

	int coeff, exp;
	for (int i = 1; i <= getnterm(); i++)		//loop from 1 until the number of terms inputted by the user
	{
		do
		{
			cout << "Enter the coefficient " << i << ": ";
			if (!(cin >> coeff))		//if a non integer is entered, enter again
			{
				cout << "Invalid entry. Please enter again: ";
				cin.clear();		//clears the invalid entry so that the vald entry can be accomodated
			}

			else
				break;		//if no problems encountered, proceed normally
		} while (1);
		
		cout << "Enter the exponent " << i << ": ";
		do
		{
			if (!(cin >> exp))		//if a non integer is entered, enter again
			{
				cout << "Invalid entry. Please enter again: ";
				cin.clear();		//clear the value
			}

			else
				if (exp < 0)	//if exponent is negative, re-enter.
					cout << "Please enter a positive value: ";

			else 
				if (exp > 6)		//if exponent value is greater than 6, re-enter
					cout << "Greatest value for exponent is 6. Please enter again: ";
				
			else
				break;		//otherwise proceed normally
		} while (exp < 0 || exp > 6);
		poly[exp] += coeff;		//store the entered coefficient in the corresponding position in the polynomial. Also useful if the user enters terms of the same degree.
	} 
}

ostream& operator<<(ostream& output, const polynomial& p)
{
	if (p.isEmpty(p))		//if the polynomial is empty i.e a zero polynomial, print 0
	{
		output << 0;
	}
	else
	{
		bool b = true;				//use a bit to toggle between states 'true' and 'false'
		if (p.poly[0] != 0)			//if the first term with exponent 0 isn't 0, 
		{
			output << p.poly[0];
			b = false;				//change the state of b after writitng the value of the coefficient
		}

		for (int i = 1; i < p.max_size; i++)
		{
			if (p.poly[i] != 0)		//check if any of the terms in the polynomial have a non-zero coefficient
			{
				if (b)
				{
					output << p.poly[i] << "x^" << i;		//if true, write the value of the coefficient
					b = false;							//change the state of b after writitng the value of the coefficient
				}
				else
				{
					if (p.poly[i] < 0)		//check if any terms of the polynomial are negative
					{
						output << " - " << -p.poly[i] << "x^" << i;		//if negative, append a minus sign before writing
					}
					else
					{
						output << " + " << p.poly[i] << "x^" << i;		//if positive, add a plus sign followed by the coefficient
					}
					b = false;				//change the state of b after writitng the value of the coefficient
				}
			}
		}
	}
	return output;		//returns the output to the main function when it is called
}

polynomial polynomial :: operator+(const polynomial& p2) const
{
	polynomial p3;

	for (int i = 0; i < 6; ++i)
		p3.poly[i] = poly[i] + p2.poly[i];		//overloading the + operator to perform addition

	return p3;

}

polynomial polynomial :: operator-(const polynomial& p2) const
{
	polynomial p3;

	for (int i = 0; i < max_size; i++)
		p3.poly[i] = poly[i] - p2.poly[i];		//overloading the - sign to perform subtraction

	return p3;		//return to the main function
}

polynomial polynomial :: operator=(const polynomial& p2) 
{
	for (int i = 0; i < max_size; i++)
		(*this).poly[i] = p2.poly[i];		//using this pointer to overload the assignment operator

	return (*this);
}

polynomial polynomial :: operator+=(const polynomial& p2) const
{
	polynomial p3;

	p3 = (*this);
	p3 = p3 + p2;		//using the previous function to assign the polynomial and then add

	return p3;			//return to the main function

}

polynomial polynomial::operator-=(const polynomial& p2) const
{
	polynomial p3;
	p3 = (*this);
	p3 = p3 - p2;			//using the previous function to assign the polynomial and then subtract

	return p3;		//return to the main function
}

polynomial polynomial:: operator*(const polynomial& p2) const
{
	polynomial p3;

	for (int i = 0; i < max_size; i++)
	{
		for (int j = 0; j < max_size; j++)
		{
			p3.poly[i + j] = p3.poly[i + j] + poly[i] * p2.poly[j];		//overloading the * operator for multiplication
		}
	}

	return p3;				//return to the main function
}

polynomial polynomial :: operator*=(const polynomial& p2) const
{
	polynomial p3;

	p3 = (*this);
	p3 = p3 * p2;		//using the previous function to assign the polynomial and then multiply

	return p3;			//return to the main function
}


