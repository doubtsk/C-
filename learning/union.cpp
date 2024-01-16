// 三个类型，但是共用一块内存，也就是给三个中一个赋值，另外两个也会变
#include <iostream>
#include <string.h>
using namespace std;

union Myunion
{
    int idata;
    char chdata;
    float fdata;
} ustruct;
int main()
{
    ustruct.chdata = 'A';
    ustruct.fdata = 0.3;
    ustruct.idata = 100;
    cout << ustruct.chdata << endl;
    cout << ustruct.fdata << endl;
    cout << ustruct.idata << endl;
    cout << endl;
    ustruct.idata = 100;
    ustruct.fdata = 0.3;
    ustruct.chdata = 'A';
    cout << ustruct.idata << endl;
    cout << ustruct.fdata << endl;
    cout << ustruct.chdata << endl;
    cout << endl;
    ustruct.idata = 100;
    ustruct.chdata = 'A';
    ustruct.fdata = 0.3;
    cout << ustruct.idata << endl;
    cout << ustruct.chdata << endl;
    cout << ustruct.fdata << endl;
    cout << endl;
    system("pause");
    return 0;
}
