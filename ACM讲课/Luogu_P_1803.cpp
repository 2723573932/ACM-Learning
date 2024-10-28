#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end(),[](pair<int,int> a,pair<int,int> b){
        if(a.second==b.second)return a.first>b.first;
        return a.second<b.second;
    });
    int ans=0;
    int t=0;
    for(const auto &[l,r]:a)
    {
        if(l>=t)
        {
            ans++;
            t=r;
        }
    }
    cout<<ans<<'\n';
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
