/*数组排序
从大到小
选择算法
测试char数组、int数组
*/
#include <iostream>
#include <algorithm>
using namespace std;

template <class C> // 交换函数模板
void mySwape(C &a, C &b)
{
    C temp = a;
    a = b;
    b = temp;
}

template <class T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i; // 认定最大值
        for (int j = i + 1; j < len; j++)
        {
            if (arr[max] < arr[j]) // 若认定的最大值比遍历出的数值小，说明j下标才是最大值
            {
                max = j; // 更新最大值
            }
        }
        if (max != i)
        {
            mySwape(arr[max], arr[i]); // 交换max和i的元素
        }
    }
}

template <class A>
void mysort1(A arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
            if (min != i)
            {
                mySwape(arr[min], arr[i]);
            }
        }
    }
}



template <class P>
void printArry(P arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void test1()
{
    char charArry[] = "fcasde";
    int num = sizeof(charArry) / sizeof(char);
    mySort(charArry, num);
    printArry(charArry, num);
}
void test2()
{
    int intArry[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int num = sizeof(intArry) / sizeof(int);
    mysort1(intArry, num);
    printArry(intArry, num);
}
int main()
{
    // test1();
    test2();
    system("pause");
    return 0;
}