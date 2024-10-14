#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    vector<int> lst;
    while (s[0] == s.back() && cnt <= n)
    {
        s = s.substr(1) + s[0];
        cnt++;
    }
    int ans = 0;
    int f = 0;
    int tmp = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            tmp++;
        }
        else
        {
            lst.push_back((tmp + 1) / 2);
            if (tmp & 1)
                f = 1;
            tmp = 0;
        }
    }
    lst.push_back((tmp + 1) / 2);
    if (tmp & 1)
        f = 1;
    if (lst.size() == 1)
        f = 0;
    for(int i=0;i<lst.size();i++)
    {
        ans+=lst[i];
    }
    cout << ans - f << '\n';
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
