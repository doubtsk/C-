#include <iostream>
#include <time.h>
#include <string>
#include <windows.h>
#include <stdlib.h>

struct user
{
    std::string name; // 用户名称
    int age;          // 用户年龄
    int gold = 0;
};

int main()
{
    using std::string;
    using namespace std;
    string start;

    // 以下是关于个人信息
    user p;
    cout << "请输入你的名字\n"
         << endl;
    cin >> p.name;
    cout << "嗨！" << p.name << "\t我需要你接下来输入你的年龄\n"
         << endl;
    cin >> p.age;

    // 关于年龄来初始化金币
    if (p.age > 10 && p.age < 18)
    {
        p.gold = 1000;
    }
    else if (p.age >= 18 && p.age <= 30)
    {
        p.gold = 1500;
    }
    else
    {
        p.gold = 500;
    }
    cout << "姓名：" << p.name << "\n"
         << "年龄：" << p.age << "\n"
         << "初始金币：" << p.gold << endl;
    Sleep(1000);
    system("cls");

    cout << "**************以下是游戏说明**************" << endl;
    Sleep(1000);
    system("cls");

    cout << "	" << endl;
    Sleep(1000);
    system("cls");
    cout << "你准备好了吗？(yes/no)" << endl;
    // 开始游戏
    string start0 = "yes";
    string start1;
    cin >> start1;
    int yes = start0.compare(start1);
    // 比较用户输入是否与“yes”一致，并返回值：0
    if (yes == 0)
    {
        while (p.gold >= 0)
        {
            srand((unsigned)time(NULL));
            int num0 = rand() % 6 + 1;
            int num1 = rand() % 6 + 1;
            int num2 = rand() % 6 + 1;
            int sum = (num0 + num1 + num2);

            string person_choice;
            cout << "电脑已经想好三个随机数的总和了，你觉得是大是小？(big/small)?\n"
                 << endl;
            cin >> person_choice;
            string com_choice1 = "big";
            string com_choice2 = "small";
            if ((person_choice.compare(com_choice1)) == 0 && (sum > 10) || (person_choice.compare(com_choice2) == 0) && (sum < 10))
            {
                cout << "电脑的数是：" << num0 << "," << num1 << "," << num2 << endl;
                cout << "赢!" << endl;
                p.gold += 100;
                cout << "目前金币" << p.gold << endl;
            }
            else
            {
                cout << "电脑的数是：" << num0 << "," << num1 << "," << num2 << endl;
                cout << "输！" << endl;
                p.gold -= 200;
                cout << "目前金币" << p.gold << endl;
            }
            if (p.gold <= 0)
            {
                break;
            }
        }
        cout << "看来是没有金币了" << endl;
    }

    system("pause");
    return 0;
}