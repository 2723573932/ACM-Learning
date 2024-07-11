#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = n; i > min(m, k); i--)
    {
        cout << i << ' ';
    }
    for (int i = 1; i <= min(m, k); i++)
    {
        cout << i << ' ';
    }
    cout<<'\n';
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
