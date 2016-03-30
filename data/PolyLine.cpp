#include "Polyline.h"
#include "Point.h"

#include <iostream>

template<int DIM>
Polyline<DIM>::
Polyline() 
{
	for (unsigned int i = 0; i != mLims.size(); ++i) {
		mLims[i] = 0.0;
	}
}

template <>
Polyline<1>::
Polyline(
	const std::vector<Point<1> >& points)
{
	mInternalPoints = points;
	for (unsigned int i = 0; i != mLims.size(); ++i) {
		mLims[i] = mInternalPoints[0][i/2];
	}
	for (auto point : mInternalPoints) {
		if (point.x() < mLims[0]) { mLims[0] = point.x(); }
		if (point.x() > mLims[1]) { mLims[1] = point.x(); }
	}
}

template <>
Polyline<2>::
Polyline(
	const std::vector<Point<2> >& points)
{
	mInternalPoints = points;
	for (unsigned int i = 0; i != mLims.size(); ++i) {
		mLims[i] = mInternalPoints[0][i/2];
	}
	for (auto point : mInternalPoints) {
		if (point.x() < mLims[0]) { mLims[0] = point.x(); }
		if (point.x() > mLims[1]) { mLims[1] = point.x(); }
		if (point.y() < mLims[2]) { mLims[2] = point.y(); }
		if (point.y() > mLims[3]) { mLims[3] = point.y(); }
	}
}

template <>
Polyline<3>::
Polyline(
	const std::vector<Point<3> >& points)
{
	mInternalPoints = points;
	for (unsigned int i = 0; i != mLims.size(); ++i) {
		mLims[i] = mInternalPoints[0][i/2];
	}
	for (auto point : mInternalPoints) {
		if (point.x() < mLims[0]) { mLims[0] = point.x(); }
		if (point.x() > mLims[1]) { mLims[1] = point.x(); }
		if (point.y() < mLims[2]) { mLims[2] = point.y(); }
		if (point.y() > mLims[3]) { mLims[3] = point.y(); }
		if (point.z() < mLims[4]) { mLims[4] = point.z(); }
		if (point.z() > mLims[5]) { mLims[5] = point.z(); }
	}
}

template<int DIM>
double
Polyline<DIM>::
xMin() const
{
	return mLims[0];
}

template<int DIM>
double
Polyline<DIM>::
xMax() const
{
	return mLims[1];
}

template<int DIM>
std::vector<Point<DIM> >
Polyline<DIM>::
getPoints() const
{
	return mInternalPoints;
}

template<int DIM>
void
Polyline<DIM>::
addSegment(
	const Point<DIM>& newPoint) 
{
	if (mInternalPoints.empty()) {
		for (unsigned int i = 0; i != mLims.size(); ++i) {
			mLims[i] = newPoint[i/2];
		}
	}
	else {
		for (unsigned int i = 0; i != mLims.size()/2; ++i) {
			if (newPoint[i] < mLims[2 * i]) { mLims[2 * i] = newPoint[i]; }
			if (newPoint[i] > mLims[2 * i + 1]) { mLims[2 * i + 1] = newPoint[i]; }
		}
	}
	mInternalPoints.push_back(newPoint);
}

template<int DIM>
Point<DIM>
Polyline<DIM>::
operator[] (const unsigned int& i) const
{
	if (i > mInternalPoints.size() - 1) {
		throw std::domain_error("Invalid index - larger than the size of this polyline");
	}
	else {
		return mInternalPoints[i];
	}
}

template class Polyline<1>;
template class Polyline<2>;
template class Polyline<3>;