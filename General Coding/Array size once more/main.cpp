#include <iostream>

using namespace std;

int arrCount(int arr[]);

int main()
{
    int arr[5] = {5,2,3,4,7};
    cout << "The number of elements in this array is " << arrCount(arr) << endl;
    return 0;
}

int arrCount(int arr[]) {
    int counts=0;
    for(int n: arr) {
        counts++;
    }
    return counts;
}
