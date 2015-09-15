#include <iostream>
#include <string>

int main() {
	using namespace std;
	string previous = " ", current;
	cout << "Please enter your text: ";
	while (cin >> current)
	{
		if (previous == current) {
			cout << "Repeated word: " << current << endl;
		}
		previous = current;
	}
	return 0;
}