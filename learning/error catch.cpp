#include <string.h>
#include <iostream>
using namespace std;
class CcustomError
{
private:
    int my_errorID;
    char m_error[225];

public:
    CcustomError()
    {
        my_errorID = 1;
        strcpy(m_error, "错误");
    }
    int getErrorId()
    {
        return my_errorID;
    }
    char *Geterror()
    {
        return m_error;
    }
};
int main()
{
    try
    {
        // throw(new CcustomError());
        throw "啊？";
    }
    catch (CcustomError *error)
    {
        // 输出异常信息
        cout << "异常ID= " << error->getErrorId() << endl;
        cout << "异常信息" << error->Geterror() << endl;
    }
    catch (char *error)
    {
        cout << "??" << error << endl;
    }
    catch (...) // catch(...)可以处理任何错误的语句
    {
        cout << "鬼知道哪出错了" << endl;
    }

    system("pause");
    return 0;
}