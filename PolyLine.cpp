#include "Polyline.h"
#include "Point.h"

template <>
Polyline<1>::
Polyline(
	const std::vector<Point<1> >& points)
{
	internalPoints = points;
	for (auto point : internalPoints) {
		if (point.x() < Lim[0]) { Lim[0] = point.x(); }
		if (point.x() < Lim[1]) { Lim[1] = point.x(); }
	}
}

template <>
Polyline<2>::
Polyline(
	const std::vector<Point<2> >& points)
{
	internalPoints = points;
	for (auto point : internalPoints) {
		if (point.x() < Lim[0]) { Lim[0] = point.x(); }
		if (point.x() < Lim[1]) { Lim[1] = point.x(); }
		if (point.y() < Lim[2]) { Lim[2] = point.y(); }
		if (point.y() < Lim[3]) { Lim[3] = point.y(); }
	}
}

template <>
Polyline<3>::
Polyline(
	const std::vector<Point<3> >& points)
{
	internalPoints = points;
	for (auto point : internalPoints) {
		if (point.x() < Lim[0]) { Lim[0] = point.x(); }
		if (point.x() < Lim[1]) { Lim[1] = point.x(); }
		if (point.y() < Lim[0]) { Lim[0] = point.y(); }
		if (point.y() < Lim[1]) { Lim[1] = point.y(); }
		if (point.z() < Lim[0]) { Lim[0] = point.z(); }
		if (point.z() < Lim[1]) { Lim[1] = point.z(); }
	}
}

// template class Polyline<1>;
// template class Polyline<2>;
template class Polyline<3>;