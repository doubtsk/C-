// 文件操作 写文件
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ofstream file;
    file.open("C:\\C--\\file\\test.txt", ios::out | ios::trunc); // 使用ofstream打开文件
    file << "hello world";                                       // 向文件中写入数据
    file.close();                                                // 关闭文件
    system("pause");
    return 0;
}