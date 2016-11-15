#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
#define NIN(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define NINJ(i,n) for((i)=1;(i)<=(int)(n);(i)++)
#define pb push_back
#define LL long long
main()
{
    vector<int>v[100000];
    int m,n;
    cin>>m>>n;
    int i;
    int dir[100000]= {0};
    int sz=sizeof(dir)/sizeof(int);
    NIN(i,n)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        dir[y]++;
    }
    queue<int>q,p;
    NINJ(i,m)
    {
        if(!dir[i])
            q.push(i);

    }
    while(!q.empty())
    {
        int m=q.front();
        p.push(m);
        q.pop();
        NIN(i,v[m].size())
        {
            int d=v[m][i];
            dir[d]--;
            if(!dir[d])
                q.push(d);

        }
    }
    while(!p.empty())
    {
        cout<<p.front()<<endl;
        p.pop();
    }
    return 0;
}
