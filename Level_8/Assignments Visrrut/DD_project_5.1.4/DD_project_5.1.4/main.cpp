/*Author: Vishrut Talekar; 2020
*/

/* The purpose of the file is to experiment with the Random Number Generator of Boost
* 
* 
*/

#include <boost/random.hpp> // Convenience header file
#include <iostream>
#include <ctime>			// std::time
#include <map>
using namespace std;


int main()
{

	// Throwing dice.
	 // Mersenne Twister.
	boost::random::mt19937 myRng;
	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));
	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1, 6);
	
	//We now create a map that holds the frequency of each outcome : 
	
	map<int, long> statistics; // Structure to hold outcome + frequencies

	int outcome; // Current outcome
	
	//A typical outcome is generated as follows :

	statistics[1] = 0;
	statistics[2] = 0;
	statistics[3] = 0;
	statistics[4] = 0;
	statistics[5] = 0;
	statistics[6] = 0;

	int trials = 1000000;

	for (int i = 1; i <= trials; i++) 
	{
		outcome = six(myRng);  //This will generate a number in the range[1, 6].
		statistics[outcome] += 1;
	}

	for (int i = 1; i <= 6; i++)
	{

		// **Changed some wordings from the question**
		cout << " For outcome " << i << "'th the frequency is: " <<  ((float)statistics[i]/trials)*100<<"%" << "\n" << endl;
		cout << " The count for " << i << "'th outcome is: " << statistics[i] << "\n" << endl;
	}
	
	return 0;
}