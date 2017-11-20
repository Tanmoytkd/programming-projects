#include <stdio.h>
#include <math.h>
#include <limits.h>

void merge(int arr[], int p, int q, int r) {
    int n1=q-p+1, n2=r-q;
    int L[n1+1], R[n2+1];
    int i, j;
    for(i=0; i<n1; i++) {
        L[i]=arr[p+i];
    }
    for(j=0; j<n2; j++) {
        R[j]=arr[q+j+1];
    }

    L[n1]=INT_MAX;
    R[n2]=INT_MAX;

    i=0;
    j=0;
    int k;
    for(k=p; k<=r; k++) {
        if(L[i]<=R[j]) {
            arr[k]=L[i];
            i++;
        }
        else {
            arr[k]=R[j];
            j++;
        }
    }
}

void m_s (int arr[], int p, int r) {
    if(p<r) {
    int q=(p+r)/2;
    m_s(arr, p, q);
    m_s(arr, q+1, r);
    merge(arr, p, q, r);
    }
}

void i_s(int arr[], int m, int n) {
    int i;
    for(i=m+1; i<=n; i++) {
        int j=i;
        while(arr[j]<arr[j-1] && j>m){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t, i;
    scanf("%d", &t);
    for(i=0; i<t; i++) {
        int ques, m=0, n=0, j, counter=0;
        scanf("%d", &ques);
        int inc[ques], cor[ques];

        for(j=0; j<ques; j++) {
            int diff, stat;
            char res;
            scanf("%d %d", &diff, &stat);
            res=getchar();
            while(res==' ') res=getchar();

            if(res=='c' && stat==1) {
                cor[m]=diff;
                m++;
            }
            else if(res=='i' && stat == 0) {
                inc[n]=diff;
                n++;
            }
        }

        if(m==0 || n==0) {
            printf("0\n");
            continue;
        }
        else {
            m_s(cor, 0, m-1);
            m_s(inc, 0, n-1);

            int x=0, y=0, xcount=0,  k;

            cor[m]=INT_MAX;
            inc[n]=INT_MAX;
            for(k=0; k<m+n; k++) {
                if(inc[x]<cor[y]) {
                    x++;
                    xcount++;
                }
                else {
                    y++;
                    counter+=xcount;
                }
            }

            printf("%d\n", counter);
        }
    }
    return 0;
}

