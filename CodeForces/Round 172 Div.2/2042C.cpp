#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> suf(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1)
            suf[i] = suf[i + 1];
        if (s[i] == '1')
            suf[i]++;
        else
            suf[i]--;
    }
    suf.erase(suf.begin());
    sort(suf.begin(), suf.end(), greater());
    ll sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += suf[i];
        if (sum >= k)
        {
            cout << i + 2 << '\n';
            return;
        }
    }
    cout << "-1\n";
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
