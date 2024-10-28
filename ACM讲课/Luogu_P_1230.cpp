#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int m;
    cin>>m;
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i].second;
    }
    sort(a.begin(),a.end(),[](pair<int,int> a,pair<int,int> b){
        if(a.second==b.second)return a.first<b.first;
        return a.second>b.second;
    });
    vector<bool> vis(n+1);
    for(auto [t,w]:a)
    {
        while(vis[t]&&t>0)
        {
            t--;
        }
        if(t==0)m-=w;
        else vis[t]=true;
    }
    cout<<m<<'\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
system("pause");
#endif
    return 0;
}
