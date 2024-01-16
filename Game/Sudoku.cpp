#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    int num0 = rand() % 3 + 1;
    int num1 = rand() % 3 + 1;
    int num2 = rand() % 10 + 1;
    cout << num0 << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    system("pause");
    return 0;
}