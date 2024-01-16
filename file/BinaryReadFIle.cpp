#include <fstream>
#include<iostream>
using namespace std;
class Person
{
public:
    char m_Name[64];
    int m_Age;
};

void test01()
{
    ifstream ifs("person.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "打开失败!" << endl;
        return;
    }
    Person p;
    ifs.read((char *)&p, sizeof(Person));
    std::cout << "姓名: " << p.m_Name << " 年龄 " << p.m_Age << std::endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}