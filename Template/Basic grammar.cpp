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
    cout << "����" << endl;
}

int main()
{
    int a = 4;
    int b = 9;
    mySwape(a, b);
    cout << b << endl;
    test<int>(); // ����ָ��T�������Ͳ���ʹ��
    system("pause");
    return 0;
}
