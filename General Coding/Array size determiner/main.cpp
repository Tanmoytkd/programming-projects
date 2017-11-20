#include <iostream>

using namespace std;

int findLength(int data[]);

int main()
{
    int l;
    cout << "Enter the length of the array: ";
    cin >> l;
    int data[l];
    for(int i=0; i<l; i++) {
        data[i]=i;
    }
    //data[l-1]=NULL;

    cout << findLength(data) << endl;

    return 0;
}

int findLength(int data[]) {
    int count=0;
    while(data[count]) {
            count++;
    }
    return count;
}
