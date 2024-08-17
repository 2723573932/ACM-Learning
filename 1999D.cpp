#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    int p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (p < t.size())
        {
            if (s[i] == t[p] || s[i] == '?')
            {
                s[i] = t[p];
                p++;
            }
        }
        else if (s[i] == '?')
        {
            s[i] = 'a';
        }
    }
    if (p == t.size())
    {
        cout << "YES\n"<<s<<'\n';
        return;
    }
    cout << "NO\n";
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
