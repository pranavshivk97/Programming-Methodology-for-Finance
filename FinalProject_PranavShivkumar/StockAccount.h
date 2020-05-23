/*Name: Pranav Shivkumar
Title: StockAccount.h (Node for DLL header and Stock Portfolio Header)*/

#ifndef StockAccount_h
#define StockAccount_h

#include<map>

#include"Account.h"

class Node
{
	friend class StockAccount;
public:
	Node(string& name, int n)
		:StockSymbol(name), quantity(n)			//constructor that initializes the stock symbol and number of stocks
	{
		this->prev = NULL;						//set the prev and next pointers to NULL initially
		this->next = NULL;
	}
	

private:
	string StockSymbol;
	int quantity;
	double stkprice;

	double nodeval;
	string nodestr;

	Node* next;
	Node* prev;
};

class StockAccount : public Account			//public derivation of class StockAccount from base class Account
{
public:
	StockAccount();
	~StockAccount();
	
	double displayStockPrice(string);		//displays the price per share of stock symbol (string)

	static double total;
	void addNode(Node*);				//adds a node to the DLL
	void printList();					//print the DLL

	Node* sort(Node*, Node*);			//sorts the list
	//void sort();
	Node* split(Node*);					//splits the list recursively for merge sort
	Node* merge(Node*);					//merge sort call
	void wrapper();						

	void displayCurrentPortfolio();		//stores the portfolio in file
	void buyShares(string, int, double, BankAccount&);		//function to buy shares
	void sellShares(string, int, double, BankAccount&);		//function to sell shares
	void viewGraph();									//function to view the graph (MATLAB interface)
	void transactionHistory();							//read from file and print transaction history

	virtual void setCashBalance(double);
	virtual double getCashBalance();

private:
	Node* head;
	Node* tail;
	int size;

	double balance;
};


#endif
