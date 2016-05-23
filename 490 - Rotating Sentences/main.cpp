#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> sentences;
    string str;
    unsigned int maxlen=0;
    while(getline(cin, str)) {
        if(str.length()>maxlen) maxlen=str.length();
        sentences.push_back(str);
    }
    int elements=sentences.size(), pos=0;

    for(int i=0; i<maxlen; i++) {
        for(int j=elements-1; j>=0; j--) {
            pos=i;
            if(pos>=sentences[j].length()) printf(" ");
            else printf("%c", sentences[j][pos]);
        }
        printf("\n");
    }


    return 0;
}
