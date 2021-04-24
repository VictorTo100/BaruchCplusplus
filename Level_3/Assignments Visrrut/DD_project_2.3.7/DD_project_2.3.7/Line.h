
#ifndef Line_H
#define Line_H

#include "Point.h"
#include <iostream>
using namespace std;

class Line
{
private:

	Point startPoint;	// e1
	Point endPoint;		// e2

public:

	// Constructors
	Line();									// Line with both end Points at the origin
	Line(const Point& p1, const Point& p2);	// Line with end Points [p1, p2]
	Line(const Line& l); 				  // Copy constructor
	~Line();							// Destructor

	// Accesssing functions
	Point start() const;
	Point end() const;

	// Modifiers
	void start(const Point& pt) { startPoint = pt; }					// Set Point pt1
	void end(const Point& pt) { endPoint = pt; }						// Set Point pt2

	double Length() const;

	// ToString function to print the description of the Point object
	std::string ToString() const;

};

inline Point Line::start() const { return startPoint; }
inline Point Line::end() const { return endPoint; }

#endif

