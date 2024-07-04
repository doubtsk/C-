#include <iostream>
#include<windows.h>
using namespace std;

// 3.7.1
void func1()
{
    int height;
    const int conversion = 12;
    cout << "Enter your height:__\b\b";
    cin >> height;
    cout << "You are " << height / conversion << " feet and " << height % conversion << " inches high.";
}

// 3.7.2
void func2()
{
    double feet = 0;
    double inches = 0;
    double weight = 0;
    const int Fconversion = 12;
    const double Mconversion = 0.0254;
    const double Wconversion = 2.2;
    cout << "Enter your height(feet.inch)" << endl;
    cin >> feet;
    Sleep(3000);
    system("cls");
    cout << feet * Fconversion << "inches" << endl;
    cout << "Enter your weight(pound)" << endl;
    cin >> weight;
    Sleep(3000);
    system("cls");
    cout << weight / Wconversion <<"kilograms"<< endl;
    Sleep(3000);
    system("cls");
}
int main()
{
    //func1();
    func2();
    system("pause");
    return 0;
}
