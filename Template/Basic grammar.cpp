#include <iostream>
using namespace std;
template <class T>
void mySwape(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void test()
{
    cout << "调用" << endl;
}

int main()
{
    int a = 4;
    int b = 9;
    mySwape(a, b);
    cout << b << endl;
    test<int>(); // 必须指定T数据类型才能使用
    system("pause");
    return 0;
}
