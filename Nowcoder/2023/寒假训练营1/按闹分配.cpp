#include <bits/stdc++.h>
using namespace std;
long long d[1000000];
void solve()
{

    int n, q, tc;
    cin >> n >> q >> tc;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    sort(d+1, d + n +1);
    for (int i = 1; i <= n; i++)
    {
        d[i] += d[i - 1];
    }
    long long m;
    while (q--)
    {
        cin >> m;
        cout << d[max((long long)0, n - m / tc)] + tc << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}
