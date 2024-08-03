#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long ans = 0;
    for (long long i = max(a + b, c + 1); i <= b + c; i++)
    {
        ans+=(min(d+1,i)-c)*(min(i-b,b)-max(i-c,a)+1);
    }
    cout << ans;
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
