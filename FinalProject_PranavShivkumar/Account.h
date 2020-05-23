/*Name: Pranav Shivkumar
Title: Account.h (Account Base Class Header)*/

#ifndef Account_h
#define Account_h

class Account
{
public:
	Account();

	virtual void setCashBalance(double);
	virtual double getCashBalance() const;
private:
	double balance;

};


#endif

