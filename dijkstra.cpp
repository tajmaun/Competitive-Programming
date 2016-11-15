#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
#define inf 9999999999999
#define LL long long

vector<LL>v[200000],x[200000];
LL bfs(LL s);
unsigned LL d[200000];
struct mn
{
    LL vt,ucost;
    bool operator < (const mn& p) const
    {
        cout<<ucost<<"  " <<vt<<" "<<p.vt<<"  "<<p.ucost<<endl;
        return ucost>p.ucost;
    }
};
void bfs(LL s,int vi[])
{
    priority_queue<mn>q;
    for (LL i=1;i<=50000;i++)
        d[i]=inf;
    d[s]=0;
    mn k,m;
    m.vt=s;
    m.ucost=0;
    q.push(m);
    LL y=s;
    while (!q.empty())
    {
        m=q.top();
        LL p=m.vt;
        q.pop();
        for (LL i=0;i<v[p].size();i++)
        {
            k.vt =v[p][i];
            k.ucost=x[p][i]+d[p];
            if (d[k.vt]>k.ucost && !vi[v[p][i]])
            {
                d[k.vt]=k.ucost;
                q.push(k);
            }
            if (k.vt>y)
                y=k.vt;

        }
    }
}
LL powt(int n,int p)
{
    LL c=1;
    while(p--)
        c*=n;
    return c;
}
main()
{
    LL vtx,ed,s;
    scanf("%d %d",&vtx,&ed);
        bool t=true;
        for (LL i=0;i<ed;i++)
        {
            LL r1,r2,r3;
            cin>>r1>>r2>>r3;
            v[r1].push_back(r2);
            v[r2].push_back(r1);
            x[r1].push_back(powt(2,r3));
            x[r2].push_back(powt(2,r3));
            if (t)
            {
                s=r1;
                t=false;
            }
        }
    LL st=0;
    int vi[vtx+1];
    for(int i=1;i<=vtx;i++)
        vi[i]=0;
       for(int i=1;i<=vtx;i++)
       {
        bfs(i,vi);
        for(int j=i;j<=vtx;j++)
            st+=d[j];
        vi[i]=1;
       }
        //  for(LL j=0;j<=k;j++)
        cout<<st<<endl;

    return 0;
}


