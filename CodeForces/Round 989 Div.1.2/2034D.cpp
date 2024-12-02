#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    set<int> s0,s1,s2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i]==0)s0.insert(i);
        else if(a[i]==1)s1.insert(i);
        else s2.insert(i);
    }
    int n0=s0.size(),n1=s1.size(),n2=s2.size();
    vector<pair<int,int>> ans;
    for(int i=n;i>n-n2;i--)
    {
        if(a[i]==0)
        {
            int x=*s1.begin();
            int y=*s2.begin();
            s1.erase(x);
            s2.erase(y);
            ans.push_back({x,i});
            ans.push_back({y,i});
            a[x]=0;
            a[y]=1;
            s1.insert(y);
        }
        else if(a[i]==1)
        {
            int x=*s2.begin();
            s2.erase(x);
            ans.push_back({x,i});
            a[x]=1;
            s1.insert(x);
        }
    }
    for(int i=n-n2;i>n-n2-n1;i--)
    {
        if(a[i]==0)
        {
            int x=*s1.begin();
            s1.erase(x);
            ans.push_back({x,i});
            a[x]=0;
        }
    }
    cout<<ans.size()<<'\n';
    for(auto &[x,y]:ans)
    {
        cout<<x<<' '<<y<<'\n';
    }
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
system("pause");
#endif
    return 0;
}
