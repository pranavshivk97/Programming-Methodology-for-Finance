#ifndef tetrahedron_h
#define tetrahedron_h

#include "threed.h"

class tetrahedron : public ThreeDimensionalShape			//deriving public class tetrahedron from the class ThreeDimensionalShape
{
public:
	tetrahedron();				//default constructor
	void setlen(double);			//member function to input the length
	double getlen() const;			//member function to return the length

	double getarea() const;				//member function to calculate the surface area
	double getvol() const;				//member function to calculate the volume 

	void print() const;				//print the resulting values

private:
	double len;			//private member function for length
};

#endif