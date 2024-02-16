#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(34);
    v.push_back(45);
    v.push_back(12);
    vector<int>::iterator begin = v.begin();
    vector<int>::iterator end = v.end();

    while (begin != end)
    {
        cout << *begin << endl;
        begin++;
    }
    system("pause");
    return 0;
}