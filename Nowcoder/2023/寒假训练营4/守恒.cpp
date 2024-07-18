#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, sum = 0, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        sum += x;
    }
    if (n == 1)
    {
        cout <<"1\n";
        return;
    }
    long long ans = 0;
    for (long long i = 1; n * i <= sum; i++)
    {
        if (sum % i == 0)
            ans++;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}
