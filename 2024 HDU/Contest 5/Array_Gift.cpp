#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    for (int i = n - 1; i >= 0; i--)
    {
        int f = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[i] % a[j] == 0)
            {
                f = 0;
                break;
            }
        }
        if (f)
            b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    int g = b[0], g1 = b[1];
    int m=b.size();
    for (int i = 1; i < m; i++)
    {
        g = gcd(g, b[i]);
        g1 = gcd(g1, b[i]);
    }
    if (g == b[0])
    {
        cout << n - 1 << '\n';
        return;
    }
    else
    {
        if (g1 > b[0])
        {
            cout << n << '\n';
            return;
        }
        for (int i = 0; i < m; i++)
        {
            g1 = b[0];
            for (int j = 0; j < m; j++)
            {
                if (i != j)
                    g1 = gcd(g1, b[j]);
                if (b[j] % b[i] == g || b[j] % b[i] == 1)
                {
                    cout << n << '\n';
                    return;
                }
            }
            if (g1 == b[0])
            {
                cout << n << '\n';
                return;
            }
        }
    }
    cout << n + 1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // freopen("C:\\Users\\acm\\Desktop\\1002.in", "r", stdin);
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
