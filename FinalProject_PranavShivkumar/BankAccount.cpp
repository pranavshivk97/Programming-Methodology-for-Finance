/*Name: Pranav Shivkumar
Title: BankAccount.cpp (Bank Account Implementation)*/

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime>
#include<vector>

//using std::cout;
//using std::cin;
//using std::endl;
//using std::fixed;
//using std::setprecision;
//using std::ofstream;
//using std::string;
//using std::setw;

using namespace std;

#include "Account.h"
#include "BankAccount.h"

//constructor definition for Bank Account
BankAccount::BankAccount()
{
	setCashBalance(10000);				//if not defined, set the balance to $10,000
	deposit = withdraw = 0.0;
	balance = getCashBalance();			//assigning the balance to be the cash balance when the class object is created

	ofstream file;
	file.open("Bank_Account_Balance.txt");
	file << getCashBalance();				//write the balance to a text file

	file.close();

	ofstream fout;
	fout.open("Bank_Transaction_History.txt", ios::app);
	fout << "EVENT\t" << setw(15) << "AMOUNT\t" << setw(15) << "DATE\t" << setw(15) << "BALANCE" << endl;

	fout.close();
}

void BankAccount::viewAccountBalance()
{
	ifstream f1;
	f1.open("Bank_Account_Balance.txt");
	if (!f1)
	{
		//if the file doesn't exist, balance is $10,000 by default
		double bal = 10000;
		setCashBalance(bal);
		getCashBalance();
		cout << "Your account currently has $" << fixed << setprecision(2) << bal << endl << endl;
	}
	else
	{
		//if the file exists, read the balance from the file and print on screen
		double bal = 0.0;
		f1 >> bal;
		cout << "Your account currently has $" << fixed << setprecision(2) << bal << endl << endl;
		ofstream fout;
		fout.open("Bank_Account_Balance.txt");
		fout << bal << endl;
		fout.close();
	}

	f1.close();
}

void BankAccount::setDeposit(double d)
{
	//if the deposit entered is 0 or negative, print invlid amount
	if (d <= 0)
	{
		cout << "Invalid entry. Please enter again: ";
		cin.ignore();
	}
	else
		//otherwise, read the deposit
		deposit = d;
}

double BankAccount::getDeposit()
{
	//return the deposit amount
	return deposit;
}

void BankAccount::setWithdrawAmount(double w)
{
	//if the amount to be withdrawn is 0 or negative, print invalid
	if (w <= 0)
	{
		cout << "Invalid entry. Please enter again: ";
		cin.ignore();
	}
	else
		//otherwise, read the amount to be withdrawn
		withdraw = w;
}

double BankAccount::getWithdrawAmount()
{
	//return the amount to be withdrawn
	return withdraw;
}

void BankAccount::depositMoney()			//function to carry out the deposit function
{
	cout << "You have chosen to deposit $" << getDeposit() << " into your account." << endl << endl;
	viewAccountBalance();

	//consult the balance in the text file. Add the deposit amount to the balance. 
	ifstream in;
	in.open("Bank_Account_balance.txt");
	in >> total;
	total += getDeposit();			//add the deposit amount to the balance, contained in the 'total' member
	setCashBalance(total);			//update the account cash balance using 'total'
	balance = getCashBalance();

	//print the transaction results on screen
	cout << "Money successfully deposited into your account." << endl << endl;
	cout << "Your account currently has : $" << fixed << setprecision(2) << balance << endl << endl;

	writeToFile(1, getDeposit(), balance);			//write the corresponding results to the text file
	ofstream file;
	file.open("Bank_Account_Balance.txt");			//store the resulting balance to the file
	file << getCashBalance();

	file.close();
	in.close();
}

void BankAccount::withdrawMoney()			//function to carry out the withdraw the amount from the bank account
{
	cout << "You have chosen to withdraw $" << fixed << setprecision(2) << getWithdrawAmount() << " from your account." << endl << endl;

	double b;						// read balance from file
	ifstream f1("Bank_Account_Balance.txt");
	f1 >> b;
	setCashBalance(b);
	getCashBalance();

	viewAccountBalance();

	//if withdraw amount is greater than balance, cancel the transaction with an ERROR MESSAGE
	if (getWithdrawAmount() > getCashBalance())
	{
		cout << "ERROR MESSAGE: Your account has insufficient balance to carry out the transaction." << endl << endl;
		return;
	}

	else
	{
		//otherwise write to the file 
		writeToFile(2, getWithdrawAmount(), b);

		total -= getWithdrawAmount();			//subtract the withdraw amount from the balance, contained in the 'total' member
		setCashBalance(total);					//update the account cash balance using 'total' and assign to balance
		balance = getCashBalance();			
		
		//print the corresponding results to the screen
		cout << "The amount was successfully withdrawn from your account." << endl << endl;
		cout << "Your account currently has: $" << fixed << setprecision(2) << balance << endl << endl;

		ofstream file("Bank_Account_Balance.txt");
		file << balance;					//update the balance in the text file

		file.close();
	}
}

void BankAccount::writeToFile(int val, double amt, double bal)			//function that writes to text file for transaction history
{
	string mode;
	ifstream in;

	in.open("Bank_Account_Balance.txt");
	in >> bal;
	in.close();

	time_t t = time(NULL);				//function for time
	tm* timePtr = localtime(&t);

	//modes to chooose from: 1. Deposit 2. Withdraw 3. Buy 4. Sell
	switch (val)
	{
	case 1:
		mode = "Deposit";
		amt = getDeposit();
		bal += deposit;
		setCashBalance(bal);
		getCashBalance();
		break;
	case 2:
		mode = "Withdraw";
		amt = getWithdrawAmount();
		if (amt > bal)
			return;
		else
		{
			amt = getWithdrawAmount();
			bal -= withdraw;
			setCashBalance(bal);
			getCashBalance();
		}
		break;
	case 3:
		mode = "Buy";
		bal -= amt;
		setCashBalance(bal);
		getCashBalance();
		break;
	case 4:
		mode = "Sell";
		bal += amt;
		setCashBalance(bal);
		getCashBalance();
		break;
	default:
		break;
	}
	
	ofstream f1;
	f1.open("Bank_Account_Balance.txt");
	f1 << bal;
	setCashBalance(bal);			
	getCashBalance();
	f1.close();

	ofstream file;
	file.open("Bank_Transaction_History.txt", std::ios::app);
	file << mode << setw(13) << amt << setw(13);				//print the transactions in the text file
	file << (timePtr->tm_mday) << "/" << (timePtr->tm_mon) + 1 << "/" << (timePtr->tm_year) + 1900 << setw(13);
	file << "$" << bal << endl;	

	file.close();
}

void BankAccount::printHistory()
{
	//read from the transaction file and write to screen
	string str;
	std::ifstream file("Bank_Transaction_History.txt", std::ios::in);

	if (!file.is_open())
	{
		cout << "ERROR: Unable to open file" << endl;
		return;
	}

	std::vector<string> bank;

	while (std::getline(file, str))
	{
		bank.push_back(str);
	}

	for (size_t i = 0; i < bank.size(); i++)
		cout << bank[i] << endl;
	
	cout << endl << endl;
}

void BankAccount::setCashBalance(double bal)
{
	//virtual function to set the account balance
	balance = bal;
}

double BankAccount::getCashBalance()
{
	//virtual function to get the account balance
	return balance;
}