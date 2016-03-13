#include "GeometryOps_2.h"
#include "Vector.h"
#include "Point.h"

#include <iostream>
#include <vector>

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
compare(
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

std::vector<Point<2> >
GeometryOps_2::
convexHull(
	std::vector<Point<DIM> >& unsortedPoints)
{
	// Sort points by x location
	std::sort(unsortedPoints.begin(), unsortedPoints.end(), GeometryOps_2::compare);
	// std::cout << "Sorted: " << std::endl;
	// for (auto iter = unsortedPoints.begin(); iter != unsortedPoints.end(); ++iter) {
	// 	std::cout << iter->x() << ", " << iter->y() << std::endl;
	// }

	// Generate Upper Hull
	std::vector<Point<DIM> > upperHull;
	upperHull.push_back(*unsortedPoints.begin());
	upperHull.push_back(*(unsortedPoints.begin() + 1));
	Point<DIM> prevPoint  = *(unsortedPoints.begin() + 1);
	Point<DIM> newPoint;
	Vector<DIM> prevVector = prevPoint - upperHull[0];
	Vector<DIM> newVector;
	for (auto iter = unsortedPoints.begin() + 2; iter != unsortedPoints.end(); ++iter) {
		// std::cout << "Upper Hull:" << std::endl;
		// for (auto iter = upperHull.begin(); iter != upperHull.end(); ++iter) {
		// 	std::cout << iter->x() << ", " << iter->y() << std::endl;
		// }	
		upperHull.push_back(*iter);
		newPoint = *iter;
		newVector = newPoint - prevPoint;
		// std::cout << "New Point: " << newPoint.x() << ", " << newPoint.y() << std::endl;
		// std::cout << "Cross Product: " << prevVector.cross(newVector) << std::endl;
		while (prevVector.cross(newVector) >= 0 && upperHull.size() > 2) {
			// std::cout << "Erased Point: " << prevPoint.x() << ", " << prevPoint.y() << std::endl; 
			upperHull.erase(upperHull.end() - 2);
			prevPoint = *(upperHull.rbegin() + 1);
			prevVector = prevPoint - *(upperHull.rbegin() + 2);
			newVector = newPoint - prevPoint;
		}
		prevVector = newPoint - prevPoint;
		prevPoint = newPoint;
	}
	upperHull.erase(upperHull.end() - 1);

	// std::cout << "Upper Hull:" << std::endl;
	// for (auto iter = upperHull.begin(); iter != upperHull.end(); ++iter) {
	// 	std::cout << iter->x() << ", " << iter->y() << std::endl;
	// }

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

		// std::cout << "Lower Hull:" << std::endl;
		// for (auto iter = lowerHull.begin(); iter != lowerHull.end(); ++iter) {
		// 	std::cout << iter->x() << ", " << iter->y() << std::endl;
		// }
		// std::cout << "New Point: " << newPoint.x() << ", " << newPoint.y() << std::endl;
		// std::cout << "Cross Product: " << prevVector.cross(newVector) << std::endl;
		while (prevVector.cross(newVector) >= 0 && lowerHull.size() > 2) {
			// std::cout << "Erased Point: " << prevPoint.x() << ", " << prevPoint.y() << std::endl; 
			lowerHull.erase(lowerHull.end() - 2);
			// std::cout << "Size: " << lowerHull.size() << std::endl;
			
			prevPoint = *(lowerHull.rbegin() + 1);
			// std::cout << "Prev Point: " << prevPoint.x() << ", " << prevPoint.y() << std::endl; 
			prevVector = prevPoint - *(lowerHull.rbegin() + 2);
			newVector = newPoint - prevPoint;
			// std::cout << "Prev Vector: " << prevVector.x() << ", " << prevVector.y() << std::endl;
			// std::cout << "New Vector:  " << newVector.x() << ", " << newVector.y() << std::endl;
			// std::cout << "Cross Product: " << prevVector.cross(newVector) << std::endl;
		}
		prevVector = newPoint - prevPoint;
		prevPoint = newPoint;		
	}
	lowerHull.erase(lowerHull.end() - 1);

	// std::cout << "Lower Hull:" << std::endl;
	// for (auto iter = lowerHull.begin(); iter != lowerHull.end(); ++iter) {
	// 	std::cout << iter->x() << ", " << iter->y() << std::endl;
	// }

	// join two halves of convex hull
	for (auto iter = lowerHull.begin(); iter != lowerHull.end(); ++iter) {
		upperHull.push_back(*iter);
	}

	// std::cout << "Upper Hull:" << std::endl;
	// for (auto iter = upperHull.begin(); iter != upperHull.end(); ++iter) {
	// 	std::cout << iter->x() << ", " << iter->y() << std::endl;
	// }

	// return full convex hull
	return upperHull;
}
