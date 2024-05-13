#include <bits/stdc++.h>
using namespace std;
#define int long long
int mp[5000][5000];
int ans[5000], route[5000], a[5000];

void print(int from)
{
    if (!from)
    {
        return;
    }
    print(route[from]);
    cout << from << ' ';
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans[i] = a[i];
    }
    ans[1] = a[1];
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] && ans[i] + a[j] > ans[j])
            {
                ans[j] = ans[i] + a[j];
                route[j] = i;
            }
        }
    }
    auto it = max_element(ans + 1, ans + n + 1);
    print(it - ans);
    cout << '\n'
         << *it;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    //    cin>>tt;
    while (tt--)
        solve();
    return 0;
}
