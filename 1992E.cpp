#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
void solve()
{
    int n;
    cin >> n;
    int lenn = 0;
    int tmp = n;
    while (tmp)
    {
        lenn++;
        tmp /= 10;
    }
    int ans = 0;
    queue<pair<int, int>> que;
    for (int a = 1; a <= 10000; a++)
    {
        for (int b = 1; b <= min((int)10000, a * n); b++)
        {
            int key = a * n - b;
            int tmp = key;
            int lenkey = 0;
            while (tmp)
            {
                lenkey++;
                tmp /= 10;
            }
            tmp = n;
            if (a * lenn - b == lenkey)
            {
                int len = lenn;
                while (len < lenkey)
                {
                    tmp *= pow(10, lenn);
                    tmp += n;
                    len += lenn;
                }
                for (int i = 1; i <= len - lenkey; i++)
                {
                    tmp /= 10;
                }
                if (tmp == key)
                {
                    ans++;
                    que.push({a, b});
                }
            }
        }
    }
    cout << ans << '\n';
    while (!que.empty())
    {
        auto [a, b] = que.front();
        que.pop();
        cout << a << ' ' << b << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
