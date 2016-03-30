#g++ -std=c++11 -lgtest main.cpp Point.cpp Vector.cpp Point_unittest.cpp Vector_unittest.cpp GeometryOps_2.cpp GeometryOps_2_unittest.cpp PolyLine.cpp PolyLine_unittest.cpp

# the compiler: g++ for the C++ program being generated
CC = g++

# compiler flags:
CFLAGS = -std=c++11 -lgtest

# build files
TARGET = main.cpp Point.cpp Vector.cpp Point_unittest.cpp Vector_unittest.cpp GeometryOps_2.cpp GeometryOps_2_unittest.cpp PolyLine.cpp PolyLine_unittest.cpp

target: $(TARGET)
	$(CC) $(CFLAGS) $(TARGET)

clean:
	$(RM) $(TARGET)
