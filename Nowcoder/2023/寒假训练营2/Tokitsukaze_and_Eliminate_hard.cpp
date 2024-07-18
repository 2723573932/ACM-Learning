#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp, rec;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    reverse(a.begin(), a.end());
    int tmp = 0, tp = 0;
    for (auto i : a)
    {
        mp[i]--;
        if (mp[i] == 0)
            tmp++;
        if (rec[i] != 1)
        {
            rec[i]++;
        }
        if (rec.size() >= mp.size() - tp)
        {
            ans++;
            rec.clear();
            tp = tmp;
        }
    }
    cout << ans << '\n';
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
