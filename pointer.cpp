#include <iostream>
using namespace std;

int main()
{
    float f = 0.0;
    int i = 5;
    f = (float)i;
    cout << f << endl; // 5
    f = *(float *)&i;
    cout << f << endl; // 7.00649e-45
    return 0;
}