#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, t;
    cin >> n >> t;
    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y > 0)
        {
            a.push_back({x, y});
        }
        else
        {
            b.push_back({x, y});
        }
    }
    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.first < b.first; });
    sort(b.begin(), b.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.first + a.second > b.first + b.second; });
    for (const auto &[x, y] : a)
    {
        if (t <= x)
        {
            cout << "-1s\n";
            return;
        }
        t += y;
    }
    for (const auto &[x, y] : b)
    {
        if (t <= x)
        {
            cout << "-1s\n";
            return;
        }
        t += y;
        if (t <= 0)
        {
            cout << "-1s\n";
            return;
        }
    }
    cout << "+1s\n";
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
