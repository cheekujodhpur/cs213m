#include <iostream>
#include "minMaxHeap.hpp"
using namespace std;

class FivePred:public Predicate<int>
{
    bool toDelete(int a)
    {
        return ((a%5==0));
    }
};

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
    foo.deleteMin();
    foo.print();
    foo.deleteMax();
    foo.print();
    foo.deleteMax();
    foo.print();
    foo.deleteMin();
    foo.print();
    FivePred predObj;
    foo.deleteElems(predObj);
    foo.print();
    return 0;
}
