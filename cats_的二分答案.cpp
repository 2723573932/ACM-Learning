#include <bits/stdc++.h>
using namespace std;
using ll = long long;
unordered_map<ll, ll> mp[64];
ll check(ll l, ll r, ll k)
{

    ll mid = (l + r) / 2;
    if (l > r)
        return 0;
    if (l == r)
        return 1;
    if (mp[k].count(r - l + 1))
        return mp[k][r - l + 1];
    if (log2(r - l + 1) <= k)
        return r - l + 1;
    if (k == 0)
        return mp[k][r - l + 1] = check(mid + 1, r, k) + 1;
    return mp[k][r - l + 1] = check(l, mid - 1, k - 1) + check(mid + 1, r, k) + 1;
}
void solve()
{
    fill(mp, mp + 64, unordered_map<ll, ll>());
    ll l, r, k;
    cin >> l >> r >> k;
    if(k>60)cout<<r-l+1<<'\n';
    else
    cout << check(l, r, k) << '\n';
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
