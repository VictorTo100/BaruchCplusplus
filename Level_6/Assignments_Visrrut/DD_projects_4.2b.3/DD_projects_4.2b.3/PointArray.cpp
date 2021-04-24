/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of this file is implement the PointArray class defined in header file PointArray
*/
#include "PointArray.h"
#include "Point.h"
#include "Array.h"

using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		/*Default Constructor
		*/
		PointArray::PointArray() : Array()
		{
			cout << "Default Constructor of PointArray is called\n " << endl;
		}
		/*Default Constructor
		*/
		PointArray::PointArray(int size) : Array(size)
		{
			cout << "Custom Constructor of PointArray is called\n " << endl;
		}
		/*Copy Constructor
		*/
		PointArray::PointArray(const PointArray& ptarr) : Array(ptarr)
		{
			cout << "Copy Constructor of Point Array is called\n " << endl;
		}
		/*Destructor
		*/
		PointArray::~PointArray()
		{
			cout << "Destructor of PointArray is called\n" << endl;
		}
		/*Operator Overloading
		* Assignment Operator
		*/
		PointArray& PointArray::operator = (const PointArray& ptarr)
		{
			if (this == &ptarr)
			{
				return *this;
			}
			else
			{
				/*Call to the assignment operator of the base class
				*/
				Array<CAD::Point>::operator=(ptarr);

				return *this;

				cout << "Assignment Operator of Point Array is called\n " << endl;
			}	
		}
	/*https://quantnet.com/threads/question-on-length-in-pointarray.44176/
	* https://quantnet.com/threads/exercise-3.10238/page-8#post-272323
	* 
	*/
		/*Calculate the total length between contiguous Points in the PointArray; i.e. P1 to P2 + P2 to P3 so on and so forth
		*/ 

		double PointArray::Length() const
		{
			/*Declare and initialise variables for 
			* storing Length
			*/
			double length = 0.0;
			/*Declare temporary PointArray
			*/
			PointArray ptarr(*this);
			for (int i = 0; i < ptarr.Size()-1; i++)
			{
				length += ptarr[i].Distance(ptarr[i + 1]);
			}
			return length;
		}
	}	
}