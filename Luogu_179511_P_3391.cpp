#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        reverse(a.begin() + l, a.begin() + r + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
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