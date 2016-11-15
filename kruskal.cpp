#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<string>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define PI acos(-1.0)
#define SQ(x) ((x)*(x))
#define CUBE(x) ((x)*(x)*(x))
#define MX 10000
#define MAX_INT 2147483647
#define inf 1<<28
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define REP(i,n) for(i=0;i<n;i++)
using namespace std;
struct edge
{
    int u,v,w;
    bool operator < ( const edge& p ) const
    {
        cout<<w<<" "<<p.w<<endl;
        return w < p.w;
    }
};
int pr[MX];
vector<edge>e;
int find(int r)
{
   return (pr[r]==r) ? r:  find(pr[r]);
}
int mst(int n)
{
    sort(e.begin(),e.end());
    for(int i=1;i<=n;i++)pr[i]=i;
    int sum=0;
    for(int i=0;i<(int)e.size();i++)
    {
        cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
     //  sum+=e[i].w;
    }

    int count=0,s=0;
    for(int i=0;i<(int)e.size();i++)
    {
        int u=find(e[i].u);
        int v=find(e[i].v);
        if(u!=v)
        {
            pr[u]=v;
            count++;
            s+=e[i].w;
            if(count==n-1) break;
        }
    }
    return s;
}

int main(){
//  READ("in");
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge get;
        get.u=u; get.v=v; get.w=w;
        e.push_back(get);
    }
    cout<<mst(n)<<endl;
    return 0;

}
