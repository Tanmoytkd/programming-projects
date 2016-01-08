#include "../../std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to (followed by 'enter'): \n";
	string first_name; // first_name is a variable of type string
	cin >> first_name; // read characters into first_name
	cout << "Dear " << first_name << ", \n";
	cout << "    How are you? I am fine. I miss you. I don't know who I am writing to. But I am still writing it in the hopes that it will become one of the most popular writings of all time within a few years.";
	cout << " Maybe this will become famous within a decade of so. Hahaha. :-p" << endl;
	string frnd_name="";
	cout << "Enter name of another friend: ";
	cin >> frnd_name;
	cout << "Have you seen " << frnd_name << " lately?" << endl;
	char friend_sex=0;
	cout << "Enter 'm' if the friend is male or 'f' if the friend is female:";
	cin >> friend_sex;
	if (friend_sex == 'm') cout << "If you see " << frnd_name << " please ask him to call me." << endl;
	else if (friend_sex == 'f') cout << "If you see " << frnd_name << " please ask her to call me." << endl;
	cout << "Enter your friend's age: ";
	int age;
	cin >> age;
	if (age < 0 || age > 110) simple_error("you're kidding!");
	else { cout << "I hear you just had a birthday and you are " << age << " years old." << endl; }
	if (age < 12) cout << "Next year you will be " << age + 1 << endl;
	else if (age == 17) cout << "Next year you will be able to vote." << endl;
	else if (age > 70) cout << "I hope you are enjoying retirement." << endl;

	cout << endl << "Yours sincerely," << endl << endl;
	cout << "Tanmoytkd" << endl;
}