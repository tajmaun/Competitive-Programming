#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int cost[50];
int arr[50];
int wr[100];
int dp[1001][500][500];
int n,m,m1;
int pass(int i,int w,int w1)
{
    if(i==n)
        return 0;
    int p1,p2;
    if(dp[i][w][w1]!=-1)
        return dp[i][w][w1];
    if(w+arr[i]<=m && w1+wr[i]<=m1)
    {
        p1=cost[i]+pass(i+1,w+arr[i],w1+wr[i]);
    }
    else
        p1=0;
    p2=pass(i+1,w,w1);
    int l=max(p1,p2);
    return dp[i][w][w1]=l;
}
main()
{
    memset(dp,-1,sizeof(dp));
    cin>>m>>m1;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i]>>cost[i]>>wr[i];
    }
    cout<<pass(0,0,0)<<endl;
}
