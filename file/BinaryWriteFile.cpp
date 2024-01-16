// 二进制打开文件并写入
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person
{
public:
    char name[64];
    int m_Age;
};

void test01()
{
    ofstream ofs("person.txt", ios::out | ios::binary);
    Person p = {"张三", 18};
    ofs.write((const char *)&p, sizeof(Person));
    ofs.close();
}

int main()
{
    test01();
    system("pause");
    return 0;
}