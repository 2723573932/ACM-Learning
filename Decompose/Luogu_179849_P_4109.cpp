#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cal(ll x)
{
    while (x % 10 == 0)
        x /= 10;
    int cnt = 0;
    if(x%10==5)cnt--;
    while (x)
    {
        cnt+=2;
        x /= 10;
    }
    return cnt;
}
void solve()
{
    ll l, r;
    cin >> l >> r;
    ll ans = 0, nxt = l, minn = 0x3f3f3f3f;
    while (nxt <= r)
    {
        if (cal(nxt) < minn)
            minn = cal(nxt), ans = nxt;
        if (nxt % 10)
        {
            nxt = (nxt / 5 + 1) * 5;
            continue;
        }
        for (ll i = 1e5; i >= 10; i /= 10)
            if (nxt % i==0)
            {
                nxt = (nxt / i + 1) * i;
                break;
            }
    }
    cout<<ans<<'\n';
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
