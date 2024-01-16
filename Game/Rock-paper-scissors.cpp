#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
int main()
{
    using namespace std;
    int win_num = 0;  //赢！
    int lose_num = 0; //输！
    int num = 0;      
    
    cout << "石头(0),剪刀(1),(布)" << endl;

    while (num != 3)
    {
        int user = 0;
        cin >> user;
        srand((unsigned)time(NULL));
        int com = rand() % 2;
        if (user > 2)
        {
            cout << "不能出大于2的值哦" << endl;
        }
        else
        {
            string data[3] = {"石头", "剪刀", "布"};
            cout << "你出的是：" << data[user] << "\t电脑出的是:" << data[com] << endl;
            if (user == com)
            {
                cout << "平局" << endl;
                continue;
            }
            else if ((user == 0 && com == 1) || (user == 1 && com == 2) || (user == 2 && com == 0))
            {
                cout << "赢！" << endl;
                win_num += 1;
            }
            else
            {
                cout << "输！" << endl;
                lose_num += 0;
            }
        }

        num += 1;
    }
    system("pause");
    return 0;
}