#include <bits/stdc++.h>
using namespace std;

int a[100007], b[100007];
void solve()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    if (n == 1)
        cout << "-1\n";
    else if (n == 2)
    {
        if (a[1] == b[1] || b[2] == a[2])
            cout << "-1\n";
        else if (a[1] == b[2] || b[1] == a[2])
            cout << "1\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if ((a[i] == b[i]&&i!=1&&i!=n) || a[i] == b[i - 1] || a[i] == b[i + 1])
            {
                cout << "1\n";
                return;
            }
        }
        cout << "2\n";
    }
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
