#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100005
struct mn
{
    int value;
    int sum;
};
int array[N];
mn tree[3*N-1];

void segment(int p,int q,int l)
{

    if(p==q)
    {
        tree[l].sum=array[p];

        return;
    }
    int mid=(p+q)>>1;
    int lt=l<<1;
    int rt=(l<<1)+1;
    segment(p,mid,lt);
    segment(mid+1,q,rt);
    tree[l].value=0;
    tree[l].sum=tree[rt].sum + tree[lt].sum;

}

void update(int p,int q,int l,int x,int y,int cost)
{
    if(q<x || p>y)
        return;
    if(p>=x && q<=y)
    {
       // cout<<cost<<endl;
        tree[l].value=cost;
        tree[l].sum+=(q-p+1)*cost;
        return;
    }
    int mid=(p+q)>>1;
    int lt=l<<1;
    int rt=(l<<1)+1;
    update(p,mid,lt,x,y,cost);
    update(mid+1,q,rt,x,y,cost);
    tree[l].sum=tree[lt].sum +tree[rt].sum;
}

int search(int p,int q,int l,int x,int y,int carry)
{

    if(q<x || p>y)
        return 0;
    if(p>=x && q<=y)
    {
        return tree[l].sum+(q-p+1)*carry;
    }
    int sum=0;
    int mid=(p+q)>>1;
    int lt=l<<1;
    int rt=(l<<1)+1;
    int a=search(p,mid,lt,x,y,carry+tree[l].value);
    int b=search(mid+1,q,rt,x,y,carry+tree[l].value);
    return sum=a+b;
}
main()
{
    int m;
    scanf("%d",&m);
    for(int i=1; i<=m; i++)
    {
        int n,p;
        scanf("%d %d",&n,&p);
          memset(array,0,n*sizeof(int));
          segment(1,n,1);
          printf("Case %d:\n",i);
          for(int i=1;i<=p;i++)
          {
              int a,b,c,d;
              scanf("%d",&a);
              if(!a)
              {

                      scanf("%d %d %d",&b,&c,&d);
                      update(1,n,1,b+1,c+1,d);

              }
              else
              {

                       scanf("%d %d",&b,&c);
                       printf("%d\n",search(1,n,1,b+1,c+1,0));

              }
          }
    }
return 0;
}
