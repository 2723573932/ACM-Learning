#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> lst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lst[i].first >> lst[i].second;
    }
    sort(lst.begin(), lst.end());
    cout << "YES\n";
    for (int i = 0; i < n - 1; i++)
    {
        cout << lst[i].first << ' ' << lst[i].second << '\n';
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
