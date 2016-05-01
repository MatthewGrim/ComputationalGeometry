#g++ -std=c++11 -lgtest main.cpp Point.cpp Vector.cpp Point_unittest.cpp Vector_unittest.cpp GeometryOps_2.cpp GeometryOps_2_unittest.cpp PolyLine.cpp PolyLine_unittest.cpp

# the compiler: g++ for the C++ program being generated
CC = g++

# compiler flags:
CFLAGS = -Wall -Wextra -std=c++11 -lgtest

# build files
TARGET = main.cpp data/Point.cpp data/Vector.cpp testing/Point_unittest.cpp testing/Vector_unittest.cpp algo/GeometryOps_2.cpp testing/GeometryOps_2_unittest.cpp data/PolyLine.cpp testing/PolyLine_unittest.cpp testing/BinarySearchTree_unittest.cpp

target: $(TARGET)
	$(CC) $(CFLAGS) $(TARGET)

clean:
	$(RM) $(TARGET)
