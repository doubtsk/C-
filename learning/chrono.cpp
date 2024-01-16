#include <windows.h>
#include <iostream>
using namespace std;
int main()
{
    POINT curpos;
    while (1)
    {
        GetCursorPos(&curpos);
        cout << "x: " << curpos.x << " " << "y: " << curpos.y;
        //printf("x:%d,y:%d", curpos.x, curpos.y);
        Sleep(300);
        printf("\n");
    }
}