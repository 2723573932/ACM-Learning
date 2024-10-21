#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1), b(m + 1);
    unordered_map<int, int> mp;
    vector<set<int>> st(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]] = i;
        st[i].insert(0x3f3f3f3f);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        st[b[i]].insert(i);
    }
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (*st[a[i]].begin() > *st[a[i + 1]].begin())
        {
            cnt++;
        }
    }
    if (cnt == 0)
        cout << "YA\n";
    else
        cout << "TIDAK\n";
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (mp[b[x]] + 1 <= n)
            if (*st[a[mp[b[x]]]].begin() > *st[a[mp[b[x]] + 1]].begin())
                cnt--;
        if (mp[b[x]] - 1 >= 1)
            if (*st[a[mp[b[x]] - 1]].begin() > *st[a[mp[b[x]]]].begin())
                cnt--;
        st[b[x]].erase(x);
        if (mp[b[x]] + 1 <= n)
            if (*st[a[mp[b[x]]]].begin() > *st[a[mp[b[x]] + 1]].begin())
                cnt++;
        if (mp[b[x]] - 1 >= 1)
            if (*st[a[mp[b[x]] - 1]].begin() > *st[a[mp[b[x]]]].begin())
                cnt++;
        if (mp[y] + 1 <= n)
            if (*st[a[mp[y]]].begin() > *st[a[mp[y] + 1]].begin())
                cnt--;
        if (mp[y] - 1 >= 1)
            if (*st[a[mp[y] - 1]].begin() > *st[a[mp[y]]].begin())
                cnt--;
        st[y].insert(x);
        if (mp[y] + 1 <= n)
            if (*st[a[mp[y]]].begin() > *st[a[mp[y] + 1]].begin())
                cnt++;
        if (mp[y] - 1 >= 1)
            if (*st[a[mp[y] - 1]].begin() > *st[a[mp[y]]].begin())
                cnt++;
        b[x] = y;
        if (cnt == 0)
            cout << "YA\n";
        else
            cout << "TIDAK\n";
    }
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
