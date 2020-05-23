#include <yvals.h>
#if (_MSC_VER >= 1600)
#define __STDC_UTF_16__
#endif
#include "mex.h" 

#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<map>
#include<vector>
#include<time.h>
#include<engine.h>

#pragma comment( lib, "libmx.lib" )
#pragma comment( lib, "libmex.lib" )
#pragma comment( lib, "libeng.lib" )

using namespace std;

#include "Account.h"
#include"BankAccount.h"
#include "StockAccount.h"

using std::ios;


StockAccount::StockAccount()
{
	head = tail = 0;
	size = 0;

	ifstream in("Stock_Portfolio.txt");

	if (!in.is_open())
	{	//create a new file
		ofstream file;
		file.open("Stock_Portfolio.txt");

		file.close();
	}
	/*else
	{
		string str;
		string name;
		int num = 0;
		double p = 0.0;
		double val = 0.0;
	}*/

	//create transaction history file with the headings
	ofstream file1;
	file1.open("Stock_Transaction_History.txt");
	file1 << "Event\t" << setw(10) << "Company Symbol\t" << setw(10) << "Number\t" << setw(10) << "Price Per Share\t" << setw(10);
	file1 << "Total Value\t" << setw(10) << "Time\t" << endl;

	file1.close();

	//create portfolio file with appropriate headings
	ofstream out;
	out.open("Stock_Portfolio.txt");
	out << "Company Symbol\t\t" << "Number\t" << "Price Per Share\t\t" << "Total" << endl;

	out.close();
}

StockAccount::~StockAccount()
{
	if (size != 0)		//if list is not empty, destroy all nodes
	{
		Node* current = head;
		Node* temp;

		while (current != 0)		//destroy all other nodes in the list, until the end
		{
			temp = current;
			current = current->next;
			delete temp;
		}
	}
}

double StockAccount::total = 0.0;			//initializing the static portfolio value

void StockAccount::addNode(Node* node)		//function to add node to DLL
{
	if (head == 0)				//if list is empty, head and tail become the head (node is the 1st node in the DLL)
		head = tail = node;

	else
	{						//otherwise interchange the links for the nodes, to add the node
		node->next = head;
		head->prev = node;
		head = node;
		node->prev = NULL;
	}
}

//void StockAccount::sort()
//{
//	//Design Pattern to choose between sorting with stock symbol or stock price
//	int val;
//	cout << "1. Sort with Stock Symbol" << endl;
//	cout << "2. Sort with Stock Price" << endl;
//	cout << "Enter your choice: ";
//
//	cin >> val;
//
//	if (val == 1)		//stock symbol sort
//	{
//		Node* current = head;
//		Node* temp = 0;
//		Node* pre = 0;
//		string name1, name2;
//		int num = 0;
//		double t = 0.0;
//
//			name1 = current->StockSymbol;				//setting the current pointer's stock name
//
//			//bubble sort algorithm to sort the list
//			for (int i = 0; i < size; i++)
//			{
//				while (current->next != 0)			//check if tail or not
//				{
//					temp = current->next;
//					name2 = temp->StockSymbol;
//					if (name1 < name2)				//checks if descending order or not
//					{
//						temp->prev = current->prev;
//						current->prev = temp;
//						current->next = temp->next;
//						if (current->next != NULL) // checking for tail pointer
//							current->next->prev = current;
//						temp->next = current;   // after swapping temptr's next pointer should be current.
//						if (pre != 0)				  // if previous pointer to the current is not NULL
//							pre->next = temp;  // then previous's next pointer should be temptr after swapping.
//						pre = temp;               // and for next iteration previous should be temptr.
//						if (head == current)       // if headptr is current, then after swapping, headptr should be temptr.
//							head = temp;
//						if (current->next == 0)    // if current's next pointer is tailpointer then after swapping, tailpointer should be current.
//							tail = current;
//					}
//
//					else
//					{
//						pre = current;
//						current = current->next;
//					}
//				}
//			}
//	}
//
//	else if (val == 2)
//	{
//		double price1, price2;
//		Node* current = head;
//		Node* temp = 0;
//		Node* pre = 0;
//
//			price1 = current->quantity * displayStockPrice(current->StockSymbol);
//
//			//bubble sort algorithm to sort the list
//			for (int i = 0; i < size; i++)
//			{
//				while (current->next != 0)
//				{
//					temp = current->next;
//					price2 = temp->quantity * displayStockPrice(current->StockSymbol);
//
//					if (price1 < price2)				//checks if descending order or not; if not, swap the nodes
//					{
//						temp->prev = current->prev;
//						current->prev = temp;
//						current->next = temp->next;
//						if (current->next != NULL) // checking for tail pointer
//							current->next->prev = current;
//						temp->next = current;   // after swapping temp's next pointer should be current.
//						if (pre != 0)				  // if previous pointer to the current is not NULL
//							pre->next = temp;  // then previous's next pointer should be temp after swapping.
//						pre = temp;               // and for next iteration previous should be temp.
//						if (head == current)       // if head is current, then after swapping, head should be tem.
//							head = temp;
//						if (current->next == 0)    // if current's next pointer is tail pointer then after swapping, tail pointer should be current.
//							tail = current;
//					}
//
//					else
//					{
//						pre = current;
//						current = current->next;
//					}
//				}
//			}
//	}
//}

