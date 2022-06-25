#include<bits/stdc++.h>
using namespace std;
struct node
{
    string a,b;
    int w;
};
bool comp(node a,node b)
{
    if(a.w<b.w)return true;
    else return false;
}
struct node ar[100005];
map<string,string>parent;
string findd(string a)
{
    if(parent[a]==a)return a;
    else
        return parent[a]=findd(parent[a]);
}
void unionn(string a,string b)
{
    parent[a]=b;
}
int main()
{
    int t;cin>>t;
    for(int k=1;k<=t;k++)
    {
        int n;cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ar[i].a>>ar[i].b>>ar[i].w;
            parent[ar[i].a]=ar[i].a;
            parent[ar[i].b]=ar[i].b;
        }
        sort(ar,ar+n,comp);
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            string u=findd(ar[i].a);
            string v=findd(ar[i].b);
            if(u!=v)
            {
                unionn(u,v);
                sum+=ar[i].w;
            }
        }
       int cnt=0;
        for(auto x:parent)
        {
            string s1=x.first;
            string s2=x.second;
            if(s1==s2)cnt++;
        }
        printf("Case %d: ",k);
        if(cnt>1)cout<<"Impossible"<<endl;
        else cout<<sum<<endl;
        parent.clear();

    }
}
