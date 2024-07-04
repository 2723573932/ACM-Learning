#include <bits/stdc++.h>
using namespace std;

bool check(long long x)
{
    if (x % 7 == 0)
    {
        return true;
    }
    while (x)
    {
        if (x % 10 == 7)
        {
            return true;
        }
        x /= 10;
    }
    return false;
}
void solve()
{
    long long n;
    cin >> n;
    int f = 1;
    long long ans = 0;
    if(n<(int)1e8)
    for (long long i = 1; i <= n; i++)
    {
        ans += f;
        if (check(i))
        {
            f = -f;
        }

        if (ans == 0)
        {
            ans = 1337;
        }
        if (ans > 1337)
        {
            ans = 1;
        }
    }
    else{
        ans=547;
        for (long long i = 100000000; i <= n; i++)
    {
        ans += f;
        if (check(i))
        {
            f = -f;
        }

        if (ans == 0)
        {
            ans = 1337;
        }
        if (ans > 1337)
        {
            ans = 1;
        }
    }
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
