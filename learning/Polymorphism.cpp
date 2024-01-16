#include <iostream>
using namespace std;
class animal
{
public:
    // 虚函数
    void speak()
    {
        cout << "动物在说话" << endl;
    }
};
class cat : public animal
{
public:
    virtual void speak()
    {
        cout << "小猫在说话" << endl;
    }
};
class dog : public animal
{
    virtual void speak()
    {
        cout << "小狗在说话" << endl;
    }
};

// 地址早绑定，在编译阶段确定函数地址
void DoSpeak(animal &animal)
{
    animal.speak();
}

void test1()
{
    cat Cat;
    dog Dog;
    DoSpeak(Cat);
    DoSpeak(Dog);
}

void test2()
{
    cout << "sizeof = " << sizeof(animal) << endl;
}
int main()
{
    test1();
    test2();
    system("pause");
    return 0;
}