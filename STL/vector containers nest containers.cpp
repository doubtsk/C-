// vector容器嵌套容器
#include <vector>
#include <iostream>
using namespace std;
void test01()
{
    vector<vector<int>> v;

    // 创建小容器
    vector<int> i1;
    vector<int> i2;
    vector<int> i3;
    vector<int> i4;
    vector<int> i5;

    // 向小容器中创建数据
    for (int i = 0; i < 4; i++)
    {
        i1.push_back(i + 1);
        i2.push_back(i + 2);
        i3.push_back(i + 3);
        i4.push_back(i + 4);
    }

    // 将小容器插入到大容器中
    v.push_back(i1);
    v.push_back(i2);
    v.push_back(i3);
    v.push_back(i4);

    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        //(*it)---容器 vector<int
        for (vector<int>::iterator ii = (*it).begin(); ii != (*it).end(); ii++)
        {
            cout << *ii << " ";
        }
        cout << endl;
    }
}
int main()
{
    test01();
    system("pause");
    return 0;
}