#include<iostream>

using namespace std;

//include all the necessary defined header files

#include "circle.h"
#include "triangle.h"
#include "sphere.h"
#include "tetrahedron.h"

int main()
{
	int val;
	int x = 0, y = 0, z = 0;
	double rad = 0.0, len = 0.0;

	//instantiating the objects from the classes

	circle c;
	triangle t;
	sphere s;
	tetrahedron T;

	while (1)		//run the menu forever until 0
	{
		cout << "Please choose a shape or 0 to exit: " << endl;
		cout << "1. Circle" << endl;
		cout << "2. Triangle" << endl;
		cout << "3. Sphere" << endl;
		cout << "4. Regular Tetrahedron" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> val;

		switch (val)
		{
		case 1: cout << "You have chosen the circle." << endl;
			cout << endl;

			c.setx(x);		//call all member functions from class circle
			c.getx();
			c.sety(y);
			c.gety();

			cout << "Enter the radius of the circle: ";
			cin >> rad;
			c.setrad(rad);
			c.getrad();

			c.print();				//prints the center and area of the circle
		
			break;

		case 2: cout << "You have chosen the triangle." << endl;
			cout << endl; 

			t.setx(x);		//call all member functions of the clas triangle
			t.getx();
			t.sety(y);
			t.gety();

			cout << "Enter the length of the edge of the triangle: ";
			cin >> len;
			t.setlen(len);
			t.getlen();

			t.print();			//prints the center and area of the triangle

			break;

		case 3: cout << "You have chosen the sphere." << endl;
			cout << endl; 

			s.setx(x);		//call all member functions of the class sphere
			s.getx();
			s.sety(y);
			s.gety();
			s.setz(z);
			s.getz();


			cout << "Enter the radius of the sphere: ";
			cin >> rad;
			s.setrad(rad);
			s.getrad();

			s.print();			//prints the center, area and volume of the sphere

			break;

		case 4:cout << "You have chosen the tetrahedron." << endl;
			cout << endl;

			T.setx(x);			//call all member functions of the class tetrahedron
			T.getx();
			T.sety(y);
			T.gety();
			T.setz(z);
			T.getz();

			cout << "Enter the length of the edge of the tetrahedron: ";
			cin >> len;
			T.setlen(len);
			T.getlen();

			T.print();				//prints the center, area and volume of the tetrahedron
			break;

		case 0: exit(0);		//case which exits from the menu and stops running the program, when 0 is pressed
			break;

		default: cout << "Invalid option. Please choose again." << endl;		//if any other key is pressed
			break;
		}
	}
}