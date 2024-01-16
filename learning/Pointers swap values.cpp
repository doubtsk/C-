#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x, y;
    int *p_x;
    int *p_y;
    cout << "输入两个值" << endl;
    cin >> x;
    cin >> y;
    cout << endl;
    p_y = &y;
    p_x = &x;
    swap(p_x, p_y);
    cout << x << endl;
    cout << y << endl;
    cout << endl;
    swap(x, y);
    cout << x << endl;
    cout << y << endl;
    system("pause");
    return 0;
}