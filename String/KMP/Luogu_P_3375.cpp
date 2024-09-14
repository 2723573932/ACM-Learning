#include <bits/stdc++.h>
using namespace std;
void KMP(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<int> nxt(m);
    for (int i = 1, j = 0; i < m; i++)
    {
        while (j && t[i] != t[j])
        {
            j = nxt[j - 1];
        }
        if (t[i] == t[j])
            j++;
        nxt[i] = j;
    }
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j && s[i] != t[j])
            j = nxt[j - 1];
        if (s[i] == t[j])
            j++;
        if (j == m)
        {
            cout << i - m + 2 << '\n';
            j = nxt[j - 1];
        }
    }
    for (const auto &i : nxt)
        cout << i << ' ';
}

void solve()
{   
    string s,t;
    cin>>s>>t;
    KMP(s,t);
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
