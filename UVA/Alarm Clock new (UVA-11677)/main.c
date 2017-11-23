#include<stdio.h>


int main()
{



    int h1,m1,h2,m2,d,t,t1;

    while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2) && (h1!=0 || m1!=0 || h2!=0 || m2!=0)) {
    	t=h1*60+m1;
    	t1=h2*60+m2;
    	d=(t1-t);
    	if(d<0) {
    		printf("%d\n", d+1440);
    	}
    	else {
    		printf("%d\n",d);
    	}
    }
   return 0;

}

