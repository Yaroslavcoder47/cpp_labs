/*«аданы две окружности: с центром в точке ќ(x0, y0) и радиусом R0 и с центром в точке ќ(x1, 
y1) и радиусом R1. ќпределите, в скольких точках пересекаютс€ окружности, и определите 
координаты точек пересечени€.
*/

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;


int main() {
	const double EPS = 0.000001;
	cout << "Enter coordinates x0, y0 and radius r0 of center of first circle: \n";
	double x0, y0, r0;
	cout << "x0 = ";
	cin >> x0;
	cout << "y0 = ";
	cin >> y0;
	cout << "r0 = ";
	cin >> r0;
	cout << "Enter coordinates x1, y1 and radius r1 of center of second circle: \n";
	double x1, y1, r1;
	cout << "x1 = ";
	cin >> x1;
	cout << "y1 = ";
	cin >> y1;
	cout << "r1 = ";
	cin >> r1;

	/*ѕроверим совпадают ли окружности*/
	if (fabs(x1 - x0) < EPS && fabs(y1 - y0) < EPS && fabs(r1 - r0) < EPS) {
		cout << "Circles are coincide";
	}
	else{
		/* поместим начало координат в центр одной из окружностей, тогда получитс€ система уравнений :
		x^2 + y^2 = r0^2;
		(x - x1)^2 + (y - y1)^2 = r1^2;
		тогда реша€ эту систему придем к задаче пересечени€ пр€мой и окружности. ¬ид пр€мой
		Ax + By + C = 0; Ќайдем коэффициенты A, B, C
		*/
		x1 = x1 - x0;
		y1 = y1 - y0;
		double A = -2. * x1;
		double B = -2. * y1;
		double C = x1 * x1 + y1 * y1 + r0 * r0 - r1 * r1;

		/*–еша€ систему уравнений получаем одно квадратное относительно y, поэтому находим дискриминант*/
		double discriminant = B * B * r0 * r0 - C * C + r0 * r0 * A * A;
		if (discriminant < 0.) {
			cout << "No intersection points";
		}
		else if (discriminant > 0.) {
			cout << "Two intersection points: ";
			double yIntersection1;
			double xIntersection1;
			double yIntersection2;
			double xIntersection2;
			yIntersection1 = (-1. * B * C - A * sqrt(discriminant)) / (A * A + B * B);
			yIntersection2 = (-1. * B * C + A * sqrt(discriminant)) / (A * A + B * B);
			xIntersection1 = (-1. * B * yIntersection1 - C) / A;
			xIntersection2 = (-1. * B * yIntersection2 - C) / A;
			cout << '(' << xIntersection1 + x0 << "; " << yIntersection1 + y0 << "), ("
				<< xIntersection2 + x0 << "; " << yIntersection2 + y0 << ')';
		}
		else {
			cout << "One intersection point: ";
			double yIntersection = (-1. * B * C) / (A * A + B * B);
			double xIntersection = (-1. * B * yIntersection - C) / A;
			cout << '(' << xIntersection + x0 << "; " << yIntersection + y0 << ')';
		}
	}
	return 0;
}