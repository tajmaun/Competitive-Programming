#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;


const int MAXN = 100001, MOD = 1e9 + 7, sigma = 26;
int term[MAXN], len[MAXN], to[MAXN][sigma], link[MAXN], ta[MAXN],sz = 1;
void call()
{
    for(int i=0;i<MAXN;i++)
    {
        for(int j=0;j<26;j++)
            to[i][j]=0;
    }
    for(int i=0;i<MAXN;i++)
    {
        ta[i]=0;
    }
    for(int i=0;i<MAXN;i++)
    {
        link[i]=0;
    }
    sz=1;
}
void add_str(string s)
{
    int cur = 0;
    for (int i=0; s[i]; i++)
    {
        if (!to[cur][s[i] - 'a'])
        {
            to[cur][s[i] - 'a'] = sz++;
            len[to[cur][s[i] - 'a']] = len[cur] + 1;
        }
        cur = to[cur][s[i] - 'a'];
    }
    term[cur] = cur;
    ta[cur]=1;
}

void push_links()
{
    int que[sz];
    int st = 0, fi = 1;
    que[0] = 0;
    int d=0;
    while (st < fi)
    {

        int V = que[st++];
        int U = link[V];
        // cout<<"\n"<<d<<" V= "<<V<<" U= "<<U<<"\n\n";
        if(ta[U])
        {
            ta[V]++;
            //   cout<<"YES "<<ta[V]<<endl;

        }

        if (!term[V])
        {
            //cout<<"V= "<<V<<" U= "<<U<<"\n\n";
            term[V] = term[U];
            //cout<<term[V]<<"  "<<term[U]<<"\n\n";
        }
        // cout<<"\n"<<d<<" V= "<<V<<" U= "<<U<<"\n\n";


        for (int c = 0; c < sigma; c++)
            if (to[V][c])
            {
                char ch=c+'a';
                // cout<<ch<<endl;
                //if(to[V][c]==6)
                // cout<<"U "<<U<<"  - "<<to[U][c]<<endl;
                link[to[V][c]] = V ? to[U][c] : 0;

                //cout<<"link : "<<to[V][c]<<" to "<<link[to[V][c]] <<endl;
                que[fi++] = to[V][c];
                // cout<<to[V][c]<<" "<<to[U][c]<<endl;
            }
            else
            {
                to[V][c] = to[U][c];
            }
        d++;
    }
}
int findN(int c, char nextInput)
{
    int answer = c;
    int p = nextInput - 'a';
    //while (to[answer][p] == -1) answer = link[answer];
    return to[answer][p];
}
main()
{
    /* int p=1<<3;
     //cout<<p<<endl;
     string M[4]={"woman","man","meat","animal"};//"atek"};
     for (int i=0;i<4;i++)
         add_str(M[i]);

     push_links();
    /*string text="manwomanetimeatek";//WOMANETIMEAT
     int c=0;
     int count=0;
     for (int i = 0; i < text.size(); ++i)
     {
         c = findN(c, text[i], 'a');
         cout<<ta[c]<<endl;
         count+=ta[c];
        /* if (term[c] == 0) continue; // Nothing new, let's move on to the next character.
         cout<<c<<" "<<"found"<<endl;
         if(term[link[c]])
         cout<<link[c]<<" "<<"found"<<endl;*/
    /* for (int j = 0; j < 4; ++j)
     {
         if (term[c] & (1 << j))   // Matched keywords[j]
         {
             cout << "Keyword " <<M[j] << " appears from "
             << i - M[j].size() + 1 << " to " << i << endl;
         }
     }
    }
    cout<<count<<endl;*/
    int n;
    cin>>n;
    for(int i=1; i<=n; i++ )
    {
        string s;
        cin>>s;
        int m;
        cin>>m;
        vector<string > v;
        for(int j=1; j<=m; j++)
        {
            string S;
            cin>>S;
            v.push_back(S);
        }
        call();
        for(int j=0; j<v.size(); j++)
        {
            add_str(v[j]);
        }
        push_links();
        int c=0;
        string f="",d="";
        map<string,int>mp;
        for(int j=0; j<s.size(); j++)
        {
            c = findN(c, s[j]);
            f+=s[j];
            if(link[c])
                d+=s[j];
            if(ta[link[c]])
                mp[d]++;
            if(ta[c])
                mp[f]++;
            //cout<<f<<" aaa "<<c<<" "<<link[c]<<endl;
            //cout<<d<<endl;
            if(c==0)
            {
                c=findN(c,s[j]);
                f="";
                d="";
                if(c)
                    f+=s[j];
            }
        }
        for(string G:v)
        {
            if(mp.find(G)!=mp.end())
                cout<<"y"<<endl;
            else
                cout<<"n"<<endl;
        }
        mp.clear();

    }


}
