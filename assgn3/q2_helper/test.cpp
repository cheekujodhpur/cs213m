#include <iostream>
using namespace std;

int main()
{
    int n=30;
    int res = (n==32? 0xffffffff : (1<<n)-1);
    cout << res << endl;
    return 0;
}
