/**
This test file is used to verify that the class Polyline is working appropriately
*/

#include "gtest/gtest.h"
#include "Polyline.h"
#include "Point.h"

namespace compGeom {

class PolylineTest : 
	public ::testing::Test {};

TEST_F(PolylineTest, constructorTest) {
	std::vector<Point<1> > oneDPoints;

	oneDPoints.push_back(Point<1>(1.0));
	oneDPoints.push_back(Point<1>(2.0));
	oneDPoints.push_back(Point<1>(3.0));

	Polyline<1> oneDPolyline(oneDPoints);

	std::vector<Point<2> > twoDPoints;

	twoDPoints.push_back(Point<2>(1.0));
	twoDPoints.push_back(Point<2>(2.0));
	twoDPoints.push_back(Point<2>(3.0));

	Polyline<2> twoDPolyline(twoDPoints);

	std::vector<Point<3> > threeDPoints;

	threeDPoints.push_back(Point<3>(1.0));
	threeDPoints.push_back(Point<3>(2.0));
	threeDPoints.push_back(Point<3>(3.0));

	Polyline<3> threeDPolyline(threeDPoints);
}

}