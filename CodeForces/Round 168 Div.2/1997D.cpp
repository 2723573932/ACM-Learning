#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, ans = 0;
    cin >> n;
    vector<vector<long long>> mp(n + 1);
    vector<long long> lst(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> lst[i];
    }
    ans = lst[1];
    lst[1] = 0;
    for (long long i = 2; i <= n; i++)
    {
        long long x;
        cin >> x;
        mp[x].push_back(i);
    }
    auto dfs = [&](auto &&self, long long node) -> void
    {
        long long minn = 0x3f3f3f3f;
        for (const auto &i : mp[node])
        {
            self(self, i);
            minn = min(minn, lst[i]);
        }
        if(minn==0x3f3f3f3f) minn=lst[node];
        if (lst[node] < minn&&node!=1)
        {
            lst[node] = (minn + lst[node]) / 2;
        }
        else
        {
            lst[node] = minn;
        }
        return;
    };
    dfs(dfs, 1);
    cout << (ans + lst[1]) << '\n';
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
