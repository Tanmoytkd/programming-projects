#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main()
{
    while(1)
    {
        POINT point; COLORREF color; HDC dc;
        GetCursorPos(&point); dc=GetDC(NULL);
        color=GetPixel(dc,point.x,point.y);
        ReleaseDC(GetDesktopWindow(),dc);
        for(int i=0; i<20; i++) printf("\b");
        printf("%i %i %i\n", GetRValue(color), GetGValue(color), GetBValue(color));
        Sleep(300);

    }
}
