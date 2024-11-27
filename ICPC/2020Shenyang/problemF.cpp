#include <bits/stdc++.h>
using namespace std;
string f(string s)
{
    vector<char> mp(26);
    set<char> st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (!st.contains(s[i]))
        {
            mp[s[i] - 'a'] = 'a' + st.size();
            st.insert(s[i]);
        }
        s[i] = mp[s[i] - 'a'];
    }
    return s;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, f(s.substr(0, i)));
    }
    cout << ans;
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
