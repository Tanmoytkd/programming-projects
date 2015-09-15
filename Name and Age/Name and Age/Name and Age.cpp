#include <iostream>
#include <string>
#include <cmath>

double getAge();

int main() {
	using namespace std;
	cout << "Please Enter your first and last name and press enter: ";
	string fname, lname;
	cin >> fname >> lname;
	cout << "Please enter your age: ";
	double age = -1;
	while (age == -1) {
		age = getAge();
	}
	int years = int (floor(age));
	int months = int ((age - years)*12);

	cout << "Your name is " << fname << " " << lname << endl;
	cout << "Your age is " << years << " years " << "and " << months << " months" << endl;
}
double getAge() {
	double age = -1;
	std::cin >> age;
	return age;
}