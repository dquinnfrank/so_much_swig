#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class bro_array 
{
	public:

		// Just a default constructor, nothing to see here
		bro_array();

		// What's parameterization?
		bro_array(string greet);

		// This kills the class
		~bro_array();

		// Nobody asked for this
		string say(string msg);

		// Shows all elements of the array
		void show_array(float* data, int n);

		// Shows elements of an array [0 - up_to)
		void show_array(float* data, int n, int up_to);

		// Gives the sum of all array elements
		int sum_array(float* data, int n);

	private:

		// Goes before all say messages
		string greeting;
};
