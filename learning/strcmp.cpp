#include <string.h>
#include <iostream>
using namespace std;
int main()
{
    char str1[30], str2[20];
    int i = 0;
    cout << "Enter a string: ";
    gets(str1);
    cout << "Enter a string: ";
    gets(str2);
    i = strcmp(str1, str2);
    if (i > 0)
    {
        cout << "String1 is bigger than String2";
    }
    else if (i < 0)
    {
        cout << "String1 is smaller than String2";
    }
    else
    {
        cout << "String1 is equal to String2";
    }
    system("pause");
    return 0;
}
// strcmp只会比较字符串的第一个字母 