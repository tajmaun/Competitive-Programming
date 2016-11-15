#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    node * first; node * second;
    node (node * a, node * b){first=a; second=b;}
};
int ans=0;
node * root = new node (NULL, NULL);
void insert (node * x, int bits, int pos)
{
    if (pos==-1) return;
    if ((1<<pos)&bits)
    {

        if (x->second==NULL)
        {
            x->second=new node (NULL, NULL);
        }
        insert(x->second, bits, pos-1);
    }
    else
    {
        if (x->first==NULL)
        {
            x->first=new node (NULL, NULL);
        }
        insert(x->first, bits, pos-1);
    }
}
void query (node * t, int a, int pos)
{
  if (pos==-1) return;
  int p=(1<<pos)&a;
  if ((1<<pos)&a)
  {
      if (t->first==NULL)
      {
          query (t->second, a, pos-1);
      }
      else
      {
          if(a==8)
    cout<<p<<" "<<pos<<endl;
          ans+=pow(2, pos); query (t->first, a, pos-1);
      }
  }
  else
  {
      if (t->second==NULL)
      {
          query(t->first, a, pos-1);
      }
      else
      {
          if(a==8)
    cout<<p<<" "<<pos<<endl;
          ans+=pow(2, pos); query(t->second, a, pos-1);
      }
  }
}
main()
{
     int a; scanf("%lld", &a);
   /*  int leng=31;
     for (int g=0; g<a; g++)
     {
         int n;
         scanf("%d",&n);
         insert(root, n , leng);

     }

     query(root, 4 , leng, ans);
     cout<<ans<<endl;*/
     for (int g=0; g<a; g++)
     {
         int curxor=0, anss=0;
         int b; scanf("%lld", &b);vector <int> t; int leng=31;
         insert(root, 0, leng);
         for (int y=0;y<b; y++)
         {
              ans=0;
             int c; scanf("%lld", &c); curxor^=c; insert(root, curxor, leng);query(root, curxor, leng),anss=max(anss,ans);
            // cout<<curxor<<endl;
         }
       /*  for (int y=0;y<t.size(); y++)
         {
            insert(root, t[y], leng); int ans=0;
            anss=max(anss, ans);
         }cout << anss << ' ';
         int y=6^9;*/
         cout<<anss<<endl;
         root=new node (NULL, NULL);
     }
     return 0;
}
