#include "so_much_swig.h"

bro_array::bro_array()
{
	// The most basic of greetings
	greeting = "Bro";

	// Hello, bro
	cout << say("default af") << endl;
}

bro_array::bro_array(string greet)
{
	// Set the new, original greeting
	greeting = greet;

	cout << say("fresh") << endl;
}

bro_array::~bro_array()
{
	cout << say("you've killed me") << endl;
}

string bro_array::say(string message)
{
	return greeting + ", " + message;
}

void bro_array::show_array(float* data, int n)
{
	// Just call the other function
	show_array(data, n, n);
}

void bro_array::show_array(float* data, int n, int upto)
{

	// Check for dumb
	if (upto > n)
	{
		throw range_error(say("that is too big (that's what she said)"));
	}

	else if(upto < 0)
	{
		throw range_error(say("I can't get high off of this"));
	}

	// Show array elements
	for(int i = 0; i < upto; i++)
	{
		cout << data[i] << endl;
	}
}

int bro_array::sum_array(float* data, int n)
{
	// It's a sum loop, big suprise
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += data[i];
	}

	return total;
}

int main()
{
	// Basic bro
	bro_array bro1 = bro_array();

	// Another bro
	bro_array bro2 = bro_array("Dude");

	// An array, just what all bros love
	float arr[] = {1,2,3,4,5};
	int size = 5;

	cout << "\nTests, high five bro!" << endl;

	cout << "\nbro1 says:" << endl;
	cout << bro1.say("sup") << endl;

	cout << "\nbro2 says:" << endl;
	cout << bro2.say("sup brah") << endl;

	cout << "\nShowing everything" << endl;
	bro2.show_array(arr, size);

	cout << "\nTopless" << endl;
	bro2.show_array(arr, size, 3);

	cout << "\nToo big" << endl;
	try
	{
		bro2.show_array(arr, size, 6);
	}
	catch(range_error& e)
	{
		cout << e.what() << endl;
	}

	cout << "\nToo small" << endl;
	try
	{
		bro2.show_array(arr, size, -1);
	}
	catch(range_error& e)
	{
		cout << e.what() << endl;
	}

	cout << "\nAddition!" << endl;
	cout << bro2.sum_array(arr, size) << endl;

	return 0;
}
