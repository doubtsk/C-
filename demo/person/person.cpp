#include <iostream>
#include <string.h>
#include "person.h" //将类相关的声明放在了person.h头文件中

using namespace std;

person::person() // 这个类的名字也是一个构造函数，可以用来初始化某些值
{
    index = 0;
    age = 0;
    salary = 0;
}

int person::getindex()
{
    return index;
}

int person::setindex(int mindex)
{
    index = mindex;
    return 0;
}

short person::getage()
{
    return age;
}

short person::setage(short mage)
{
    age = mage;
    return 0;
}

char *person::getname()
{
    return name;
}

char person::setname(char mname[30])
{
    strcpy(name, mname);
    return 0;
}

int person::getsalary()
{
    return salary;
}

int person::setsalary(int msalary)
{
    salary = msalary;
    return 0;
}
