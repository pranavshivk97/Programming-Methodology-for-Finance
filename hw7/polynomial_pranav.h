#ifndef polynomial_pranav_h
#define polynomial_pranav_h

#include<iostream>

using namespace std;
class polynomial
{
	static const int max_size = 13;
	friend ostream& operator<<(ostream&, const polynomial&);	//overloading output operator as a friend function
	
public:
	polynomial();	//constructor
	~polynomial();	//declaration of destructor

	void input();		//function to input the terms of the polynomial
	void setnterm(int);		//member function to set number of input terms
	int getnterm() const;		//member function to return number of input terms

	//overloading all operators as member functions
	polynomial operator+(const polynomial&) const;
	polynomial operator-(const polynomial&) const;
	polynomial operator*(const polynomial&) const;
	polynomial operator=(const polynomial&);
	polynomial operator+=(const polynomial&) const;
	polynomial operator-=(const polynomial&) const;
	polynomial operator*=(const polynomial&) const;

private:
	int nterms;
	int poly[max_size];		//array to hold maximumm number of terms in the polynomial 
	bool isEmpty(const polynomial&) const;		//function to check if the polynomial is empty or not
};

#endif