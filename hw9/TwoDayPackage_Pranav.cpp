/*Name: Pranav Shivkumar
Title: TwoDayPackage.cpp*/

#include<iostream>

using namespace std;

#include "TwoDayPackage.h"		//include the defined header file with class declaration

TwoDayPackage::TwoDayPackage():Package()
{
	fee_twoday = 0;			//initialize fee to 0
}

//initialize the fee as needed
TwoDayPackage::TwoDayPackage(string sname, string rname, string saddress, string raddress, string scity, string rcity, string sstate, string rstate, string szip, string rzip, double wt, double cst, double fee)
	:Package(sname, rname, saddress, raddress, scity, rcity, sstate, rstate, szip, rzip, wt, cst)
{
	fee_twoday = fee;
}

TwoDayPackage::~TwoDayPackage()
{
	//empty body of constructor
}

string TwoDayPackage::gettype() const
{
	return "Two Day Delivery";		//return type of delivery
}

void TwoDayPackage::setfee(double fee)		//set and return the two day fee
{
	fee_twoday = fee;
}

double TwoDayPackage::getfee() const
{
	return fee_twoday;
}

double TwoDayPackage::calculateCost() const		//return the total cost
{
	return Package::calculateCost() + (Package::getwt() * fee_twoday);
}
