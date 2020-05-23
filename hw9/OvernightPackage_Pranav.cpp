/*Name: Pranav Shivkumar
Title: OvernightPackage.cpp*/

#include<iostream>

using namespace std;

#include "OvernightPackage.h"		//include the defined header file  with the class declaration

OvernightPackage::OvernightPackage():Package()		//initialize fee to 0
{
	fee_over = 0;
}

//initilize fee as needed
OvernightPackage::OvernightPackage(string sname, string rname, string saddress, string raddress, string scity, string rcity, string sstate, string rstate, string szip, string rzip, double wt, double cst, double fee)
	:Package(sname, rname, saddress, raddress, scity, rcity, sstate, rstate, szip, rzip, wt, cst)
{
	fee_over = fee;
}

OvernightPackage::~OvernightPackage()
{
	//empty body f destructor
}

string OvernightPackage::gettype() const		//return type of delivery
{
	return "Overnight Delivery";
}

void OvernightPackage::setfee(double fee)		//set the fee
{
	fee_over = fee;
}

double OvernightPackage::getfee() const			//return the fee
{
	return fee_over;
}

double OvernightPackage::calculateCost() const		//calculate and return the total cost
{
	return Package::calculateCost() + (Package::getwt() * fee_over);
}