#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    set<int> st0, st1;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        if (y == 0)
            st0.emplace(x);
        else
            st1.emplace(x);
    }
    long long ans = 0;
    for (auto it = st1.begin(); it != st1.end(); it++)
    {
        if (st0.count(*it))
            ans += st1.size() - 1;
        if (st0.contains(*it - 1) && st0.contains(*it + 1))
            ans++;
    }
    for (auto it = st0.begin(); it != st0.end(); it++)
    {
        if (st1.contains(*it - 1) && st1.contains(*it + 1))
            ans++;
        if (st1.contains(*it))
            ans += st0.size()-1;
    }
    cout<<ans<<'\n';
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
