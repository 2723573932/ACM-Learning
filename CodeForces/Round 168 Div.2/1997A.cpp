#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++)
        if (s[i] == s[i + 1])
        {
            s.insert(i + 1, 1, (s[i] - 'a' + 1) % 26 + 'a');
            cout<<s<<'\n';
            return;
        }
    s.append(1, (s.back() - 'a' + 1) % 26 + 'a');
    cout<<s<<'\n';
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
