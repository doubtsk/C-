#include <iostream>
using namespace std;

int a = 0;
int b = 0;
int count = 0;
int exchange(int empty_bottle)
{

    if (empty_bottle <= 1)
    {
        return 0;
    }
    if (empty_bottle == 2)
    {
        return 1;
    }
    if (empty_bottle >= 3)
    {
        a = empty_bottle / 3; // 一开始就只能换几次
        b = empty_bottle % 3; // 还剩下几瓶
    }
    count = a + exchange((empty_bottle / 3)) + exchange((empty_bottle % 3));
    return count;
}
int main()
{
    int empty_bottle = 0;
    cin >> empty_bottle;
    int total = exchange(empty_bottle);
    cout << "change" << total << endl;
    system("pause");
    return 0;
}