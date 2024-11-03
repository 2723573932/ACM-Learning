#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, m;
    cin >> n >> m;
    if (n * (n + 1) / 2 * m * (m + 1) / 2 % 2 == 1)
    {
        cout << "No\n";
        return;
    }
    if (m%4==0||m%4==3)
    {
        int sum = m * (m + 1) / 4;
        vector<int> a;
        int f = 0;
        sum -= m;
        while (sum > 0)
        {
            for (int i = m - a.size(); i >= 1; i--)
            {
                if (i * (i - 1) / 2 <= sum)
                {
                    sum -= i * (i - 1) / 2;
                    for (int j = 1; j <= i; j++)
                    {
                        a.push_back(f);
                    }
                    f ^= 1;
                    break;
                }
            }
        }
        while (a.size() < m)
        {
            a.push_back(f);
            f ^= 1;
        }
        if (a.size() != m && sum != 0)
        {
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[j] << " ";
            }
            cout << '\n';
        }
    }
    else
    {
        int sum = n * (n + 1) / 4;
        vector<int> a;
        int f = 0;
        sum -= n;
        while (sum > 0)
        {
            for (int i = n - a.size(); i >= 1; i--)
            {
                if (i * (i - 1) / 2 <= sum)
                {
                    sum -= i * (i - 1) / 2;
                    for (int j = 1; j <= i; j++)
                    {
                        a.push_back(f);
                    }
                    f ^= 1;
                    break;
                }
            }
        }
        while (a.size() < n)
        {
            a.push_back(f);
            f ^= 1;
        }
        if (a.size() != n && sum != 0)
        {
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i] << " ";
            }
            cout << '\n';
        }
    }
}
signed main()
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
