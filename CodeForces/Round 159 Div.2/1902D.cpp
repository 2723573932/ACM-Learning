#include <bits/stdc++.h>
using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    unordered_map<pair<int, int>, vector<int>, pair_hash> mp;
    vector<pair<int, int>> lst(n + 1);
    for (int i = 0, x = 0, y = 0; i <= n; i++)
    {
        if (s[i] == 'U')
            y++;
        if (s[i] == 'D')
            y--;
        if (s[i] == 'L')
            x--;
        if (s[i] == 'R')
            x++;
        mp[{x, y}].push_back(i);
        lst[i] = {x, y};
    }
    auto check = [&](int x, int y, int l, int r) -> bool
    {
        if (mp.contains({x, y}))
        {
            auto it = lower_bound(mp[{x, y}].begin(), mp[{x, y}].end(), l);
            if (it != mp[{x, y}].end() && *it <= r)
                return true;
        }
        return false;
    };
    while (q--)
    {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        if (check(x, y, 0, l - 1) || check(x, y, r, n) || check(lst[r].first + lst[l - 1].first - x, lst[r].second + lst[l - 1].second - y, l, r - 1))
        {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
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
