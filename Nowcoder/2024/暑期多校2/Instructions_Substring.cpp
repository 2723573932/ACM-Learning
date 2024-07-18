#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, x, y;
    cin >> n >> x >> y;
    vector<pair<long long, long long>> prefix(n + 1);
    map<pair<long long, long long>, long long> mp;
    for (long long i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        prefix[i] = prefix[i - 1];
        if (x == 'A')
            prefix[i].first--;
        else if (x == 'D')
            prefix[i].first++;
        else if (x == 'W')
            prefix[i].second++;
        else
            prefix[i].second--;
    }
    long long ans = 0;
    for (long long i = n; i >= 0; i--)
    {
        auto [x1,y1] = prefix[i];
        mp[prefix[i]] = i;
        x1 += x;
        y1 += y;
        ans += n - (mp[{x1, y1}] == 0 ? n : mp[{x1, y1}] - 1);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
