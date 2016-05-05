/*
Author: Rohan Ramasamy
Data: 05/05/16
*/

#include "gtest/gtest.h"

#include "../data/LineSegment.h"

namespace compGeom {

class LineSegmentTest : 
	public ::testing::Test {};

TEST_F(LineSegmentTest, ConstructorTest) {
	EXPECT_NO_THROW(LineSegment<1> line1D(Point<1>(1.0), Point<1>(2.0)));
	EXPECT_NO_THROW(LineSegment<2> line2D(Point<2>(1.0, 2.0), Point<2>(2.0, 3.0)));
	EXPECT_NO_THROW(LineSegment<3> line3D(Point<3>(1.0, 2.0, 3.0), Point<3>(2.0, 3.0, 4.0)));
}

TEST_F(LineSegmentTest, minAndMaxTest) {
	LineSegment<1> line1D(Point<1>(1.0), Point<1>(2.0));
	LineSegment<2> line2D(Point<2>(1.0, 2.0), Point<2>(2.0, 3.0));
	LineSegment<3> line3D(Point<3>(1.0, 2.0, 3.0), Point<3>(2.0, 3.0, 4.0));

	EXPECT_EQ(1.0, line1D.startPoint().x());
	EXPECT_EQ(2.0, line2D.startPoint().y());
	EXPECT_EQ(3.0, line3D.startPoint().z());
	EXPECT_EQ(2.0, line1D.endPoint().x());
	EXPECT_EQ(3.0, line2D.endPoint().y());
	EXPECT_EQ(4.0, line3D.endPoint().z());
}

TEST_F(LineSegmentTest, getPointsTest) {
	LineSegment<1> line1D(Point<1>(1.0), Point<1>(2.0));
	LineSegment<2> line2D(Point<2>(1.0, 2.0), Point<2>(2.0, 3.0));
	LineSegment<3> line3D(Point<3>(1.0, 2.0, 3.0), Point<3>(2.0, 3.0, 4.0));

	EXPECT_EQ(1.0, line1D.getPoints().first.x());
	EXPECT_EQ(2.0, line2D.getPoints().first.y());
	EXPECT_EQ(3.0, line3D.getPoints().first.z());
	EXPECT_EQ(2.0, line1D.getPoints().second.x());
	EXPECT_EQ(3.0, line2D.getPoints().second.y());
	EXPECT_EQ(4.0, line3D.getPoints().second.z());
}

}