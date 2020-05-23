/*Name: Pranav Shivkumar
Title: Main.cpp (Main File)*/

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

#include"Account.h"
#include"BankAccount.h"
#include"StockAccount.h"

int main(void)
{
	double dep, w;
	double price;
	string name;
	int num, val;
	int av, sv, bv;
	char v1, v2, v3;

	dep = w = price = 0.0;
	num = val = v1 = v2 = v3 = 0;

	//instantaiting objects from all classes
	Account *a = new Account();
	StockAccount* s = new StockAccount();
	BankAccount b;

	s->displayCurrentPortfolio();

	while (1)
	{
	menu1:
		cout << "Welcome to the Account Management System" << endl << endl;

		cout << "Please select an account to access " << endl;
		cout << "1. Stock Portfolio Account" << endl;
		cout << "2. Bank Account " << endl;
		cout << "3. Exit " << endl << endl;
		cout << "Option: ";
		cin >> av;

		switch (av)
		{
		case 1:
		menu2:
			cout << "Stock Portfolio Account" << endl << endl;

			cout << "Please select an option: " << endl;
			cout << "1. Display the price for a current stock symbol" << endl;
			cout << "2. Display the current portfolio" << endl;
			cout << "3. Buy Shares" << endl;
			cout << "4. Sell Shares" << endl;
			cout << "5. View a graph for the portfolio value" << endl;
			cout << "6. View Transaction History" << endl;
			cout << "7. Return to the previous menu" << endl << endl;
			cout << "Option: ";
			cin >> sv;

			switch (sv)
			{
			case 1:
				cout << "Display the price for a current stock symbol" << endl << endl;
				cout << "Enter the stock symbol: ";
				cin >> name;
				cout << endl;
				
				price = s->displayStockPrice(name);		//return the price and print in the format
				cout << "Stock Symbol\t" << setw(10) << "Price Per Share" << endl;
				cout << name << "\t" << setw(15) << price << endl << endl;
				goto menu2;
				break;

			case 2:
				cout << "Display the current portfolio" << endl;
				s->wrapper();		//uses the sort wrapper function to sort the list in descending order of price before printing
				s->printList();
				goto menu2;
				break;

			case 3:
				cout << "Buy Shares" << endl;
				s->buyShares(name, num, price, b);		//buy shares and update the balance
				goto menu2;
				break;

			case 4:
				cout << "Sell Shares" << endl;
				s->sellShares(name, num, price, b);		//sell shares andupdate balance
				goto menu2;
				break;

			case 5:
				cout << "View a graph for the portfolio value" << endl;
				s->viewGraph();		//view the graph on MATLAB
				goto menu2;
				break;

			case 6:
				cout << "View Transaction History" << endl;
				s->transactionHistory();		//view the transaction history
				goto menu2;
				break;

			case 7:
				cout << "Returning to the Previous Menu" << endl << endl;
				goto menu1;
				break;

			default:
				cout << "Invalid Option. Returning to menu " << endl;
				goto menu2;
				break;
			}

			break;

		case 2:
		menu3:
			cout << "Bank Account" << endl << endl;

			cout << "Please choose an option: " << endl;
			cout << "1. View Account Balance" << endl;
			cout << "2. Deposit Money" << endl;
			cout << "3. Withdraw Money" << endl;
			cout << "4. Print the History " << endl;
			cout << "5. Return to the previous menu" << endl << endl;
			cout << "Option: ";
			cin >> bv;

			switch (bv)
			{
			case 1:
				cout << "View Account Balance" << endl << endl;
				b.viewAccountBalance();
				goto menu3;
				break;

			case 2:
				//deposit money and update balance
				cout << "Deposit Money" << endl;
				cout << "Enter the amount you want to deposit into your account: ";
				cin >> dep;
				b.setDeposit(dep);
				b.getDeposit();
				b.depositMoney();
				goto menu3;
				break;

			case 3:
				//withdraw money and update balance
				cout << "Withdraw Money" << endl;
				cout << "Enter the amount you want to withdraw from your account: ";
				cin >> w;
				b.setWithdrawAmount(w);
				b.getWithdrawAmount();
				b.withdrawMoney();
				goto menu3;
				break;

			case 4:
				//print the history
				cout << "Print the History" << endl << endl;
				b.printHistory();
				goto menu3;
				break;

			case 5:
				cout << "Returning to the Previous Menu" << endl << endl;
				goto menu1;
				break;

			default: 
				cout << "Invalid choice. Returning to menu" << endl;
				goto menu3;
				break;
			}

			break;

		case 3:
			//exit the program
			cout << "Exiting the Program" << endl << endl;
			exit(0);
			break;

		default:
			cout << "Invalid Option. Returning to menu" << endl;
			goto menu1;
			break;
		}
	}
}