#include <windows.h>
void NumLock(BOOL bSate)
{
    BYTE keyState[256];

    GetKeyboardState((LPBYTE)&keyState);
    if ((bSate && !(keyState[VK_NUMLOCK] & 1)) || (!bSate && (keyState[VK_NUMLOCK] & 1)))
    {
        // 模拟一个按键被按下
        keybd_event(VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
        // 模拟一个按键被释放
        keybd_event(VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    }
}
int main()
{
    NumLock(true);
    system("pause");
    return 0;
}
