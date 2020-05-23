/*Name: Pranav Shivkumar
Title: Package.h*/

#ifndef package_h
#define package_h

#include <string>

using namespace std;

class Package
{
public:
	Package();		//default constructor
	//constructor for initializing the variables
	Package(string, string, string, string, string, string, string, string, string, string, double, double);	
	~Package();		//destructor

	virtual string gettype() const;		//returns the type of delivery

	virtual void setsender(string);		//sender name
	virtual string getsender() const;	

	virtual void setsender_address(string);		//sender address
	virtual string getsender_address() const;	

	virtual void setsender_city(string);		//sender city
	virtual string getsender_city() const;	

	virtual void setsender_state(string);		//sender state
	virtual string getsender_state() const;	

	virtual void setsender_zip(string);			//sender zip code
	virtual string getsender_zip() const;		

	virtual void setrecipient(string);			//recipient name
	virtual string getrecipient() const;

	virtual void setrecipient_address(string);	//recipient address
	virtual string getrecipient_address() const;

	virtual void setrecipient_city(string);		//recipient city
	virtual string getrecipient_city() const;

	virtual void setrecipient_state(string);	//recipient state 
	virtual string getrecipient_state() const;

	virtual void setrecipient_zip(string);		//recipient zip code
	virtual string getrecipient_zip() const;

	virtual void setwt(double);					//weight of the package
	virtual double getwt() const;				

	virtual void setcost(double);				//cost per ounce of the package
	virtual double getcost() const;

	virtual double calculateCost() const;		//calculate total cost
	

private:			//private members for the class
	string sender, recipient;
	string sender_address, recipient_address;
	string sender_city, recipient_city, sender_state, recipient_state;
	string sender_zip, recipient_zip;

	double weight, cost;		//weight(oz) of the package and cost per ounce
};

#endif
