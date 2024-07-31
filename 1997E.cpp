#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> lst(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> lst[i];
    }
    while (q--)
    {
        int t, x, cnt;
        cin >> t >> x;
        cnt = x;
        for (int i = 1; i < t; i++)
        {
            if (cnt / x > lst[i])
                continue;
            else
                cnt++;
        }
        if (cnt / x <= lst[t])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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
