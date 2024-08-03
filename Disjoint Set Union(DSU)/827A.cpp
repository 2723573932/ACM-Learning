#include <bits/stdc++.h>
using namespace std;
string ans((int)2e6 + 3, 'a');
int fa[(int)2e6 + 3];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void solve()
{
    iota(begin(fa), end(fa), 0);
    int mx = 0;
    int n;
    cin >> n;
    while (n--)
    {
        int t;
        string s;
        cin >> s >> t;
        int len = s.size();
        while (t--)
        {
            int x;
            cin >> x;
            x--;
            mx = max(mx, x + len);
            for (int pos = x; pos < x + len;)
            {
                int p = find(pos);
                if (p >= x + len)
                {
                    break;
                }
                ans[p] = s[p - x];
                fa[p] = p + 1;
                pos = p + 1;
            }
        }
    }
    cout << ans.substr(0, mx);
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
