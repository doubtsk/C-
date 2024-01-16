#include <iostream>
#include<thread>
#include<chrono>
#include <cstdlib> // 用于 system() 函数
#include <ctime> // 用于 srand() 和 time() 函数
using namespace std;

int main()
{
    srand((unsigned)time(NULL)); // 设置随机种子
    int age = rand() % 100 + 1;  // 年龄范围为 [1, 100]
    cout << "系统已经想好年龄了,你来猜一下" << endl;
    while (true) // 使用无限循环来保持游戏进行
    {
        int Page;
        cout << "请输入猜测的年龄: ";
        cin >> Page;
        if (cin.fail()) // 如果输入不是数字，则提示用户重新输入
        {
            cout << "字母不是数字,请重新输入" << endl;
            cin.clear();          // 清除错误标志位
            cin.ignore(10, '\n'); // 忽略错误的输入，避免死循环
        }
        else if (Page < 1 || Page > 100) // 如果输入的数字不在 [1, 100] 范围内，则提示用户重新输入
        {
            cout << "数字不在范围内,请重新输入" << endl;
        }
        else // 如果输入的数字在 [1, 100] 范围内，则进行比较
        {
            if (Page < age)
            {
                cout << "小了" << endl;
            }
            else if (Page > age)
            {
                cout << "大了" << endl;
            }
            else // 如果猜对了，则输出正确信息并退出循环
            {
                cout << "输入正确" << age << endl;
                break; // 退出循环
            }
        }
    }
    // system("pause");
     this_thread::sleep_for(chrono::seconds(1));
    return 0;
}