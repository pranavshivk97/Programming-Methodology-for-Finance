/*Name: Pranav Shivkumar
Title: Package_Pranav.cpp*/

#include<iostream>

using namespace std;

#include "Package.h"		//include the defined header file

Package::Package()		//define the default constructor
{
	setwt(0);
	setcost(0);
}

//initialize the members

Package::Package(string sname, string rname, string saddress, string raddress, string scity, string rcity, string sstate, string rstate, string szip, string rzip, double wt, double cst)
{
	sender = sname;
	recipient = rname;
	sender_address = saddress;
	recipient_address = raddress;
	sender_city = scity;
	recipient_city = rcity;
	sender_state = sstate;
	recipient_state = rstate;
	sender_zip = szip;
	recipient_zip = rzip;

	setwt(wt);
	setcost(cst);
}

Package::~Package()		
{
	//empty body
}

//as mentioned in the header file, input and return all the sender and recipient details
string Package::gettype() const
{
	return "Regular Delivery";
}

void Package::setsender(string sname)
{
	sender = sname;
}
string Package::getsender() const
{
	return sender;
}

void Package::setsender_address(string saddress)
{
	sender_address = saddress;
}

string Package::getsender_address() const
{
	return sender_address;
}

void Package::setsender_city(string scity)
{
	sender_city = scity;
}

string Package::getsender_city() const
{
	return sender_city;
}

void Package::setsender_state(string sstate)
{
	sender_state = sstate;
}

string Package::getsender_state() const
{
	return sender_state;
}

void Package::setsender_zip(string szip)
{
	sender_zip = szip;
}

string Package::getsender_zip() const
{
	return sender_zip;
}

void Package::setrecipient(string rname)
{
	recipient = rname;
}

string Package::getrecipient() const
{
	return recipient;
}

void Package::setrecipient_address(string raddress)
{
	recipient_address = raddress;
}

string Package::getrecipient_address() const
{
	return recipient_address;
}

void Package::setrecipient_city(string rcity)
{
	recipient_city = rcity;
}

string Package::getrecipient_city() const
{
	return recipient_city;
}

void Package::setrecipient_state(string rstate)
{
	recipient_state = rstate;
}
string Package::getrecipient_state() const
{
	return recipient_state;
}

void Package::setrecipient_zip(string rzip)
{
	recipient_zip = rzip;
}

string Package::getrecipient_zip() const
{
	return recipient_zip;
}


//obtain the weight of the package in oz
void Package::setwt(double wt)
{
	weight = (wt > 0.0 ? wt : 0.0);
}

double Package::getwt() const
{
	return weight;
}

//obtain the cost per oz of the package 
void Package::setcost(double cst)
{
	cost = (cst > 0.0 ? cst : 0.0);
}

double Package::getcost() const
{
	return cost;
}

//calculate the cost of the package

double Package::calculateCost() const
{
	return weight * cost;
}