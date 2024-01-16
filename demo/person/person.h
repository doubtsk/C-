class person
{
public:
    int index;
    short age;
    char name[30];
    int salary;

    // 成员函数
    person(); // 这个就是一个构造函数，也可以忽略不写
    int getindex();
    int setindex(int mindex);
    short getage();
    short setage(short mage);
    char *getname();
    char setname(char mname[30]);
    int getsalary();
    int setsalary(int msalary);
};