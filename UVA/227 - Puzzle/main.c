#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char puzzle[5][5], str[10], ch;
    int test=0, i, j, first=1;
    while(1) {
        int no_ans=0, brow, bcol, row, col;
        for(i=0; i<5; i++) {
            gets(str);
            if(strlen(str)==0) gets(str);

            if(str[0]=='Z') return 0;
            else {
                for(j=0; j<5; j++) {
                    puzzle[i][j]=str[j];
                    if(puzzle[i][j]<'A' || puzzle[i][j]>'Z') {
                        brow=i;
                        bcol=j;
                    }
                }
            }
        }
        test++;

        ch=getchar();
        while(ch!='0') {
            switch(ch) {
            case 'A' :col=bcol;
                      row=brow-1;
                      break;
            case 'B' :col=bcol;
                      row=brow+1;
                      break;
            case 'L' :row=brow;
                      col=bcol-1;
                      break;
            case 'R' :row=brow;
                      col=bcol+1;
            case ' ' :
            case '\n':break;
            default  :no_ans=1;
            }
            if(row<0 || row>=5 || col<0 || col>=5) no_ans=1;


            if(no_ans==0) {
                char temp=puzzle[brow][bcol];
                puzzle[brow][bcol]=puzzle[row][col];
                puzzle[row][col]=temp;
                brow=row;
                bcol=col;
            }

            ch=getchar();
        }

        if(first!=1) printf("\n");
        printf("Puzzle #%d:\n", test);
        if(no_ans==1) printf("This puzzle has no final configuration.\n");
        else {
            for(i=0; i<5; i++) {
                for(j=0; j<5; j++) {
                    printf("%c", puzzle[i][j]);
                    if(j<4) printf(" ");
                }
                printf("\n");
            }
        }
        if(first==1) first=0;
    }

    return 0;
}
