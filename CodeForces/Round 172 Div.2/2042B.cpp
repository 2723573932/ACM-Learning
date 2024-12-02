#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    vector<pair<int,int>> v(mp.begin(),mp.end());
    sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    });
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].second==1)
        {
            if(!(i&1))ans+=2;
        }
        else{
            ans++;
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
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}