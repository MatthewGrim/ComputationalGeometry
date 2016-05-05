/*
Author: Rohan Ramasamy
Data: 31/03/16

Comments: Class used to perform geometric operations on the fundamental geometric
data structures
*/
#pragma once

#include <vector>

#include "../data/Vector_fwd.h"
#include "../data/Point_fwd.h"
#include "../data/LineSegment.h"


namespace compGeom {

class GeometryOps_2
{
	static const int DIM = 2;
public:
	GeometryOps_2();

	~GeometryOps_2();

	// Convert a 2D Vector to 3D Vector with 0 z component
	static
	Vector<3>
	convert2Dto3D(
		const Vector<DIM>& twoDVector);

	// Lexicographic comparison of 2D points for convex hull algortithm
	static
	bool
	compareHull(
		const Point<DIM>& pointOne,
		const Point<DIM>& pointTwo);

	// Comparison of 2D points for line intersection algorithm - high y values are first,
	// followed by low x values so that the first points are in the top left of the domain
	static
	bool
	compareIntersection(
		const Point<DIM>& pointOne,
		const Point<DIM>& pointTwo);

	// Find the convex hull of a set of points -
	// Repeated Points and Points in Parallel are included
	static
	std::vector<Point<DIM> >
	convexHull(
		std::vector<Point<DIM> >& unsortedPoints);

	// Find the intersection of a set of lines
	// static
	// std::vector<Point<DIM> >
	// findIntersections(
	// 	std::vector<LineSegment<DIM> > segments);

};

}