#include "../../std_lib_facilities.h"

int main() {
	cout << "Please enter a number: ";
	_Uint32t num;
	vector<int> bin;
	cin >> num;

	if (num == 0) {
		cout << 0;
	}
	else {
		while (num != 0) {
			bin.push_back(num % 2);
			num /= 2;
		}
	}

	while (bin.size() < 32) {
		bin.push_back(0);
	}

	cout << endl;
	for (int i = (bin.size()-1); i >= 0; i--) {
		cout << bin[i];
	}
	cout << endl;
}