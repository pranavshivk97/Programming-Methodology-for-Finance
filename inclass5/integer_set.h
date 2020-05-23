// IntegerSet.h
// Header file for class IntegerSet

#ifndef INTEGER_SET_H
#define INTEGER_SET_H

class IntegerSet
{
public:
	IntegerSet(); // constructor
	
	/* Write a member funcion prototype for UnionOfSets */
	void UnionOfSets(IntegerSet a, IntegerSet b);

	//member function for IntersectionOfSets()
	void IntersectionOfSets(IntegerSet a, IntegerSet b);

	void inputSet(); // read values from user

	void printSet() const;

private:
	int set[101] = { 0 }; // range of 0 - 100

	// determines a valid entry to the set
	int validEntry(int x) const
	{
		return (x >= 0 && x <= 100);
	} // end function validEntry
};

#endif