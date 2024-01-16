#include <iostream>
#include <string.h>
using namespace std;
struct PersonInfo
{
    int index;
    char name[30];
    short age;
};
void ShowStructMessage(struct PersonInfo MyInfo)//将结构体作为函数参数
{
    cout << MyInfo.age << endl;
    cout << MyInfo.index << endl;
    cout << MyInfo.name << endl;
}
int main()
{
    PersonInfo PInfo;
    PInfo.index = 1;
    strcpy(PInfo.name, "张三");
    PInfo.age = 18;
    ShowStructMessage(PInfo);
    system("pause");
    return 0;
}