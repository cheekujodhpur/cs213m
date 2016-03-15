#include <iostream>
#include "minMaxHeap.hpp"
using namespace std;

int main()
{
    int n;
    cin >> n;
    MinMaxHeap<int> foo;
    int temp;
    for(int i = 0;i<n;i++)
    {
        cin >> temp;
        foo.insert(temp);
    }
    foo.print();
    return 0;
}
