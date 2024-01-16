#include <iostream>
using namespace std;
template <class type>
type sum(type xvale, type yvale)
{
    return xvale + yvale;
}// 创建了一个加法模板

int main()
{
    cout << "x的值" << endl;
    int x = 0;
    cin >> x;
    cout << "y的值" << endl;
    int y = 0;
    cin >> y;
    int Sum = sum(x, y);
    cout << Sum << endl;
    system("pause");
    return 0;
}