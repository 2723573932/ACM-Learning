#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, t = 0, f = 0, ans = 0;
    cin >> n;
    vector<long long> lst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
        if (lst[i] < 0)
            t++;
        if (lst[i] == 0)
            f = 1;
        lst[i] = abs(lst[i]);
    }
    sort(lst.begin(), lst.end());
    if ((t & 1) && f == 0)
        ans -= 2 * lst[0];
    for (auto i : lst)
        ans += i;
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
