#include <bits/stdc++.h>
using namespace std;
#define dpsize 100000000LL

int dparr[dpsize+7], a[100008], arr[100007], res[100007], index=0, mnindex=0, mn[100007], mnleft=INT_MAX-7;
int m, n, k, width=0;
bool mark[100007];
string input, output;

int& dp(int row, int col)
{
    return dparr[row*width+col];
}

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


int rec(int pos, int left, int n, int id)
{
    if(left<0)
    {
        return -99999;
    }

    if(pos==n)
    {
        return 0;
    }

    if(dp(pos,left)==-1)
    {
        int p = a[pos];
        int val=arr[p];

        if(val>left)
            dp(pos,left)=0;
        else
        {
            int ret1 = rec(pos+1, left, n, id);
            int ret2 = val+rec(pos+1, left-val, n, id);

            dp(pos,left) = max(ret1,ret2);
        }
    }
    return dp(pos,left);
}

void rec2(int pos, int left, int n,int id)
{
    if(left<0)
    {
        return;
    }

    if(pos==n)
    {
        choose(left, id);
        return;
    }


    int p = a[pos];
    int val=arr[p];

    if(val>left)
    {
        choose(left,id);
        return;
    }

    else
    {
        int ret1 = rec(pos+1, left, n,id);
        int ret2 = val+rec(pos+1, left-val, n,id);

        if(ret1>ret2)
        {
            rec2(pos+1,left,n,id);
        }
        else
        {
            res[index++]=p;
            rec2(pos+1, left-val, n, id);
        }
    }
}

void process(int m, int n, int id)
{
    cout << id << endl;
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt_rand = mt19937(seed+rand());
    int threscounter = 100;

    long long mleft = m, nleft=n;
    while( (long long) mleft*nleft>= (long long)dpsize)
    {
        int pos = mt_rand()%n;
        pos = (mt_rand()%2==1 && (n-1-pos)>pos) ? n-1-pos:pos;
        if(mark[pos])
        {
            threscounter--;
            if(threscounter<=0)
            {
                mt_rand = mt19937(seed+rand());
                threscounter = 100;
            }
        }
        else
        {
            mark[pos]=true;
            nleft-=1;
            if(mleft>=arr[pos])
            {
                res[index++]=pos;
                mleft-=arr[pos];
                choose(mleft, id);
            }

        }
    }
    width = mleft;

    memset(dparr, -1, sizeof dparr);
    int ind=0;
    for(int i=0; i<n; i++)
    {
        if(mark[i])
            continue;
        a[ind++]=i;
    }

    assert(ind==nleft);

    rec(0, mleft, nleft,id);
    rec2(0,mleft, nleft,id);

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

void write_to_file(int iteration)
{
    while(iteration--)
    {
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
    for(ni=0; ni<5; ni++)
    {

        index=0;
        mnindex=0;
        mnleft=INT_MAX-7;
        memset(mark, 0, sizeof mark);

        input = names[ni]+".in";
        output = names[ni]+".out";

        freopen(input.c_str(), "r", stdin);

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

        int threshold = 1;
        while(iteration--)
        {
            process(m, n, iteration);
            if(mnleft<=threshold)
                break;
        }

        write_to_file(1);
    }

    return 0;
}
