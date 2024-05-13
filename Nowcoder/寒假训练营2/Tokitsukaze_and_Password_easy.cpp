#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    string s, y;
    cin >> n >> s >> y;
    vector<char> v;
    for (int i = 0; i < n; i++)
    {
        if (s[i] <= 'd' && s[i] >= 'a')
            if (find(v.begin(), v.end(), s[i]) == v.end())
                v.push_back(s[i]);
    }
    for (int i = 9; i >=0; i--)
    for(int j=9;j)
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
