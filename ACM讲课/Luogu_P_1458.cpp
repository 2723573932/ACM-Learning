#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    ans.push_back({0, 1});
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            if (gcd(i,j)==1)
                ans.push_back({i, j});
        }
    sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b) {
        return 1.0*a.first/a.second<1.0*b.first/b.second;
    });
    for (const auto &[a, b] : ans)
    {
        cout << a << '/' << b << '\n';
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
