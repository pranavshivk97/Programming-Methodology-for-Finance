#ifndef sphere_h
#define sphere_h

#include "threed.h"

class sphere : public ThreeDimensionalShape			//deriving public class sphere from ThreeDimensionalShape
{
public:
	sphere();			//default constructor
	void setrad(double);		//member funtion to input the radius
	double getrad() const;			//member function to return the value from user

	double getarea() const;		//surface area 
	double getvol() const;		//volume

	void print() const;			//print the values

private:
	double rad;		//private member for radius
};
#endif
