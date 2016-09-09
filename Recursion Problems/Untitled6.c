#include<stdio.h>
int main()
{
    char a[500];
    gets(a);
    int l=strlen(a),c=0,v=0;
    int i;
    for(i=0;i<l;i++)
    {
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
            v++;
        else if(a[i]>=97&&a[i]<=122)
            c++;
    }
    printf("Vowels = %d\nConsonant = %d\n",v,c);
    return 0;
}

