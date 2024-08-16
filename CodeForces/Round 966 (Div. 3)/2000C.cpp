#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    while (m--)
    {
        unordered_map<char, set<int>> ss;
        unordered_map<int, set<char>> mp;
        string s;
        int f=1;
        cin >> s;
        if (s.size() != n)
        {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < s.size(); i++)
        {
            ss[s[i]].insert(a[i]);
            mp[a[i]].insert(s[i]);
            if (ss[s[i]].size() > 1 || mp[a[i]].size() > 1)
            {
                f = 0;
                break;
            }
        }
        if(f)
        cout << "YES\n";
        else cout << "NO\n";
    }
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
