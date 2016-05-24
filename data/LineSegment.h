/*
Author: Rohan Ramasamy
Data: 05/05/16

Comments: This class is used to model a series of connected line segments - a Polyline, which can be
used to approximate more complicated geometries
*/

#pragma once

#include <utility>

#include "Point.h"

namespace compGeom {

template<int DIM>
class LineSegment
{
public:
	LineSegment(const Point<DIM>& pointOne,
		        const Point<DIM>& pointTwo)
	{
		mEndPoints.first = pointOne;
		mEndPoints.second = pointTwo;
	}

	inline
	Point<DIM>
	startPoint() const { return mEndPoints.first; }

	inline
	Point<DIM>
	endPoint() const { return mEndPoints.second; }

	inline
	std::pair<Point<DIM>, Point<DIM> >
	getPoints() const { return mEndPoints; }
private:
	std::pair<Point<DIM>, Point<DIM> > mEndPoints;
};

template<int DIM>
class LineSegmentLessThan :
    public std::binary_function<LineSegment<DIM>, LineSegment<DIM>, bool>
{
	bool operator() (
		const LineSegment<DIM>& lhs,
		const LineSegment<DIM>& rhs) const
	{
		return !(lhs == rhs) && (lhs < rhs);
	}
};

}