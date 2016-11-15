#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <stack>
using namespace std;
#define REP(I,N)   FOR(I,0,N)
#define pb push_back
#define LL long long
LL limit=500000;

string ft(int f,string g)
{
    string d="";
    for(int i=0;i<=f;i++)
    {
        if(g[i]=='+')
            d+='-';
        else
                break;
    }
    return d;
}
string ht(int f,string g)
{
    string d="";
    for(int i=0;i<=f;i++)
    {
        if(g[i]=='-')
            d+='+';
        else
                break;
    }
    return d;
}

int main()
{

 freopen("inp.txt","r",stdin);
 freopen("out.txt","w",stdout);
 int t;
 cin>>t;
 for(int j=1;j<=t;j++)
 {
     LL n;
     string s;
     cin>>s;
     //cout<<s<<endl;
     cout<<"Case #"<<j<<": ";

     int p=s.size();
     stack<char>q;
     int k=0;
     while(q.size()!=p)
     {
        // cout<<s<<endl;

        string x="",d="";
        int i=s.size()-1;
        for(;i>=0;i--)
        {
            if(s[i]=='+')
                q.push(s[i]);
            else
                break;
        }
        for(;i>=0;i--)
        {
            if(s[i]=='-')
               x+=s[i];
            else
                break;

        }
       // cout<<x<<endl;
        if(i<0)
        {
           for(int l=0;l<x.size();l++)
               d+='+';
        }
       else if(s[0]=='-')
        {

             int l=0;
            for(;l<=i;l++)
            {


                if(s[l]=='-')
                   d+='+';
                else
                   break;
            }
             for(;l<=i;l++)
                d+=s[l];
             d+=x;
        }
        else if(s[0]=='+')
        {

             int l=i;
            for(;l>=0;l--)
            {
                if(s[l]=='-')
                   d+='+';
                else
                   d+='-';
            }
           d+=x;
        }

        s=d;

        k++;

       // cout<<s<<endl;

     }

     cout<<k-1<<endl;
 }
 return 0;
}
