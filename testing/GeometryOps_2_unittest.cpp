/*
Author: Rohan Ramasamy
Data: 31/03/16
*/

#include "gtest/gtest.h"
#include "../algo/GeometryOps_2.h"
#include "../data/Vector.h"
#include "../data/Point.h"

namespace compGeom {

class GeometryOps_2Test : public ::testing::Test { public: static const int DIM = 2; };

TEST_F(GeometryOps_2Test, conversion2Dto3D)
{
	Vector<DIM> TwoDVector(1.0, 2.0);

	Vector<3> threeDVector = GeometryOps_2::convert2Dto3D(TwoDVector);

	EXPECT_EQ(1.0, threeDVector.x());
	EXPECT_EQ(2.0, threeDVector.y());
	EXPECT_EQ(0.0, threeDVector.z());
}


TEST_F(GeometryOps_2Test, compareHull) 
{
	Point<DIM> pointOne(1.0, 5.0);
	Point<DIM> pointTwo(2.0, 7.0);
	Point<DIM> pointThree(1.0, 7.0);

	EXPECT_TRUE(GeometryOps_2::compareHull(pointOne, pointTwo));		// xOne < x
	EXPECT_TRUE(GeometryOps_2::compareHull(pointOne, pointThree));		// xOne == x, yOne < y
	EXPECT_FALSE(GeometryOps_2::compareHull(pointTwo, pointOne));		// Opposite
	EXPECT_FALSE(GeometryOps_2::compareHull(pointThree, pointOne));		// ""
	EXPECT_TRUE(GeometryOps_2::compareHull(pointOne, pointOne));		// Same Point
}

TEST_F(GeometryOps_2Test, compareInstersection) 
{
	Point<DIM> pointOne(1.0, 5.0);
	Point<DIM> pointTwo(2.0, 7.0);
	Point<DIM> pointThree(1.0, 7.0);

	EXPECT_FALSE(GeometryOps_2::compareIntersection(pointOne, pointTwo));	
	EXPECT_FALSE(GeometryOps_2::compareIntersection(pointOne, pointThree));		
	EXPECT_TRUE(GeometryOps_2::compareIntersection(pointTwo, pointOne));		
	EXPECT_TRUE(GeometryOps_2::compareIntersection(pointThree, pointOne));		
	EXPECT_TRUE(GeometryOps_2::compareIntersection(pointOne, pointOne));		
	EXPECT_FALSE(GeometryOps_2::compareIntersection(pointTwo, pointThree));
	EXPECT_TRUE(GeometryOps_2::compareIntersection(pointThree, pointTwo));
}

TEST_F(GeometryOps_2Test, simpleConvexHull) 
{
	std::vector<Point<DIM> > unsortedPoints;
	std::vector<Point<DIM> > hullExpected;

	unsortedPoints.push_back(Point<DIM>(5.0, 1.0));
	unsortedPoints.push_back(Point<DIM>(1.0, 4.0));
	unsortedPoints.push_back(Point<DIM>(2.0, 2.0));
	unsortedPoints.push_back(Point<DIM>(1.0, 1.0));
	unsortedPoints.push_back(Point<DIM>(4.0, 5.0));

	hullExpected.push_back(Point<DIM>(1.0, 1.0));
	hullExpected.push_back(Point<DIM>(1.0, 4.0));
	hullExpected.push_back(Point<DIM>(4.0, 5.0));
	hullExpected.push_back(Point<DIM>(5.0, 1.0));

	std::vector<Point<DIM> > hullReturned = GeometryOps_2::convexHull(unsortedPoints);

	for (unsigned int i = 0; i != hullExpected.size(); ++i) {
		EXPECT_EQ(hullExpected[i].x(), hullReturned[i].x());
		EXPECT_EQ(hullExpected[i].y(), hullReturned[i].y());
	}
}

TEST_F(GeometryOps_2Test, convexHullSegmentsParrallelToAxes) 
{
	std::vector<Point<DIM> > unsortedPoints;
	std::vector<Point<DIM> > hullExpected;

	unsortedPoints.push_back(Point<DIM>(5.0, 1.0));
	unsortedPoints.push_back(Point<DIM>(1.0, 5.0));
	unsortedPoints.push_back(Point<DIM>(2.0, 2.0));
	unsortedPoints.push_back(Point<DIM>(1.0, 1.0));
	unsortedPoints.push_back(Point<DIM>(5.0, 5.0));

	hullExpected.push_back(Point<DIM>(1.0, 1.0));
	hullExpected.push_back(Point<DIM>(1.0, 5.0));
	hullExpected.push_back(Point<DIM>(5.0, 5.0));
	hullExpected.push_back(Point<DIM>(5.0, 1.0));

	std::vector<Point<DIM> > hullReturned = GeometryOps_2::convexHull(unsortedPoints);

	for (unsigned int i = 0; i != hullExpected.size(); ++i) {
		EXPECT_EQ(hullExpected[i].x(), hullReturned[i].x());
		EXPECT_EQ(hullExpected[i].y(), hullReturned[i].y());
	}	
}

TEST_F(GeometryOps_2Test, convexHullSegmentsPointsInLine) 
{
	std::vector<Point<DIM> > unsortedPoints;
	std::vector<Point<DIM> > hullExpected;

	unsortedPoints.push_back(Point<DIM>(5.0, 1.0));
	unsortedPoints.push_back(Point<DIM>(1.0, 5.0));
	unsortedPoints.push_back(Point<DIM>(2.0, 2.0));
	unsortedPoints.push_back(Point<DIM>(1.0, 2.5));
	unsortedPoints.push_back(Point<DIM>(1.0, 1.0));
	unsortedPoints.push_back(Point<DIM>(5.0, 5.0));

	hullExpected.push_back(Point<DIM>(1.0, 1.0));
	hullExpected.push_back(Point<DIM>(1.0, 5.0));
	hullExpected.push_back(Point<DIM>(5.0, 5.0));
	hullExpected.push_back(Point<DIM>(5.0, 1.0));

	std::vector<Point<DIM> > hullReturned = GeometryOps_2::convexHull(unsortedPoints);

	for (unsigned int i = 0; i != hullExpected.size(); ++i) {
		EXPECT_EQ(hullExpected[i].x(), hullReturned[i].x());
		EXPECT_EQ(hullExpected[i].y(), hullReturned[i].y());
	}	
}

TEST_F(GeometryOps_2Test, convexHullSegmentsPointsAtSameLocation) 
{
	std::vector<Point<DIM> > unsortedPoints;
	std::vector<Point<DIM> > hullExpected;

	unsortedPoints.push_back(Point<DIM>(5.0, 1.0));
	unsortedPoints.push_back(Point<DIM>(1.0, 5.0));
	unsortedPoints.push_back(Point<DIM>(1.0, 5.0));
	unsortedPoints.push_back(Point<DIM>(2.0, 2.0));
	unsortedPoints.push_back(Point<DIM>(1.0, 2.5));
	unsortedPoints.push_back(Point<DIM>(1.0, 1.0));
	unsortedPoints.push_back(Point<DIM>(5.0, 5.0));

	hullExpected.push_back(Point<DIM>(1.0, 1.0));
	hullExpected.push_back(Point<DIM>(1.0, 5.0));
	hullExpected.push_back(Point<DIM>(5.0, 5.0));
	hullExpected.push_back(Point<DIM>(5.0, 1.0));

	std::vector<Point<DIM> > hullReturned = GeometryOps_2::convexHull(unsortedPoints);

	for (unsigned int i = 0; i != hullExpected.size(); ++i) {
		EXPECT_EQ(hullExpected[i].x(), hullReturned[i].x());
		EXPECT_EQ(hullExpected[i].y(), hullReturned[i].y());
	}	
}

} // namespace compGeom