/*Author: Vishrut Talekar; Nov 2020
*/

/*The Purpose of this file is to implement the Visitor class
* defined in Visitor class header file
*/
#include<iostream>
#include "Visitor.h"
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace CAD
	{
		/* Default Constructor
		*/
		Visitor::Visitor() :m_dx(0), m_dy(0)
		{
			cout << "Default Constructor of Visitor is called\n";
		}
		
		/*Custom  Constructor
		*/
		Visitor::Visitor(double newdx, double newdy) :m_dx(newdx), m_dy(newdy)
		{
			cout << "Parameter Constructor of Visitor is called\n";
		}

		/*Parameter constructor
		*/
		Visitor::Visitor(const Visitor& source_v) : m_dx(source_v.m_dx), m_dy(source_v.m_dy)
		{
			cout << "Copy Constructor of Visitor is called\n";
		}
		/*Destructor
		*/
		Visitor::~Visitor()
		{
			cout << " Destructor of Visitor is called\n";
		}
		/*Operator overloading
		* Assignment operator
		*/
		Visitor& Visitor::operator = (const Visitor& source_v)
		{
			/*arguments: Line object as const reference
			* return: reference to the source Line object
			*/

			/* Condition to avoid assigning to itself
			*/
			if (this == &source_v)
			{
				return *this;
			}
			else
			{
				m_dx = source_v.m_dx;
				m_dy = source_v.m_dy;

				return *this;
			}

		}

		/*create an operator () that changes the coordinates of the shape
		* Point, Line, Circle
		*/
		void Visitor::operator () (Point& p) const
		{
			/*Change the coordinates of the shape
			*/
			p.X(p.X() + m_dx);
			p.Y(p.Y() + m_dy);
		}

		void Visitor::operator () (Line& l) const
		{
			/*Get Point coordinate from Line object
			*/
			Point start_p = l.start();
			Point end_p = l.end();
			/*Change the coordinates
			* Starting point of 
			*/
			start_p.X(start_p.X() + m_dx);
			start_p.Y(start_p.Y() + m_dy);

			end_p.X(end_p.X() + m_dx);
			end_p.Y(end_p.Y() + m_dy);

			/*Change the coordinates of the shape
			*/
			l.start(start_p);
			l.end(end_p);
		}

		void Visitor::operator () (Circle& c) const
		{
			/*Get center coordinate from Circle object
			*/
			Point m_center  = c.CenterPoint();
			
			/*Change the coordinates
			* Starting point of
			*/
			m_center.X(m_center.X() + m_dx);
			m_center.Y(m_center.Y() + m_dy);

			/*Change the coordinates of the shape
			*/
			c.CenterPoint(m_center);
		}

	}

}
