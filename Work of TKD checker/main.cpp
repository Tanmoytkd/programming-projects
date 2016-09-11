#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)

#include <conio.h>

using namespace std;

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    FILE * sol_lst = fopen("current_list.txt", "r");

    set<int> solved;
    int prob_id;
    while(fscanf(sol_lst, "%d", &prob_id)==1) {
        solved.insert(prob_id);
    }

    int num;
    string tuki, data;

    vector<int> problem, unsolved;

//    int counter=1;

    while(cin >> tuki >> data) {
        cin >> num;
        int ac=0;
        getline(cin, data);
        stringstream line(data);
        while(line >> tuki) {
            if(tuki=="Accepted") ac=1;
        }
        if(ac) {
            problem.push_back(num);
//            cout << counter << " -> " << num << endl;
            if(solved.find(num)==solved.end()) {
                unsolved.push_back(num);
//                cout << "You have to do " << num << endl;
            }
        }
//        counter++;
    }

//    cout << endl << endl << endl << endl;

    reverse(unsolved.begin(), unsolved.end());
    for(int i=0; i<unsolved.size(); i++) {
        cout << unsolved[i] << endl;
    }

    return 0;
}
