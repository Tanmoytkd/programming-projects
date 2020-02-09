#include <bits/stdc++.h>
using namespace std;
#define dpsize 100000000

int dp[dpsize], arr[100007], res[100007], index=0, mnindex=0, mn[100007], mnleft=INT_MAX-7;
int m, n, k;
bool mark[100007];
string input, output;

void choose(int mleft, int id)
{
    static int previd = -2;
    if(mleft<mnleft)
    {
        mnleft=mleft;
        if(id!=previd)
        {
            previd = id;
            mnindex=index;
            for(int i=0; i<mnindex; i++)
            {
                mn[i] = res[i];
            }
        }
        else
        {
            while(mnindex<index)
            {
                mn[mnindex] = res[mnindex];
                mnindex++;
            }
        }
        cout << "=======================\n\n";
        cout << m-mnleft << endl;
        cout << "\n\n=======================" << endl;;
    }
}




void rec(int m, int n, int id)
{
//    cout << id << endl;
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt_rand = mt19937(seed+rand());
    int threscounter = 100;

    long long mleft = m, nleft=n;
    while( /*(long long) mleft*nleft>= (long long)dpsize*/ mleft>0)
    {
        int pos = mt_rand()%n;
//        cout << pos << " ";
        if(mark[pos])
        {
            mt_rand = mt19937(seed+rand());
            threscounter--;
            if(threscounter<=0)
            {
                break;
                threscounter = 100;
            }
        }
        else
        {
            mark[pos]=true;
            if(mleft>=arr[pos])
            {
                res[index++]=pos;
                mleft-=arr[pos];
                nleft-=1;
                choose(mleft, id);
            }

        }
    }
//    cout << endl;

//    for(int i=0; i<n; i++) {
//        cout << mark[i];
//    }
//    cout << endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(10));


    memset(mark, 0, sizeof mark);
    index=0;
}

void report(int iteration)
{
    while(iteration--)
    {
        std::this_thread::sleep_for (std::chrono::seconds(5));
        ofstream myfile;
        myfile.open (output);
        myfile << mnindex << endl;
        sort(mn, mn+mnindex);
        for(int i=0; i<mnindex; i++)
        {
            myfile << mn[i] << " ";
        }
        myfile << endl;
        myfile.close();
        cout << "written to disk" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string names[5] = {"a_example", "b_small", "c_medium", "d_quite_big", "e_also_big"};

    int ni;
    for(ni=0; ni<5; ni++) {
        input = names[ni]+".in";
        output = names[ni]+".out";
    }

    cin >> ni;
    input = names[ni]+".in";
    output = names[ni]+".out";



    freopen(input.c_str(), "r", stdin);
//    freopen((input+".out").c_str(), "w", stdout);


    cin >> m >> n;

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        if(arr[i]>m)
        {
            n=i;
        }
    }

    int iteration = 10000;

    thread th1(report, iteration);

    while(iteration--)
    {
        rec(m, n, iteration);
    }

    report(1);

    return 0;
}
