#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void test01()
{
    ifstream ifs;
    ifs.open("C:\\C--\\file\\test.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "打开文件失败" << endl;
        return;
    }
    // 第一种
    //  char buf[1024] = {0};
    //  while (ifs >> buf)
    //  {
    //      cout << buf << endl;
    //  }

    // 第二种
    //  char buf[1024] = {0};
    //  while (ifs.getline(buf, sizeof(buf)))
    //  {
    //      cout << buf << endl;
    //  }

    // 第三种
    // string buf;
    // while (getline(ifs, buf))
    // {
    //     cout << buf << endl;
    // }

    // 第四种
    // char c;
    // while ((c = ifs.get()) != EOF)//end of file
    // {
    //     cout << c;
    // }
    ifs.close();
}
int main()
{
    test01();
    system("pause");
    return 0;
}