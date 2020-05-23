/*Name: Pranav Shivkumar
Title: Shapes - Base Class Declaration*/

#ifndef shape_h		//base class 'shape' header file 
#define shape_h

class shape
{
public:
	shape();				//default constructor

	void setx(int);			//set x coordinate
	int getx() const;		//return x coordinate from the coordinate pair
	void sety(int);			//set y coordinate
	int gety() const;		//get y coordinate from the coordinate pair
	void setz(int);			//set z coordinate
	int getz() const;		//get z coordinate from the coordinate pair

private:
	int x, y, z;			//private variables for the coordinates 
};

#endif