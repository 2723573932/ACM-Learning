#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    if (n == 4)
    {
        if (a[3] - a[0] == accumulate(a.begin(), a.end(), 0.0) / 4 && a[3] - a[0] == (a[1] + a[2]) / 2)
        {
            cout << "YES\n";
            return;
        }
    }
    else if (n == 3)
    {

        for (int i = 1; i <= 2000; i++)
        {
            auto b = a;
            b.insert(lower_bound(b.begin(), b.end(), i), i);
            if (b[3] - b[0] == accumulate(b.begin(), b.end(), 0.0) / 4 && b[3] - b[0] == (b[1] + b[2]) / 2)
            {
                cout << "YES\n"
                     << i << "\n";
                return;
            }
        }
    }
    else if (n == 2)
    {
        for (int i = 1; i <= 2000; i++)
            for (int j = 1; j <= 2000; j++)
            {
                auto b = a;
                b.insert(lower_bound(b.begin(), b.end(), i), i);
                b.insert(lower_bound(b.begin(), b.end(), j), j);
                if (b[3] - b[0] == accumulate(b.begin(), b.end(), 0.0) / 4 && b[3] - b[0] == (b[1] + b[2]) / 2)
                {
                    cout << "YES\n"
                         << i << "\n"
                         << j << "\n";
                    return;
                }
            }
    }
    else if (n == 1)
    {
        cout << "YES\n";
        cout << a[0] << "\n"
             << a[0]*3 << "\n"
             << a[0]*3 << "\n";
        return;
    }
    else if (n == 0)
    {
        cout << "YES\n1\n1\n3\n3";
        return;
    }
    cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
