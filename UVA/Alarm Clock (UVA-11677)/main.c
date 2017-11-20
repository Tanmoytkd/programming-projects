#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h1, m1, h2, m2;
    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    while(h1!=0 || m1!=0 || h2!=0 || m2!=0) {
        int hours= (h2>=h1) ? (h2-h1):(24+h2-h1);
        int minutes= (m2-m1);
        int time = hours*60+minutes;
        time = (time>0) ? time:(1440+time);
        printf("%d\n", time);
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    }
    return 0;
}
