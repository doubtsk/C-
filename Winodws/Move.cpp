#include <iostream>
#include <windows.h>
using namespace std;

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)
#define KEY_DOWN_W(VK_CODE) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)
#define KEY_UP(VK_CODE) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 0 : 1)

int main()
{
    while (true)
    {
        cout << "判断鼠标左键是否按下" << endl;
        if (KEY_DOWN(VK_LBUTTON))
            cout << "鼠标左键按下" << endl;

        else
            cout << "否" << endl;

        if (KEY_DOWN(VK_RBUTTON))
            cout << "鼠标右键按下" << endl;
        else
            cout << "否" << endl;
        if (KEY_DOWN(VK_MBUTTON))
            cout << "鼠标中键按下" << endl;
        else
            cout << "否" << endl;
        
        Sleep(10);
        system("cls");
    }
    system("pause");
    return 0;
}