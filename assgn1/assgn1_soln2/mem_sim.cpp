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
    counts = new int[2*n+1];
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
            //we missed
            count_miss++;  

            //check if list is full
            if(L.size()<p) 
            {
                //we can still push
                L.push_back(m_ref);
                counts[m_ref]++;
                counts[n+m_ref]=i;
            }
            else
            {
                list<int>::iterator ptr,min_ptr;
                min_ptr = L.begin();
                for(ptr=L.begin();ptr!=L.end();ptr++)
                {
                    //lfu
                    if(counts[*min_ptr]>counts[*ptr])
                    {
                        min_ptr=ptr;
                    }
                    else if(counts[*min_ptr]==counts[*ptr])
                    {
                        //lru
                        if(counts[n+*min_ptr]>counts[n+*ptr])
                            min_ptr=ptr;
                    }
                }
                //we need to swap
                *min_ptr=m_ref;
                counts[m_ref]++;
                counts[n+m_ref]=i;
            }
        }
        else
        {
            count_hit++;    //we hit something
            counts[m_ref]++; //re-referenced
            counts[n+m_ref]=i;
        }
    }

    cout << count_hit << endl << count_miss << endl;
    return 0;
}
