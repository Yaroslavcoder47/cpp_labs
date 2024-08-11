/*С начала текущего года прошло m секунд. Определите который сейчас час, 
т.к. сколько сейчас часов, минут секунд от начала текущих суток.*/

#include <iostream>

using std::cin;
using std::cout;

int main() {
	cout << "Input the value of seconds since the beginning of the year: ";
	long long seconds_since_beginning;
	cin >> seconds_since_beginning;
	long long all_seconds_today; // it means how much seconds will be today
	all_seconds_today = seconds_since_beginning % 86400;
	long long hours = all_seconds_today / 3600;
	long long minutes = (all_seconds_today % 3600) / 60;
	long long seconds = (all_seconds_today % 3600) % 60;
	cout << "Today now: " << hours << " hours " << minutes << " minutes " << seconds << " seconds\n";
}