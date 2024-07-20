#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    long long len = s.size();
    long long n = stoll(s);
    long long ans = 0;
    queue<tuple<long long, long long>> q;
    for (long long a = 1; a <= 10000; a++)
    {
        for (long long b = max(len * a - 5, (long long)1); b < len * a; b++)
        {
            long long x = n * a - b;
            long long y = 0;
            for (long long k = 0; k < len * a - b; k++)
            {
                y = y * 10 + (s[k % len] - '0');
            }
            if (x == y)
            {
                ans++;
                q.push({a, b});
            }
        }
    }
    cout << ans << '\n';
    while (!q.empty())
    {
        const auto [a, b] = q.front();
        q.pop();
        cout << a << ' ' << b << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
