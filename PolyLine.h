/**
This class is used to model a series of connected line segments - a Polyline, which can be
used to approximate more complicated geometries
*/
#pragma once

#include <array>
#include <vector>

template<int DIM>
class Point;

template<int DIM>
class Polyline
{
public:
	Polyline(
		const std::vector<Point<DIM> >& polyLine);

	// addSegment(
	// 	const Point<DIM>& newPoint);

	// yMax() const;
	// yMin() const;
	// xMax() const;
	// xMin() const;
private:
	std::vector<Point<DIM> > internalPoints;
	std::array<double, 2 * DIM> Lim;
};