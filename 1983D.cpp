#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n], b[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        mp[b[i]] = abs(mp[b[i]] - i);
    }
    if (mp.size() != n)
        cout << "NO\n";
    else
    {
        int sum = 0;
        for (auto i : mp)
        {
            sum += i.second;
        }
        if (sum % 2 == 0&&sum/2%2==0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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
