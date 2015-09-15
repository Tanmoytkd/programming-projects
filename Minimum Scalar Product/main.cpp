#include <iostream>
#include <string>
#include <fstream>
using namespace std;

long long int dot(long long int v1[], long long int v2[], long long int n);
long long int *arrange(long long int v[], long long int n, string direction);

int main()
{
    string inputLoc, outputLoc;
    cout << "Please enter the location or name of the input file: ";
    getline(cin, inputLoc); //get the input file
    cout << "Please enter the location or name of the output file: ";
    getline(cin, outputLoc); //create the output file

    ifstream input(inputLoc.c_str());
    ofstream output(outputLoc.c_str());

    string blank;
    long long int cases;
    input >> cases;
    getline(input, blank);

    //processing each case
    for(long long int t=0; t<cases; t++) {
        //get number of values
        long long int n;
        input >> n;
        getline(input, blank);

        //create 2 arrays
        long long int *vector1 = new long long int[n];
        long long int *vector2 = new long long int[n];

        //populating the first array
        for(long long int i1=0; i1<n; i1++) {
            input >> vector1[i1];
        }
        getline(input, blank);

        //populating the second array
        for(long long int i2=0; i2<n; i2++) {
            input >> vector2[i2];
        }
        getline(input, blank);

        //get the minimum scaler product
        long long int product=dot(arrange(vector1, n, "up"), arrange(vector2, n, "down"), n);
        output << "Case #" << t+1 << ": " << product << endl;



    }


    input.close();
    output.close();
    return 0;
}

long long int dot(long long int v1[], long long int v2[], long long int n) {
    long long int result=0;
    for(long long int i=0; i<n; i++) {
        result += v1[i]*v2[i];
    }
    return result;
}

long long int *arrange(long long int v[], long long int n, string direction) {
    //long long int *resArray = new long long int[n];
    if (direction=="up") {
        for(long long int i=0; i<n; i++) {
            for(long long int j=i+1; j<n; j++) {
                long long int temp;
                if(v[i]>v[j]) {
                    temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
        }
    }
    else if (direction=="down") {
        for(long long int i=0; i<n; i++) {
            for(long long int j=i+1; j<n; j++) {
                long long int temp;
                if(v[i]<v[j]) {
                    temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
        }
    }
    return v;
}
