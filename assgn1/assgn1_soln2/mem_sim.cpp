/* Cache Hit and Miss problem
 * Author: Kumar Ayush
 * Date: 21 Jan 2016
 */

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    int n;  //number of pages
    int p;  //number of page frames in memory
    int m;  //number of references

    cin >> n >> p >> m;

    int *counts;    //store number of references for each page id
    counts = new int[n+1];
    for(int i = 1;i<=n;i++)
        counts[i]=0;

    list<int> L;

    int count_hit = 0,count_miss = 0;   //the hit and miss counts

    int m_ref;  //the variable to hold the page id being referenced
    for(int i = 0;i<m;i++)
    {
        cin >> m_ref;   //input the reference    
        //check if element in list
        if(find(L.begin(),L.end(),m_ref)==L.end())
        {
            cout << *find(L.begin(),L.end(),m_ref) << " " << *(L.end()) << endl;
            cout << L.size() << endl;
            //we missed
            count_miss++;  

            //check if list is full
            if(L.size()<p) 
            {
                //we can still push
                L.push_back(m_ref);
                counts[m_ref]++;
            }
            else
            {
                //we need to swap
            }
        }
        else
        {
            count_hit++;    //we hit something
            counts[m_ref]++; //re-referenced
        }
    }

    cout << count_hit << endl << count_miss << endl;
    return 0;
}
