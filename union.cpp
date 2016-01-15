#include <iostream>
using namespace std;

int main()
{
    union test
    {
        int i;
        char c;
        float x;
        int* p;
    };  //defines a union
    int j;
    test data;
    //declares a type
    cout << "size of union " << sizeof(data) << endl;
    cout << "give an integer: ";
    cin >> j;
    cout << "input value is :" << j << endl;
    data.i = j;
    cout << "interperet as integer : " << data.i << endl;
    cout << "interpret as character : " << data.c << endl;
    cout << "interpret as float : " << data.x << endl;
    cout << "interpret as pointer : " << data.p << endl;

    return 0;

}
