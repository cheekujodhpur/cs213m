#include <iostream>
#include "minMaxHeap.hpp"
using namespace std;

int main()
{
    int n;
    cin >> n;
    MinMaxHeap<int> foo;
    pred predObj;
    int temp;
    for(int i = 0;i<n;i++)
    {
        cin >> temp;
        foo.insert(temp);
    }
    foo.print();
    foo.deleteMin();
    foo.print();
    foo.deleteMax();
    foo.print();
    foo.deleteMax();
    foo.print();
    foo.deleteMin();
    foo.print();
    foo.deleteElems(predObj);
    foo.print();
    return 0;
}
