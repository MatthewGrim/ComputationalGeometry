/* 
Class used to perform geometric operations on the fundamental geometric
data structures
*/
#pragma once

#include <vector>

template<int DIM>
class Vector;

template<int DIM>
class Point;

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
		const Vector<2>& twoDVector);

	// Lexicographic comparison of 2D points
	static
	bool
	compare(
		const Point<DIM>& pointOne,
		const Point<DIM>& pointTwo);

	// Find the convex hull of a set of points -
	// Repeated Points and Points in Parallel are included
	static
	std::vector<Point<2> >
	convexHull(
		std::vector<Point<2> >& unsortedPoints);

};