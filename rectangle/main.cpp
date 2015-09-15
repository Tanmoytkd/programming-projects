class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C-A)*(D-B);
        int area2 = (G-E)*(H-F);
        int area3, x, y;

        if(A<=E) {
            if(C>E) {
                if(C<G)
                    x=C-E;
                else
                    x=G-E;
            }
            else x=0;
        }
        else if(A>E) {
            if(A<G) {
                if(C>G)
                    x=G-A;
                else
                    x=C-A;
            }
            else x=0;
        }


        if(B<=F) {
            if(D>F) {
                if(D<H)
                    y=D-F;
                else
                    y=H-F;
            }
            else y=0;
        }
        else if(B>F) {
            if(B<H) {
                if(D>H)
                    y=H-B;
                else
                    y=D-B;
            }
            else y=0;
        }


        area3 = x*y;
        int areaTotal = area1 + area2 - area3;
        return areaTotal;
    }
};
