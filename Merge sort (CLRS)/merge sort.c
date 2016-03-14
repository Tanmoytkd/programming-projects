#include <stdio.h>
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

int main() {
    int arr[1000];
    int i, j=1000;
    for(i=0; i<1000; i++) {
        arr[i]=j;
        j--;
    }

    for(i=0; i<1000; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    m_s(arr, 0, 999);

    for(i=0; i<1000; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
