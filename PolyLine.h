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
	// Constructors
	Polyline();

	Polyline(
		const std::vector<Point<DIM> >& polyLine);

	// Limits
	double
	xMin() const;

	double
	xMax() const;

	template<int D = DIM, typename = typename std::enable_if<(D >= 2)>::type >
	double
	yMin() const
	{
		return mLims[2];
	}

	template<int D = DIM, typename = typename std::enable_if<(D >= 2)>::type >
	double
	yMax() const
	{
		return mLims[3];
	}

	template<int D = DIM, typename = typename std::enable_if<(D == 3)>::type >
	double
	zMin() const
	{
		return mLims[4];
	}

	template<int D = DIM, typename = typename std::enable_if<(D == 3)>::type >
	double
	zMax() const
	{
		return mLims[5];
	}

	// Internal Point Functions
	std::vector<Point<DIM> >
	getPoints() const;

	void
	addSegment(
		const Point<DIM>& newPoint);

	// Operators
	Point<DIM>
	operator[] (const int& i) const;

private:
	std::vector<Point<DIM> > mInternalPoints;
	std::array<double, 2 * DIM> mLims;
};