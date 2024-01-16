// vector存放内置数据类型
#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
using namespace std;
void MyPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    // 创建了一个int类型的数组
    vector<int> v;
    // 尾插入数组
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // 通过迭代器访问容器里的数据
    vector<int>::iterator itBegin = v.begin(); // 起始迭代器    指向容器中的第一个元素
    vector<int>::iterator itEnd = v.end();     // 结束迭代器    指向容器中最后一个元素的下一个位置
    // iterator就类似于一个vector的小指针

    while (itBegin != itEnd)
    {
        cout << "while" << *itBegin << endl;
        itBegin++;
    }
}

void test02()
{
    // 创建了一个int类型的数组
    vector<int> v;
    // 尾插入数组
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "for" << *it << endl;
    }
}

void test03()
{
    // 创建了一个int类型的数组
    vector<int> v;
    // 尾插入数组
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    for_each(v.begin(), v.end(), MyPrint);
}

int main()
{
    test01();
    test02();
    test03();
    system("pause");
    return 0;
}