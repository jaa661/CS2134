

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
	double input;

	do {
		cout << "Enter time: ";
		cin >> input;

		int weeks = 0;
		int days = 0;
		int hours = 0;
		int minutes = 0;

		cout << 60 * 60 * 24 * 7 << endl;

		while (input - (60 * 60 * 24 * 7) >= 0) {
			input -= (60 * 60 * 24 * 7);
			++weeks;
		}
		while (input - (60 * 60 * 24) >= 0) {
			input -= (60 * 60 * 24);
			++days;
		}
		while (input - (60 * 60) >= 0) {
			input -= (60 * 60);
			++hours;
		}
		while (input - 60 >= 0) {
			input -= 60;
			++minutes;
		}
		cout << weeks << " weeks, " << days << " days, " << hours << " hours, " << minutes << " minutes, and " << input << " seconds." << endl;
	}
	while (input >= 0);
}

