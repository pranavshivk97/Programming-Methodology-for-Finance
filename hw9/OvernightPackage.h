/*Name: Pranav Shivkumar
Title: OvernightPackage.h*/

#ifndef OvernightPackage_h
#define OvernightPackage_h

#include"Package.h"

class OvernightPackage : public Package			//public derivation of the class from base class Package
{
public:
	OvernightPackage();		//default constructor

	//initialize members of the class
	OvernightPackage(string, string, string, string, string, string, string, string, string, string, double, double, double);
	~OvernightPackage();		//destructor

	virtual string gettype() const;		//return type of delivery

	virtual void setfee(double);		//set and returns the additional cost 
	virtual double getfee() const;

	double calculateCost() const;		//returns the final cost
	

private:
	double fee_over;			//additonal cost member
};

#endif