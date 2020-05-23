/*Name: Pranav Shivkumar
Title: BankAccount.h (Bank Account Header)*/

#ifndef BankAccount_h
#define BankAccount_h

#include"Account.h"

class BankAccount : public Account			//public derivation of the BankAccount class from the Account class
{
public:
	BankAccount();					//costructor for Bank Account

	void viewAccountBalance();		//function to view the account balance
	//void readBalancefromFile();

	void setDeposit(double);		//set the amount to be deposited
	double getDeposit();			//return the amount to be deposited

	void setWithdrawAmount(double);	//set the aamount to be withdrawn
	double getWithdrawAmount();		//return the amount to be withdrawn

	void depositMoney();			//function to deposit money into the account
	void withdrawMoney();			//function to withdraw money from the account

	virtual void setCashBalance(double);
	virtual double getCashBalance();

	void writeToFile(int, double, double);	//write the transaction details to the file 
	void printHistory();					//print the transaction history to screen 

private:
	double deposit, withdraw, balance;
	double total;				//total amount after depositing/withdrawing
};


#endif
