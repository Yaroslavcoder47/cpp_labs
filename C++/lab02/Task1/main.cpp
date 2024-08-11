/*јндрей, просматрива€ программу телевидени€ на воскресенье, выписал названи€, врем€ 
начала и продолжительности трех передач, которые ему хотелось бы посмотреть. ¬ h часов 
m минут он включил телевизор.  акую передачу смотрит јндрей?*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main() {
	//First show
	string firstShow;
	int hoursOfFirstShow;
	int minutesOfFirstShow;
	int hoursDurationOfFirstShow;
	int minutesDurationOfFirstShow;
	cout << "Enter name of the first show: ";
	cin >> firstShow; 
	cout << "Enter hours when the first show starts: ";
	cin >> hoursOfFirstShow;
	cout << "Enter minutes when the first show starts: ";
	cin >> minutesOfFirstShow;
	cout << "Enter hours of duration of the first show: ";
	cin >> hoursDurationOfFirstShow;
	cout << "Enter minutes of duration of the first show: ";
	cin >> minutesDurationOfFirstShow;

	//Second show
	string secondShow;
	int hoursOfSecondShow;
	int minutesOfSecondShow;
	int hoursDurationOfSecondShow;
	int minutesDurationOfSecondShow;
	cout << "Enter name of the second show: ";
	cin >> secondShow;
	cout << "Enter hours when the second show starts: ";
	cin >> hoursOfSecondShow;
	cout << "Enter minutes when the second show starts: ";
	cin >> minutesOfSecondShow;
	cout << "Enter hours of duration of the second show: ";
	cin >> hoursDurationOfSecondShow;
	cout << "Enter minutes of duration of the second show: ";
	cin >> minutesDurationOfSecondShow;

	//Third show
	string thirdShow;
	int hoursOfThirdShow;
	int minutesOfThirdShow;
	int hoursDurationOfThirdShow;
	int minutesDurationOfThirdShow;
	cout << "Enter name of the third show: ";
	cin >> thirdShow;
	cout << "Enter hours when the third show starts: ";
	cin >> hoursOfThirdShow;
	cout << "Enter minutes when the third show starts: ";
	cin >> minutesOfThirdShow;
	cout << "Enter hours of duration of the third show: ";
	cin >> hoursDurationOfThirdShow;
	cout << "Enter minutes of duration of the third show: ";
	cin >> minutesDurationOfThirdShow;

	int startHours;
	int startMinutes;
	cout << "Enter hours when he starts watching: ";
	cin >> startHours;
	cout << "Enter minutes when he starts watching: ";
	cin >> startMinutes;
	string currentShow;

	if (startHours*60 + startMinutes >= hoursOfFirstShow * 60 + minutesOfFirstShow && 
		startHours * 60 + startMinutes <= (hoursOfFirstShow + hoursDurationOfFirstShow) * 60 + 
		minutesOfFirstShow + minutesDurationOfFirstShow){
		currentShow = firstShow;
	}
	else if (startHours * 60 + startMinutes >= hoursOfSecondShow * 60 + minutesOfSecondShow &&
		startHours * 60 + startMinutes <= (hoursOfSecondShow + hoursDurationOfSecondShow) * 60 +
		minutesOfSecondShow + minutesDurationOfSecondShow) {
		currentShow = secondShow;
	}
	else if (startHours * 60 + startMinutes >= hoursOfThirdShow * 60 + minutesOfThirdShow &&
		startHours * 60 + startMinutes <= (hoursOfThirdShow + hoursDurationOfThirdShow) * 60 +
		minutesOfThirdShow + minutesDurationOfThirdShow){
		currentShow = thirdShow;
	}
	else {
		currentShow = "No show(";
	}

	cout << currentShow;
	return 0;
}