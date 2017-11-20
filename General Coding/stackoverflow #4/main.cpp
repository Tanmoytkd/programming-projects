#include <iostream>

 using namespace std;

   int main()
{

int celsius, fahrenheit;

//Get degrees in celsius
cout << "Please input degrees Celsius: \n";

cin >> celsius;

//convert celsius to fahrenheit
fahrenheit = celsius * 1.8 + 32;

//display degrees farhenheit/ thank you message
cout << "\n" << "Degrees Fahrenheit: \n" << fahrenheit << "\n";
cout << "\n" << "Thank you for using my Celsius to Fahrenheit converter. \n" << "\n";


   int yes = 1;

   cout << "do you wish to convert again? \n";
   cin >> yes;

        if (yes == 1)
            {
                cout << "please enter degrees Celsius" ;
                cin >> celsius;

                //convert celsius to fahrenheit
                fahrenheit = celsius * 1.8 + 32;

                cout << "\n" << "Degrees Fahrenheit: \n" << fahrenheit << "\n";
            }
            else
            {
                cout << "fine";
            }
return 0;


}
