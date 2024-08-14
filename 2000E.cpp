#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<ll> a(w);
    for (ll i = 0; i < w; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    ll ans = 0;
    priority_queue<ll, vector<ll>> pq;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
        {
            pq.push(min(min(i,k), min(n - i + 1, n - k+1)) * min(min(j,k), min(m - j + 1, m - k+1)));
        }
    for (const auto &i : a)
    {
        ans += i * pq.top();
        pq.pop();
    }
    cout << ans << '\n';
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
