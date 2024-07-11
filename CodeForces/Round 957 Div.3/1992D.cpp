#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = 'L' + s + 'L';
    int pos = 0, f = 1;
    for (int i = 0; i <= n + 1; i++)
    {
        if (s[i] == 'L')
        {
            if (i - pos <= m)
                pos = i;
            else
            {
                auto tmp = s.substr(pos + m, i - pos - m);
                if (tmp.find('C') != string::npos)
                {
                    cout << "NO\n";
                    return;
                }
                k -= tmp.size();
                pos = i;
            }
        }
    }
    if (pos == n + 1 && k >= 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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
