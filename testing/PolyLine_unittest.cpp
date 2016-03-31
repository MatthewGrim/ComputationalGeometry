/*
Author: Rohan Ramasamy
Data: 31/03/16
*/

#include "gtest/gtest.h"
#include "../data/Polyline.h"
#include "../data/Point.h"

namespace compGeom {

class PolylineTest : 
	public ::testing::Test {};

TEST_F(PolylineTest, limitsTest) {
	Polyline<1> defaultPolyline;
	EXPECT_EQ(0.0, defaultPolyline.xMin());
	EXPECT_EQ(0.0, defaultPolyline.xMax());

	defaultPolyline.addSegment(Point<1>(1.0));
	EXPECT_EQ(1.0, defaultPolyline.xMin());
	EXPECT_EQ(1.0, defaultPolyline.xMax());

	std::vector<Point<1> > oneDPoints;
	oneDPoints.push_back(Point<1>(1.0));	
	oneDPoints.push_back(Point<1>(2.0));
	oneDPoints.push_back(Point<1>(3.0));

	Polyline<1> oneDPolyline(oneDPoints);

	EXPECT_EQ(1.0, oneDPolyline.xMin());
	EXPECT_EQ(3.0, oneDPolyline.xMax());

	std::vector<Point<2> > twoDPoints;

	twoDPoints.push_back(Point<2>(-1.0));
	twoDPoints.push_back(Point<2>(2.0));
	twoDPoints.push_back(Point<2>(3.0, 5.0));

	Polyline<2> twoDPolyline(twoDPoints);

	EXPECT_EQ(-1.0, twoDPolyline.xMin());
	EXPECT_EQ(3.0, twoDPolyline.xMax());
	EXPECT_EQ(-1.0, twoDPolyline.yMin());
	EXPECT_EQ(5.0, twoDPolyline.yMax());

	std::vector<Point<3> > threeDPoints;

	threeDPoints.push_back(Point<3>(-1.0, 8.0, 3.0));
	threeDPoints.push_back(Point<3>(2.0, -5.0, 0.0));
	threeDPoints.push_back(Point<3>(3.0, 6.0, 7.0));

	Polyline<3> threeDPolyline(threeDPoints);

	EXPECT_EQ(-1.0, threeDPolyline.xMin());
	EXPECT_EQ(3.0, threeDPolyline.xMax());
	EXPECT_EQ(-5.0, threeDPolyline.yMin());
	EXPECT_EQ(8.0, threeDPolyline.yMax());
	EXPECT_EQ(0.0, threeDPolyline.zMin());
	EXPECT_EQ(7.0, threeDPolyline.zMax());
}

TEST_F(PolylineTest, addSegments) {
	Polyline<3> threeDPolyline;
	threeDPolyline.addSegment(Point<3>(1.0, -7.0, 8.0));
	threeDPolyline.addSegment(Point<3>(4.0, 2.0, 1.0));
	threeDPolyline.addSegment(Point<3>(0.0, -3.0, 9.0));

	std::vector<Point<3> > threeDPoints = threeDPolyline.getPoints();

	for (unsigned int i = 0; i != threeDPoints.size(); ++i) {
		EXPECT_EQ(threeDPolyline[i].x(), threeDPoints[i].x());
		EXPECT_EQ(threeDPolyline[i].y(), threeDPoints[i].y());
		EXPECT_EQ(threeDPolyline[i].z(), threeDPoints[i].z());
	}

	EXPECT_EQ(0.0, threeDPolyline.xMin());
	EXPECT_EQ(4.0, threeDPolyline.xMax());
	EXPECT_EQ(-7.0, threeDPolyline.yMin());
	EXPECT_EQ(2.0, threeDPolyline.yMax());
	EXPECT_EQ(1.0, threeDPolyline.zMin());
	EXPECT_EQ(9.0, threeDPolyline.zMax());	
}

} // compGeom