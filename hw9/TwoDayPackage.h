/*Name: Pranav Shivkumar
Title: TwoDayPackage.h*/

#ifndef TwoDayPackage_h
#define TwoDayPackage_h

#include "Package.h"

class TwoDayPackage : public Package			//public derivation of class TwoDayPackage
{
public:
	TwoDayPackage();		//default constructor

	//constructor to initialize the members
	TwoDayPackage(string, string, string, string, string, string, string, string, string, string, double, double, double);
	~TwoDayPackage();		//destructor

	virtual string gettype() const;		//returns the type of delivery

	virtual void setfee(double);		//additional fee per oz
	virtual double getfee() const;

	double calculateCost() const;		//final cost of the package

private:
	double fee_twoday;				//additional cost member
};

#endif
