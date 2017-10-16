#define _WIN32_WINNT 0x501

// if you run into some error, try 0x501 above instead of 0x500

#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <cstdio>
using namespace std;

double screenRes_width, screenRes_height;
HDC hdc;
int threshold=25;

void getMousePosition (int& xPos, int& yPos)
{
     // make a point and read into it, then update vars via pointers
     POINT cursorPos;
     GetCursorPos(&cursorPos);
     xPos = cursorPos.x;
     yPos = cursorPos.y;
}

void mouseRightClick ()
{
     INPUT Input = {0};

     // right down
     Input.type = INPUT_MOUSE;
     Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
     ::SendInput(1,&Input,sizeof(INPUT));

     // right up
     ::ZeroMemory(&Input,sizeof(INPUT));
     Input.type = INPUT_MOUSE;
     Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
     ::SendInput(1,&Input,sizeof(INPUT));
}

void mouseLeftClick ()
{
     INPUT Input = {0};

     // left down
     Input.type = INPUT_MOUSE;
     Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
     ::SendInput(1,&Input,sizeof(INPUT));

     // left up
     ::ZeroMemory(&Input,sizeof(INPUT));
     Input.type = INPUT_MOUSE;
     Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
     ::SendInput(1,&Input,sizeof(INPUT));
}

void mouseMoveTo (int toX, int toY)
{
//     // find out info about the screen so that we know how to properly go
//     // to pixels
     screenRes_width = ::GetSystemMetrics( SM_CXSCREEN )-1;
     screenRes_height = ::GetSystemMetrics( SM_CYSCREEN )-1;
//
     // modify for the 65535 (as float) way we talk to the screen...
     double dx = toX*(65535.0f / screenRes_width);
     double dy = toY*(65535.0f / screenRes_height);

     // movement stuff
     INPUT Input = {0};
     Input.type = INPUT_MOUSE;
     Input.mi.dwFlags = MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE;
     Input.mi.dx = LONG(dx);
     Input.mi.dy = LONG(dy);
     ::SendInput(1,&Input,sizeof(INPUT));
}


void evaluate(int x, int y) {
    int red = GetRValue(GetPixel(hdc, x, y));
    //printf("%d ", red);
    if(red<=threshold) {
        mouseMoveTo(x, y);
        mouseLeftClick();
    }
}

int main() {
    int debug=0;
    SetConsoleTitle( "Piano Tiles 2 Trainer" );

//    while(1) {
//    HDC wdc = GetWindowDC(GetActiveWindow()); // desktop window, entire screen
//    POINT pt;
//    GetCursorPos(&pt); // get screen coordinates
//    COLORREF clr = GetPixel(wdc,pt.x,pt.y);
//    cout << int(GetRValue(clr)) << endl;
//    ReleaseDC(NULL,wdc);
//    }


     //find out info about the screen so that we know how to properly go
     // to pixels
     hdc = GetDC(NULL);
     screenRes_width = ::GetSystemMetrics( SM_CXSCREEN )-1;
     screenRes_height = ::GetSystemMetrics( SM_CYSCREEN )-1;


    // set up variables to be used
    int xPos, yPos; // position of pointer
    int sleepTime = 5000; // sleep time in ms

//    int prevx, prevy, cnt=0;
//    while(1) {
//        getMousePosition(xPos, yPos);
//
//        if(xPos!=prevx || yPos!=prevy) {
//            while(cnt--) putchar('\b');
//            cnt = printf("%04d %04d %d", xPos, yPos, GetRValue(GetPixel(hdc, xPos, yPos)));
//            prevx=xPos;
//            prevy=yPos;
//        }
//    }

    while(debug) {
        getMousePosition(xPos, yPos);
        COLORREF _color = GetPixel(hdc, xPos, yPos);

        int red = GetRValue(_color), green=GetGValue(_color), blue=GetBValue(_color);
        int cnt = printf("%d %d %d\n", red, green, blue);
        while(cnt--) putchar('\b');
    }

    Sleep(5000);
    std::cout << "Put your mouse over the start button and wait..." << std::endl;
    Sleep(3000);
    getMousePosition(xPos, yPos);


    int x1, y1, x2, y2, x3, y3, x4, y4;

    std::cout << "Put your mouse over the 1st area and wait..." << std::endl;
    Sleep(3000);
    getMousePosition(x1, y1);

    std::cout << "Put your mouse over the 2nd area and wait..." << std::endl;
    Sleep(3000);
    getMousePosition(x2, y2);

    std::cout << "Put your mouse over the 3nd area and wait..." << std::endl;
    Sleep(3000);
    getMousePosition(x3, y3);

    std::cout << "Put your mouse over the 4nd area and wait..." << std::endl;
    Sleep(3000);
    getMousePosition(x4, y4);


    std::cout << "Game Starting..." << std::endl;
    Sleep(5000);

    mouseMoveTo(xPos, yPos);
    mouseLeftClick();

    while(1) {
        evaluate(x1, y1);
        evaluate(x2, y2);
        evaluate(x3, y3);
        evaluate(x4, y4);
        //cout << endl;
    }


//    HDC hdc, hdcTemp;
//    RECT rect;
//    BYTE* bitPointer;
//    int x, y;
//    int red, green, blue, alpha;
//
//    while(true)
//    {
//        hdc = GetDC(HWND_DESKTOP);
//        GetWindowRect(HWND_DESKTOP, &rect);
//                int MAX_WIDTH = rect.right;
//            int MAX_HEIGHT = rect.bottom;
//
//        hdcTemp = CreateCompatibleDC(hdc);
//        BITMAPINFO bitmap;
//        bitmap.bmiHeader.biSize = sizeof(bitmap.bmiHeader);
//        bitmap.bmiHeader.biWidth = MAX_WIDTH;
//        bitmap.bmiHeader.biHeight = MAX_HEIGHT;
//        bitmap.bmiHeader.biPlanes = 1;
//        bitmap.bmiHeader.biBitCount = 32;
//        bitmap.bmiHeader.biCompression = BI_RGB;
//        bitmap.bmiHeader.biSizeImage = MAX_WIDTH * 4 * MAX_HEIGHT;
//        bitmap.bmiHeader.biClrUsed = 0;
//        bitmap.bmiHeader.biClrImportant = 0;
//        HBITMAP hBitmap2 = CreateDIBSection(hdcTemp, &bitmap, DIB_RGB_COLORS, (void**)(&bitPointer), NULL, NULL);
//        SelectObject(hdcTemp, hBitmap2);
//        BitBlt(hdcTemp, 0, 0, MAX_WIDTH, MAX_HEIGHT, hdc, 0, 0, SRCCOPY);
//
//        for (int i=0; i<(MAX_WIDTH * 4 * MAX_HEIGHT); i+=4)
//        {
//            red = (int)bitPointer[i];
//            green = (int)bitPointer[i+1];
//            blue = (int)bitPointer[i+2];
//            alpha = (int)bitPointer[i+3];
//
//            x = i / (4 * MAX_HEIGHT);
//            y = i / (4 * MAX_WIDTH);
//
//            if (red == 255 && green == 0 && blue == 0)
//            {
//                SetCursorPos(x,y);
//                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
//                Sleep(50);
//                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
//                Sleep(25);
//            }
//        }
//    }

    return 0;
}
