/*
Author: Rohan Ramasamy
Data: 31/03/16
*/

#include "GeometryOps_2.h"
#include "../data/Vector.h"
#include "../data/Point.h"

#include <iostream>
#include <vector>
#include <set>

namespace compGeom {

Vector<3>
GeometryOps_2::
convert2Dto3D(
	const Vector<DIM>& twoDVector)
{
	Vector<3> threeDVector(twoDVector.x(), twoDVector.y(), 0.0);
	return threeDVector;
}

bool
GeometryOps_2::
compareHull(
	const Point<DIM>& pointOne,
	const Point<DIM>& pointTwo)
{
	if (pointOne.x() < pointTwo.x()) {
		return true;
	}
	else if ((pointOne.x() == pointTwo.x()) && (pointOne.y() <= pointTwo.y())) {
		return true;
	}
	else {
		return false;
	}
}

bool
GeometryOps_2::
compareIntersection(
	const Point<DIM>& pointOne,
	const Point<DIM>& pointTwo)
{
	if (pointOne.y() > pointTwo.y()) {
		return true;
	}
	else if ((pointOne.y() == pointTwo.y()) && (pointOne.x() <= pointTwo.x())) {
		return true;
	}
	else {
		return false;
	}
}

std::vector<Point<2> >
GeometryOps_2::
convexHull(
	std::vector<Point<DIM> >& unsortedPoints)
{
	// Sort points by x location
	std::sort(unsortedPoints.begin(), unsortedPoints.end(), GeometryOps_2::compareHull);

	// Generate Upper Hull
	std::vector<Point<DIM> > upperHull;
	upperHull.push_back(*unsortedPoints.begin());
	upperHull.push_back(*(unsortedPoints.begin() + 1));
	Point<DIM> prevPoint  = *(unsortedPoints.begin() + 1);
	Point<DIM> newPoint;
	Vector<DIM> prevVector = prevPoint - upperHull[0];
	Vector<DIM> newVector;
	for (auto iter = unsortedPoints.begin() + 2; iter != unsortedPoints.end(); ++iter) {
		upperHull.push_back(*iter);
		newPoint = *iter;
		newVector = newPoint - prevPoint;
		while (prevVector.cross(newVector) >= 0 && upperHull.size() > 2) {
			upperHull.erase(upperHull.end() - 2);
			prevPoint = *(upperHull.rbegin() + 1);
			prevVector = prevPoint - *(upperHull.rbegin() + 2);
			newVector = newPoint - prevPoint;
		}
		prevVector = newPoint - prevPoint;
		prevPoint = newPoint;
	}
	upperHull.erase(upperHull.end() - 1);

	// // Generate Lower Hull
	std::vector<Point<DIM> > lowerHull;
	lowerHull.push_back(*unsortedPoints.rbegin());
	lowerHull.push_back(*(unsortedPoints.rbegin() + 1));
	prevPoint = *(unsortedPoints.rbegin() + 1);
	prevVector = prevPoint - lowerHull[0];
	for (auto iter = unsortedPoints.rbegin() + 2; iter != unsortedPoints.rend(); ++iter) {
		
		lowerHull.push_back(*iter);
		newPoint = *iter;
		newVector = newPoint - prevPoint;

		while (prevVector.cross(newVector) >= 0 && lowerHull.size() > 2) {
			lowerHull.erase(lowerHull.end() - 2);
			
			prevPoint = *(lowerHull.rbegin() + 1);
			prevVector = prevPoint - *(lowerHull.rbegin() + 2);
			newVector = newPoint - prevPoint;
		}
		prevVector = newPoint - prevPoint;
		prevPoint = newPoint;		
	}
	lowerHull.erase(lowerHull.end() - 1);

	// join two halves of convex hull
	for (auto iter = lowerHull.begin(); iter != lowerHull.end(); ++iter) {
		upperHull.push_back(*iter);
	}

	// return full convex hull
	return upperHull;
}

// std::vector<Point<2> >
// GeometryOps_2::
// findIntersections(
// 		std::vector<LineSegment<DIM> > segments)
// {
// 	std::set<std::pair<Point<DIM>, LineSegment<DIM> >, compareIntersection> events;
// 	// for (auto iter = segments.begin(); iter != segments.end(); ++iter) {
// 	// 	Point<DIM> pointOne = iter->startPoint();
// 	// 	Point<DIM> pointTwo = iter->endPoint();
// 	// 	if (compareIntersection(pointOne, pointTwo)) {
// 	// 		events.insert(std::pair<Point<DIM>, LineSegment<DIM> >(pointOne, *iter));
// 	// 		events.insert(std::pair<Point<DIM>, LineSegment<DIM> >(pointTwo));
// 	// 	}
// 	// 	else {
// 	// 		events.insert(std::pair<Point<DIM>, LineSegment<DIM> >(pointTwo, *iter));
// 	// 		events.insert(std::pair<Point<DIM>, LineSegment<DIM> >(pointOne));
// 	// 	}
// 	// }

// 	std::vector<Point<DIM> > intersections;
	
// 	return intersections;
// }

}
