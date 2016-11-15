/*
author: Taj Maun Kamal
*/
//Find the centroid of tree
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
vector<LL>k[100005],A[200005];
LL n;
char res[200005];
LL q[200005];
/* method to setup subtree sizes and nodes in current tree */
LL dfss(LL v, LL f)
{
    if(res[v])return 0;
    q[v]=1;
    for(LL i=0; i<k[v].size(); ++i)
    {
        LL s=k[v][i];
        if(s==f)continue;
        q[v]+=dfss(s,v);
    }
    return q[v];
}
LL centroid(LL v)
{
    LL m=q[v],f=-1;
    while(1)
    {
        LL s=-1;
        for(LL i=0; s<0&&i<k[v].size(); ++i)
        {
            if(res[k[v][i]]||k[v][i]==f)continue;
            if(2*q[k[v][i]]>=m)s=k[v][i];
        }
        if(s<0)break;
        f=v;
        v=s;
    }
    return v;
}
int main()
{

    cin>>n;
    for(LL i = 1 ; i <= n-1 ; ++i)
    {
        LL u,v;
        cin>>u>>v;
        k[u].push_back(v);
        k[v].push_back(u);
    }

    dfss(1,-1);
    LL  cn=centroid(1);
    return 0;
}
