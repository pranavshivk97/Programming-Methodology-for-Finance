/*Name: Pranav Shivkumar
Title: Account.cpp (Base Class - Account Implementation)*/

#include<iostream>
#include<fstream>

using namespace std;

#include "Account.h"

Account::Account()
{
	setCashBalance(10000);				//set account balance initially to $10,000
}

void Account::setCashBalance(double bal)
{
	/*if (bal <= 0)
	{
		cout << "Invalid entry. Please enter again: ";
		cin.ignore();
	}
	else*/
		balance = bal;
}

double Account::getCashBalance() const
{
	return balance;
}