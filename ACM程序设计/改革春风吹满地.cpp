// https://jiudge.zuccacm.top/#/contest/188/problem/A
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    while (cin >> n && n != 0)
    {
        pair<int, int> a[n];
        double ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].first>>a[i].second;
        }

        for(int i=0;i<n;i++)
        {
            ans+=a[i].first*a[(i+1)%n].second-a[i].second*a[(i+1)%n].first;
        }
        cout<<fixed<<setprecision(1)<<ans/2<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}
