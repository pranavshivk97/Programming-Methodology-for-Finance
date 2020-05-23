/*Name: Pranav Shivkumar
Title: In Class 7 (STL)*/

#include<iostream>
#include<iomanip>
#include<iterator>
#include<numeric>
#include<deque>
#include<vector>
#include<algorithm>

bool great(int);
double calchalf(int);
int main()
{
	const int size = 10;
	std::deque<int> values;		//declaring a double ended queue of integers
	std::ostream_iterator<int> out(std::cout, " ");

	//Inserting all elements one after another in the deque
	values.push_back(3);
	values.push_back(4);
	values.push_back(6);
	values.push_back(2);
	values.push_back(9);
	values.push_back(1);
	values.push_back(5);
	values.push_back(0);
	values.push_back(7);
	values.push_back(8);
	
	std::cout << "The values are: ";
	std::copy(values.begin(), values.end(), out);
	std::cout << std::endl;

	//removing the element 7 from the deque
	values.erase(values.begin() + 8);

	std::cout << "After removing 7, the deque is: ";
	std::copy(values.begin(), values.end(), out);
	std::cout << std::endl;

	//replacing values greater than 6 in the deque with 10
	std::replace_if(values.begin(), values.end(), great, 10);

	std::cout << "After replacing with 10s,  the values are: ";
	std::copy(values.begin(), values.end(), out);
	std::cout << std::endl;

	//sum of all elements in the deque
	int sum = accumulate(values.begin(), values.end(), 0);
	std::cout << "The sum of elements in the deque is: " << sum << std::endl;
	values.push_front(sum);

	//count number of elements greater than 6
	int res = std::count_if(values.begin(), values.end(), great);
	std::cout << "The number of elements greater than 6 in the deque is: " << res;
	std::cout << std::endl;

	//output half of every element
	std::vector<double> half(size);
	std::cout << "The half of every element in the deque is: " << std::endl;
	std::transform(values.begin(), values.end(), half.begin(), calchalf);

	std::copy(half.begin(), half.end(), out);
	std::cout << std::endl;

	//sort
	std::sort(values.begin(), values.end());
	std::cout << "Sorting: " << std::endl;
	std::copy(values.begin(), values.end(), out);
	std::cout << std::endl;

	//locate 6
	std::vector<int>::iterator loc;
	loc	= std::find(values.begin(), values.end(), 6);
	if (loc != values.end())
		std::cout << "\n\nFound 16 at location " << (loc - values.begin());
	else
		std::cout << "\n\n16 not found";



}

bool great(int x)
{
	return x > 6;
}

double calchalf(int y)
{
	return y / 2;
}