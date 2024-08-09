#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cal(ll x)
{
    while (x % 10 == 0)
        x /= 10;
    int cnt = 0, last = x % 10;
    while (x)
    {
        cnt++;
        x /= 10;
    }
    if(last==5)return 2*x-1;
    return 2*x;
}
void solve()
{
}
int main()
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
