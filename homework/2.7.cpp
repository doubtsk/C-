#include <iostream>
#include <string>
using namespace std;

// 2.7.1 显示名字和地址
void func()
{
    string name;
    cout << "what's your name?" << endl;
    cin >> name;
    system("cls");
    cout << name << endl;
    string address;
    cout << "where are you living?" << endl;
    cin >> address;
    system("cls");
    cout << name << endl;
    cout << address << endl;
}

// 2.7.2 以long为单位距离，转换成码(一long等于220码)
void func1()
{
    long a = 0;
    cout << "单位为long,一long等于220码" << endl;
    cin >> a;
    cout << "转换成功:" << a * 220 << endl;
}

// 2.7.3 函数调用两次生成前两行 另一个函数调用两次，生成其他两行
void func2()
{
    for (int i = 0; i < 2; i++)
    {
        cout << "hello" << endl;
    }
    for (int j = 2; j < 4; j++)
    {
        cout << "world" << endl;
    }
}

// 2.7.4 输入年龄 显示包含几个月
void func3()
{
    int age = 0;
    cout << "Enter your age" << endl;
    cin >> age;
    system("cls");
    cout << age * 12 << endl;
}
int main()
{
    // func();
    // func1();
    // func2();
    func3();
    system("pause");
    return 0;
}