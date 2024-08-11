/* »звестны уравнени€ двух пр€мых y=a1x+b1 и y=a2x+b2. ќпределить, €вл€ютс€ ли эти пр€мые 
параллельными или перпендикул€рными, если нет, то найти угол между ними.*/

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

int main() {
	cout << "Enter coefficient of lines: \n";
	double a1, b1, a2, b2;
	cout << "y = a1x + b1: \n";
	cout << "a1 = ";
	cin >> a1;
	cout << "b1 = ";
	cin >> b1;
	cout << "y = a2x + b2: \n";
	cout << "a2 = ";
	cin >> a2;
	cout << "b2 = ";
	cin >> b2;

	double angle;
	if (fabs(a1 - a2) < 0.000001) {
		cout << "Lines are parallel.";
	}
	else if (fabs(a1 * a2 + 1) < 0.000001) {
		cout << "Lines are perpendicular.";
	}
	else {
		angle = atan(fabs((a1 - a2) / (1. + a1 * a2)));
		cout << "Angle between lines: " << angle;
	}
	return 0;
}