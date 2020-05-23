/*Name: Pranav Shivkumar
Title: main.cpp*/

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>

using namespace std;

//include all defined header files, with the class declaration
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

double virtual_pointer(Package&, int i);		//function that loops throughout the vector of pointers to the Package objects

double virtual_pointer(Package& base, int i)
{
	cout << "Sender:" << endl;
	cout << base.getsender() << endl;		//returns sender name
	cout << base.getsender_address() << endl;		
	cout << base.getsender_city() << ", " << base.getsender_state() << " " << base.getsender_zip() << endl;	
	cout << endl;		//returns sender address in the mailinng label format

	cout << "Recipient:" << endl;
	cout << base.getrecipient() << endl;		//returns recipient name
	cout << base.getrecipient_address() << endl;
	cout << base.getrecipient_city() << ", " << base.getrecipient_state() << " " << base.getrecipient_zip() << endl;
	cout << endl;		//returns recipient's address in the mailinng label format
	
	cout << "Weight of package: " << base.getwt() << " ounces" << endl;		//display weight in oz
	cout << "Type of Delivery: " << base.gettype() << endl;			//display the type of delivery
	cout << "Cost of package: $" << fixed << setprecision(2) << base.calculateCost() << endl << endl;		//display the cost

	return base.calculateCost();		//return the cost of to the main function
}

int main()
{
	vector<Package*> pack(3);		//creating a vector of class Package pointers

	//calling the constructors of the classes
	Package p("John Doe", "David Mills", "34510 Alberta Terrace", "10 Commercial Avenue", "Fremont", "New Brunswick", "CA", "NJ", "94555", "08901", 10.5, 0.75);
	TwoDayPackage t("Griffin Thompson", "Janet Thompson", "24 Labrador Drive", "19 Union Drive", "East Lansing", "Newark", "MI", "NY", "10023", "27685", 11.75, 0.75, 5);
	OvernightPackage o("Monica Dunn", "Pauline Li", "10 Sunnyside Shore", "2 Norbridge Drive", "Malibu", "Princeton", "CA", "NJ", "94325", "08675", 8.6, 0.75, 6);

	//aiming the pointers at the base and derived class objects
	pack[0] = &p;
	pack[1] = &t;
	pack[2] = &o;

	//start the program
	cout << "Package Delivery Services Program" << endl << endl;
	cout << "Cost per ounce for a package: $" << fixed << setprecision(2) << p.getcost() << "/ounce." << endl;
	cout << "Additional cost for two day delivery: $" << fixed << setprecision(2) << t.getfee() << "/ounce." << endl;
	cout << "Additional cost for overnight delivery: $" << fixed << setprecision(2) << o.getfee() << "/ounce." << endl;
	cout << endl;

	double sum = 0;		//for the total cost of all packages

	//loop around the packages and process, while displayng the required results
	for (unsigned int i = 0; i < pack.size(); i++)
	{
		cout << "Package " << i + 1 << ":" << endl << endl;
		sum += virtual_pointer(*pack[i], i);
	}

	cout << "Total cost for all the packages is: " << fixed << setprecision(2) << sum << endl << endl;		//total cost

	return 0;
}