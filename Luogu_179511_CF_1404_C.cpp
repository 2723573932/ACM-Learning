#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (q--)
    {
        auto tmp = a;
        int l, r;
        cin >> l >> r;
        int f = 1;
        int ans = 0;
        while (f)
        {
            f = 0;
            for (int i = tmp.size() - r - 1; i > l; i--)
            {
                if (tmp[i] == i)
                {
                    f = 1;
                    ans++;
                    tmp.erase(tmp.begin() + i);
                    break;
                }
            }
        }
        cout << ans << '\n';
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