Node* StockAccount::sort(Node* first, Node* second)
{
	if (!first) // if first linked list is empty
		return second;
	if (!second) // if second linked list is empty
		return first;

	ifstream myfile;
	string line, sub;
	float temp_value1, temp_value2;
	//ListNode *current=firstPtr;

	int j = rand() % 2;
	if (j == 0)
	{
		myfile.open("Result_1.txt");
	}
	else
	{
		myfile.open("Result_2.txt");
	}
	while (getline(myfile, line))
	{
		istringstream iss(line);		//constructing an istringstream object
		float val;

		while (iss >> sub >> val)
		{
			if (sub == first->StockSymbol)
				temp_value1 = val;

			if (sub == second->StockSymbol)
				temp_value2 = val;
		}
	}

	if (((first->quantity) * temp_value1) > ((second->quantity) * temp_value2))		//to check the total value of all the shares
	{
		first->next = sort(first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}

	else
	{
		// cout<<"Wrong\n";
		second->next = sort(first, second->next);
		// cout<<"Pass"<<endl;
		second->next->prev = second;
		second->prev = NULL;
		// cout<<"Returning\n";
		return second;
	}
}

Node* StockAccount::split(Node* first)			//recursively splits the list for merge sort
{
	Node* temp1 = first;
	Node* temp2 = first;
	Node* temp;

	while (temp1->next && temp1->next->next)
	{
		temp1 = temp1->next->next;
		temp2 = temp2->next;
	}

	temp = temp2->next;
	temp2->next = NULL;

	return temp;
}

Node* StockAccount::merge(Node* first)
{
	if (!first || !first->next)
	{
		return first;
	}
	Node* second = split(first);
	first = merge(first);
	second = merge(second);

	return sort(first, second);
}

//Design pattern incorporating the wrapper/adapter design pattern 
void StockAccount::wrapper()
{
	if (head == 0)
	{
		//if list is empty do nothing
	}

	else
		head = merge(head);			//otherwise start merge sort at the first node of the list
}

void StockAccount::printList()
{
	//function to display the portfolio on screen
	//sort();
	cout << "Cash balance = $" << getCashBalance() << endl;

	Node* ptr = head;
	string name;
	int num = 0;
	double t = 0.0;

	if (ptr == 0)
	{
		//if list is empty print no stocks to print
		cout << "ERROR MESSAGE: You don't own any stocks" << endl << endl;
		return;
	}

	else
	{
		//otherwise print all the nodes
		cout << "Company Symbol\tNumber\tPrice Per Share\tTotal Value" << endl;
		while (ptr != 0)
		{
			name = ptr->StockSymbol;
			num = ptr->quantity;
			if (num != 0)
			{
				cout << name << "\t\t" << num << "\t\t";

				double p = displayStockPrice(name);		//using the display stock price function 
				double tot = p * num;
				cout << "$" << p << "\t" << tot << endl;
				ptr->nodeval = tot;
				t += tot;
			}

			ptr = ptr->next;				//repeat the same for the next nodes until the end of the list
		}
	}

	total = t + getCashBalance();

	cout << endl << "Total Portfolio Value = $" << total << endl;		//print total portfolio value
}

double StockAccount::displayStockPrice(string symbol)
{
	ifstream in;

	srand(time(NULL));			//seed for rand()

	int val = rand() % 2;		//generates 0 and 1

	if (val == 0)
		in.open("Result_1.txt");		//if 0, open first Result_1.txt

	else
		in.open("Result_2.txt");		//otherwise open Result_2.txt

	if (!in.is_open())
	{
		cout << "ERROR MESSAGE: Can't open the desired file" << endl << endl;
		return -2;
	}

	string stock;
	double p = 0.0;

	while (stock != symbol && !in.eof())
	{
		in >> stock;
	}

	if (in.eof())		//stock not found if reached enf of the file
	{
		cout << "Stock symbol is not found." << endl << endl;
		return -1;
	}
	in >> p;
	return p;			//else return the price
}

void StockAccount::buyShares(string name, int n, double price, BankAccount& b)
{
	bool flag1 = false;
	bool flag2 = false;

	cout << "Enter the ticker symbol of the stock you wish to buy: ";
	cin >> name;
	cout << "Enter the number of stocks you wish to buy: ";
	cin >> n;
	cout << "Enter the maximum price you wish to pay: ";
	cin >> price;

	cout << endl << endl;

	double p = displayStockPrice(name);
	double bal = 0.0;
	double stockPurchase = n * p;

	//read the balance from the text file
	ifstream in;
	in.open("Bank_Account_Balance.txt");
	in >> bal;

	in.close();

	fstream file;
	string line, str;

	int i = rand() % 2;
	if (i == 0)
		file.open("Result_1.txt");
	else
		file.open("Result_2.txt");

	if (file.is_open())
	{
		while (getline(file, line))
		{
			istringstream iss(line);
			double value;

			while (iss >> str >> value)
			{
				if (str == name)
				{
					flag2 = true;
					if (price > value)
					{
						cout << "Price per share = $" << value << endl;
						double stockPurchase = n * value;
						if (stockPurchase > bal)		//total price of all shares exceeds balance, print error
							cout << "ERROR MESSAGE: Insufficient balance to carry out the transaction" << endl << endl;

						else
						{
							ofstream out;
							//otherwise update in text file
							out.open("Stock_Transaction_History.txt", ios::app);
							if (out.is_open())
							{
								out << "Buy\t" << name << "\t\t" << n << "\t\t" << "$" << value << "\t\t$" << stockPurchase << "\t\t";
								time_t sec = time(NULL);		//function for time
								tm* tm = localtime(&sec);

								out << tm->tm_hour << ":" << tm->tm_min << ":" << tm->tm_sec << endl;

								out.close();
							}

							else
							{
								//if file can't be opened, print error
								cout << "ERROR MESSAGE: Unable to record the transaction" << endl << endl;
								break;
							}

							//subtract the price from the balance and update on screen and in the file
							bal -= stockPurchase;
							cout << "Cash Balance = $" << bal << endl;
							setCashBalance(bal);
							getCashBalance();

							//update the bank transaction file
							b.writeToFile(3, stockPurchase, bal);

							//display transaction on screen
							cout << "Shares bought successfully!!!" << endl << endl;
							cout << "TRANSACTION INFORMATION" << endl;
							cout << "Stock Symbol Bought:  " << name << endl;
							cout << "Shares Bought:  " << n << endl;
							cout << "Total Stock Purchase: $" << stockPurchase << endl << endl;

							//update the balance in file
							ofstream out1;
							out1.open("Bank_Account_Balance.txt");
							out1 << getCashBalance();

							out1.close();

							Node* node = head;

							//to add the node to DLL
							while (node != 0)
							{
								if (node->StockSymbol == name)
								{
									node->quantity += n;		//adding the number of stocks
									flag1 = true;
									break;
								}

								node->stkprice = p;
								node->nodestr = name;
								node = node->next;
							}

							if (flag1 == false)
							{
								Node* stock = new Node(name, n);
								addNode(stock);		//adds node 'stock' to the DLL
								size++;
							}
						}
					}
				}
			}
		}
		//Stock not available
		if (flag2 == false)
			cout << "ERROR MESSAGE: The stock you want to buy is not available" << endl << endl;
	}

	displayCurrentPortfolio();
}

void StockAccount::sellShares(string name, int n, double price, BankAccount& b)
{
	bool flag = false;
	if (head != 0)		//if list is not empty
	{
		cout << "Enter the ticker symbol of the stock you wish to sell: ";
		cin >> name;
		cout << "Enter the number of stocks you wish to sell: ";
		cin >> n;
		cout << "Enter the minimum price you wish to pay: ";
		cin >> price;

		cout << endl << endl;

		double p = displayStockPrice(name);
		double bal = getCashBalance();
		double stockPurchase = n * p;
		double total = 0.0;

		//reads from the results files
		fstream file; //creating a stream object
		string line, sub;

		//randomly choosing one of the 2 files
		int i = rand() % 2;
		if (i == 0)
			file.open("Result_1.txt");

		else
			file.open("Result_2.txt");

		if (file.is_open())
		{
			while (getline(file, line))			//read each line from the file
			{
				istringstream iss(line); 
				float val;
				while (iss >> sub >> val)
				{
					Node* ind = head;
					while (ind != 0)		//if list isn't empty
					{
						if (sub == name && ind->StockSymbol == name) //checking if the stock actually exists in the portfolio
						{
							flag = true;
							if (ind->quantity < n) //to check if there are sufficient shares
							{
								cout << "ERROR MESSAGE: You do not have enough shares to sell.\n";
							}

							else
							{
								if (price < val)
								{
									float tot = n * val;
									ofstream file1;
									file1.open("Stock_Transaction_History.txt", ios::app); //recording a transaction in the history file
									if (file1.is_open())
									{
										//update transaction in the file
										file1 << "Sell\t" << name << "\t\t" << n << "\t\t$" << p << "\t\t$" << tot << "\t\t";
										time_t sec = time(NULL);
										tm* tm = localtime(&sec);
										file1 << tm->tm_hour << ":" << tm->tm_min << ":" << tm->tm_sec << endl;

										file1.close();
									}

									else
									{
										cout << "ERROR MESSAGE: Unable to open file" << endl;
										break;
									}

									bal += tot;		 //updating the cash balance by the amount obtained from selling shares
									cout << "Cash Balance = $" << bal << endl;
									setCashBalance(bal);
									getCashBalance();

									//update the balance in the file
									b.writeToFile(4, stockPurchase, bal);

									//print transaction details
									cout << "Shares sold successfully!!!" << endl << endl;
									cout << "TRANSACTION INFORMATION" << endl;
									cout << "Stock Symbol Sold:  " << name << endl;
									cout << "Shares Bought:  " << n << endl;
									cout << "Total Stock Purchase: $" << stockPurchase << endl << endl;

									ofstream out1;
									out1.open("Bank_Account_Balance.txt");
									out1 << getCashBalance();

									out1.close();

									Node* ptr = head;
									while (ptr != NULL)
									{
										if (ptr->StockSymbol == name)
										{
											ptr->quantity -= n;
											if (ptr->quantity == 0) //if the total number of shares becomes zero after selling, delete the node
											{
												Node* current = head;

												if (current == head)
												{
													if (current == tail)
													{
														//remove the node if the number of the stocks becomes 0
														head = NULL;
														tail = NULL;
														delete current;
														size--;
														return;
													}
												}
											}
										}
										ptr->stkprice = p;
										ptr->nodestr = name;
										ptr = ptr->next;
									}
								}
								else
								{
									//transaction failed since amount exceeds the price of the stock
									cout << "ERROR MESSAGE: Amount entered is greater than price of the stock" << endl;
								}
							}
						}
						ind = ind->next;
					}
				}
			}
		}

		if (flag == false)
		{
			cout << "ERROR MESSAGE: Stock is not available\n";
		}
	}
	else
		cout << "ERROR MESSAGE: You do not have any shares to sell\n";

	displayCurrentPortfolio();
}

void StockAccount::displayCurrentPortfolio()				//stores into a text file
{
	ofstream out;
	out.open("Stock_Portfolio.txt");

	out << "Company Symbol\t" << "Number\t" << "Price Per Share\t" << "Total Value\t" << endl;
	Node* ptr = head;
	string name;
	int n = 0;
	double t = 0.0;

	while (ptr != 0)
	{
		name = ptr->StockSymbol;
		n = ptr->quantity;
		if (n != 0)
		{
			out << name << "\t\t" << n << "\t";

			double p = displayStockPrice(name);
			double tot = p * n;
			out << "$" << p << "\t\t" << tot << endl;
			t += tot;
		}

		ptr = ptr->next;
	}

	total = t + getCashBalance();
	out.close();

	ofstream out1;
	out1.open("Total_Portfolio_Value.txt", ios::app);

	out1 << total << "\t";

	time_t seconds;
	seconds = time(NULL);
	/*tm* timeinfo;
	timeinfo = localtime(&seconds);*/

	out1 << seconds << endl;

	out1.close();
}


void StockAccount::transactionHistory()
{
	string str;
	ifstream file("Stock_Transaction_History.txt", ios::in);

	if (!file.is_open())
	{
		cout << "ERROR: Unable to open file" << endl;
		return;
	}

	vector<string> stock;

	while (getline(file, str))
	{
		stock.push_back(str);
	}

	for (size_t i = 0; i < stock.size(); i++)
		cout << stock[i] << endl;

	cout << endl << endl;
}

void StockAccount::viewGraph()
{
	ifstream in;
	in.open("Total_Portfolio_Value.txt");

	vector<double> val;
	vector<double> t;

	double value, tm;

	while (!in.eof())
	{
		in >> value;
		val.push_back(value);
		in >> tm;
		t.push_back(tm);
	}

	in.close();

	int size = val.size();

	double* v_array = new double[size];
	double* t_array = new double[size];

	for (size_t i = 0; i < size; i++)
	{
		v_array[i] = val[i];
		t_array[i] = t[i];
	}

	Engine* ep;
	ep = engOpen(NULL);

	if (ep == NULL)
	{
		cout << "ERROR: Engine not found" << endl;
		exit(1);
	}

	mxArray* A;
	A = mxCreateDoubleMatrix(1, size, mxREAL);
	memcpy((void*)mxGetPr(A), (void*)v_array, size * sizeof(double));
	engPutVariable(ep, "y", A);

	mxArray* B;
	B = mxCreateDoubleMatrix(1, size, mxREAL);
	memcpy((void*)mxGetPr(B), (void*)t_array, size * sizeof(double));
	engPutVariable(ep, "x", B);

	// plotting function.

	engEvalString(ep, "plot(x,y)");

	// setting up the title for graph
	engEvalString(ep, "title('Portfolio Value v Time');");
	engEvalString(ep, "xlabel('Time');");
	engEvalString(ep, "ylabel('Portfolio Value ($)');");

	mxDestroyArray(A); // destroy mxArray A
	mxDestroyArray(B); // destroy mxArray A

	system("pause");

	engEvalString(ep, "close;");
	engClose(ep);
}

void StockAccount::setCashBalance(double bal)
{
	balance = bal;
}

double StockAccount::getCashBalance()
{
	return balance;
}




