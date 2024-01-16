#include <iostream>
#include <time.h>
#include <thread>
#include <chrono>

using namespace std;

void getmoney()
{
    srand((unsigned)time(NULL));
    int money = 0;
    money = rand() % 40 + 0;
    cout << "恭喜获得" << money << "的金币" << endl;
}

void getgift()
{
    srand((unsigned)time(NULL));
    int gift = 0;
    gift = rand() % 30 + 0;
    if (gift > 0 && gift <= 10)
    {
        cout << "恭喜获得杯子" << endl;
    }
    else if (gift > 10 && gift <= 20)
    {
        cout << "恭喜获得小洋娃娃" << endl;
    }
    else if (gift > 20 && gift <= 30)
    {
        cout << "恭喜获得大洋娃娃" << endl;
    }
}

int main()
{
    while (true)
    {
        int person = 0;
        cout << "抽奖游戏,1,金币 2,礼物 3,退出" << endl;
        cin >> person;
        if (isalpha(person))
        {
            cout << "请输入数字" << endl;
        }
        else if (person == 1)
        {
            getmoney();
        }
        else if (person == 2)
        {
            getgift();
        }
        else if (person == 3)
        {
            break; // 当用户输入3时，退出循环
        }
    }
    system("pause");
    //std::this_thread::sleep_for(std::chrono::seconds(2)); // 暂停两秒
    return 0;
}