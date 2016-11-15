#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
#define REP(I,N)   FOR(I,0,N)
#define pb push_back
#define LL long long
LL limit=500000;
int main()
{

 freopen("inp.txt","r",stdin);
 freopen("out.txt","w",stdout);
 int t;
 cin>>t;
 for(int j=1;j<=t;j++)
 {
     LL n;
     cin>>n;
     cout<<"Case #"<<j<<": ";
     if(!n)
     {
        cout<<"INSOMNIA"<<endl;
        continue;
     }
     std::map<int,int>mp;
     LL p=n;
     int i=1;
     LL x=n;

     while(p)
     {
         if(mp.size()==10)
         {
            cout<<n<<endl;
            break;
         }
         LL d=p;
         n=p;
        // cout<<n<<endl;
         while(d)
         {

             mp[d%10]++;
             d/=10;
         }
         p=(i+1)*x;
         i++;
     }


 }

  return 0;
  }
