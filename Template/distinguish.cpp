/*��ͨ�����ͺ���ģ�������
1����ͨ�������ÿ����Զ���������ת��
2������ģ�� ���Զ������Ƶ��������Խ����Զ�����ת��
3������ģ�� ����ʾָ�����ͣ����Խ����Զ�����ת��*/
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
    cout << myAdd1(a, c); // ��ͨ���������Զ���������ת��
    // cout << myAdd2(a, c) << endl;����������˺���ģ�����Զ������Ƶ��������Խ����Զ�����ת��
    cout << myAdd2<int>(a, c); // ����ƶ������ͣ��Ϳ��Խ����Զ�����ת��
    getchar();
    return 0;
}