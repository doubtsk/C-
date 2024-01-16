#include <iostream>
using namespace std;
void transform(int day)
{
    switch (day)
    {
    case 1:
        cout << "monday" << endl;
        break;
    case 2:
        cout << "tuesday" << endl;
        break;
    case 3:
        cout << "wednesday" << endl;
        break;
    case 4:
        cout << "thursday" << endl;
        break;
    case 5:
        cout << "friday" << endl;
        break;
    case 6:
        cout << "saturday" << endl;
        break;
    }
}
int main()
{
    enum weekend
    {
        sunday = 7,
        monday = 1,
        tuesday = 2,
        wednesday = 3,
        thursday = 4,
        friday = 5,
        saturday = 6
    };
    int a = 2;
    int b = 1;
    weekend day;
    day = (weekend)a;
    transform(day);
    // cout << day << endl;
    day = (weekend)(a - b);
    transform(day);
    // cout << day << endl;
    day = (weekend)(monday + thursday);
    transform(day);
    // cout << day << endl;
    day = (weekend)5;
    transform(day);
    // cout << day << endl;
    system("pause");
    return 0;
}