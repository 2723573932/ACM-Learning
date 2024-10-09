#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, q, f = 1;
    cin >> n >> m >> q;
    vector<int> a(n + 1), b(m + 1);
    vector<set<int>> st(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        st[i].insert(0x3f3f3f3f);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        st[b[i]].insert(i);
    }
    for (int i = 1; i < n; i++)
    {
        if (*st[a[i]].begin() > *st[a[i + 1]].begin())
        {
            f = 0;
            break;
        }
    }
    if (f)
        cout << "YA\n";
    else
        cout << "TIDAK\n";
    while (q--)
    {
        f = 1;
        int x, y;
        cin >> x >> y;
        st[b[x]].erase(x);
        st[y].insert(x);
        b[x] = y;
        for (int i = 1; i < n; i++)
        {
            if (*st[a[i]].begin() > *st[a[i + 1]].begin())
            {
                f = 0;
                break;
            }
        }
        if (f)
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
