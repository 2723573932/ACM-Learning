#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> lst[(int)2e5+7];
int check(int k)
{
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        l = max(l - k, lst[i].first);
        r = min(r + k, lst[i].second);
        if (l > r) return 0;
    }
    return 1;
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> lst[i].first >> lst[i].second;
    }
    int l = -1, r = 1e9;
    while (r > l)
    {
        int mid = (l + r) >> 1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<r<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
