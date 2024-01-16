// vector存放自定义数据类型
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class person
{
public:
    person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};

void test01()
{
    vector<person> v;
    person p1("aaa", 10);
    person p2("bbb", 20);
    person p3("ccc", 30);
    person p4("ddd", 40);
    person p5("eee", 50);
    // 尾插数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p4);
    // 遍历数据
    for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名 " << it->m_name << " 年龄 " << it->m_age << endl;
    }
}

void test02()
{
    vector<person *> v;

    person p1("aaa", 10);
    person p2("bbb", 20);
    person p3("ccc", 30);
    person p4("ddd", 40);
    person p5("eee", 50);
    // 尾插数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p4);
    for (vector<person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "指针姓名" << (*it)->m_name << "指针年龄" << (*it)->m_age << endl;
    }
}

int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}