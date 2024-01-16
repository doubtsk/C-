/*普通函数和函数模板的区别
1，普通函数调用可以自动进行类型转换
2、函数模板 用自动类型推导，不可以进行自动类型转换
3、函数模板 用显示指定类型，可以进行自动类型转换*/
#include <iostream>
using namespace std;
int myAdd1(int a, int b)
{
    return a + b;
}
template <typename T>
T myAdd2(int a, int b)
{
    return a + b;
}
int main()
{
    int a = 10;
    char c = 'c';
    cout << myAdd1(a, c); // 普通函数调用自动进行类型转换
    // cout << myAdd2(a, c) << endl;这里就体现了函数模板用自动类型推导，不可以进行自动类型转换
    cout << myAdd2<int>(a, c); // 如果制定了类型，就可以进行自动类型转化
    getchar();
    return 0;
}