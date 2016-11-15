#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <stack>
#include<queue>
using namespace std;
#define REP(I,N)   FOR(I,0,N)
#define pb push_back
#define LL long long
#define ff first
#define ss second

LL M=1000000;
LL mod=1e9 + 7;
int prime[1000000 +5 ];

void seive()
{
    for(int i=2; i<=M; ++i)
    {
        if(prime[i]==0)
        {
            for(int j=2*i; j<=M; j+=i)
            {
                prime[j] = 1;
            }
        }
    }
}
int main()
{
    seive();
    LL n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        LL f = sqrt(m);
        if(!prime[f] && f*f == m)
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
