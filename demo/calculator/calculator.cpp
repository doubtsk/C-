#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

int num1;
int num2;

class Calculator
{
public:
    int num1;
    int num2;
    virtual ~Calculator(){};
    virtual float GetResult()
    {
        return 0;
    }
};
// 加
class Addcalculator : public Calculator
{
    virtual float GetResult()
    {
        return num1 + num2;
    }
};
// 减
class Subcalculator : public Calculator
{
    virtual float GetResult()
    {
        return num1 - num2;
    }
};
// 乘
class Mulcalculator : public Calculator
{
    virtual float GetResult()
    {
        return num1 * num2;
    }
};
// 除
class Exccalculator : public Calculator
{
    virtual float GetResult()
    {
        return num1 / num2;
    }
};
// 开根号
class RadicalCalculator : public Calculator
{
    virtual float GetResult()
    {
        cin >> num1;
        int result;
        if (num1 < 0)
        {
            cout << "错误" << endl;
            GetResult();
        }
        else
        {
            result = sqrt(num1);
        }
        return result;
        cout << "答案是" << result << endl;
    }
};

// 开立方根

// 自定义多少次方
class PowerCalculator : public Calculator
{
    virtual float GetResult()
    {
        cout << "底数是 " << endl;
        cin >> num1;
        int i = 0;
        cout << "指数是 " << endl;
        return pow(num1, i);
    }
};
int main()
{
    char op;
    cout << "请选择操作：\n";
    cout << "1:加法\n";
    cout << "2:减法\n";
    cout << "3:乘法\n";
    cout << "4:除法\n";
    cout << "5:开根号\n";
    cout << "6:自定义次方\n";
    cout << "7:退出\n";
    cout << "请输入操作符：";
    cin >> op;
    while (op != 'q')
    {
        switch (op)
        {
        case '+':
            Calculator *add = new Addcalculator;
            cin >> add->num1;
            cin >> add->num2;
            cout << "答案是 " << add->GetResult() << endl;
            delete add;
            break;
        case '-':
            Calculator *sub = new Subcalculator;
            cin >> sub->num1;
            cin >> sub->num2;
            cout << "答案是 " << sub->GetResult() << endl;
            delete sub;
            break;
        case '*':
            Calculator *mul = new Mulcalculator;
            cin >> mul->num1;
            cin >> mul->num2;
            cout << "答案是 " << mul->GetResult() << endl;
            delete mul;
            break;
        case '/':
            Calculator *exp = new Exccalculator;
            cin >> exp->num1;
            cin >> exp->num2;
            cout << "答案是 " << exp->GetResult() << endl;
            delete exp;
            break;
        case 'r':
            Calculator *radi = new RadicalCalculator;
            cin >> radi->num1;
            cout << "答案是 " << endl;
            delete radi;
            break;
        case 'p':
            Calculator *power = new PowerCalculator;
            cin >> power->num1;
            cout << "答案是 " << endl;
            delete power;
            break;
        case 'q':
            break;
        }
    }
    system("pause");
    return 0;
}