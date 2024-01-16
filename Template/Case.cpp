/*��������
�Ӵ�С
ѡ���㷨
����char���顢int����
*/
#include <iostream>
#include <algorithm>
using namespace std;

template <class C> // ��������ģ��
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
        int max = i; // �϶����ֵ
        for (int j = i + 1; j < len; j++)
        {
            if (arr[max] < arr[j]) // ���϶������ֵ�ȱ���������ֵС��˵��j�±�������ֵ
            {
                max = j; // �������ֵ
            }
        }
        if (max != i)
        {
            mySwape(arr[max], arr[i]); // ����max��i��Ԫ��
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