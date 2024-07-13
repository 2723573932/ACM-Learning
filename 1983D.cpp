#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n], b[n];
    map<int, int> mp;
    int a1 = 0, a2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (mp.count(b[i]))
        {
            if (mp[b[i]] > i)
                a1++;
            else if (mp[b[i]] < i)
                a2++;
        }
        mp[b[i]] = abs(mp[b[i]] - i);
    }
    if (mp.size() != n)
        cout << "NO\n";
    else
    {
        
        if (a1 % 2 == 0&&a2%2==0)
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
