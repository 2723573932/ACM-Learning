#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll rxa, rxc, rya, ryc, rza, rzc, x, y, z;
constexpr ll rp = 2333333;
double gen()
{
    x = (y * rxa + rxc) % rp;
    y = (z * rya + ryc) % rp;
    z = (x * rza + rzc) % rp;
    return x % 20 + y % 10 * 1.0 / 10 + z % 10 * 1.0 / 100;
}
struct node
{
    double x = 0;
    double y = 0;
    ll cnt = 0;
};

node mp[21][21];
void solve()
{
    ll n;
    cin >> n;
    cin >> rxa >> rxc >> rya >> ryc >> rza >> rzc;
    for (int i = 1; i <= n; i++)
    {
        double x = gen();
        double y = gen();
        mp[(int)x][(int)y].x += x - (int)x;
        mp[(int)x][(int)y].y += y - (int)y;
        mp[(int)x][(int)y].cnt++;
    }
    double ans = 0;
    ll sum=0;
    for (ll i = 0; i < 20; i++)
    {
        for (ll j = 0; j < 20; j++)
        {
            if (mp[i][j].cnt != 0)
                for (ll x = i + 1; x < 20; x++)
                {
                    for (ll y = j + 1; y < 20; y++)
                    {
                        if (mp[x][y].cnt != 0)
                        {
                            ans += 1.0 * (x - i) * mp[i][j].cnt * mp[x][y].cnt + mp[i][j].cnt * (mp[x][y].x) - mp[x][y].cnt * mp[i][j].x;
                            ans += 1.0 * (y - j) * mp[i][j].cnt * mp[x][y].cnt + mp[i][j].cnt * (mp[x][y].y) - mp[x][y].cnt * mp[i][j].y;
                            sum+=mp[i][j].cnt*mp[x][y].cnt;
                        }
                    }
                }
        }
    }
    cout << fixed << setprecision(5) << ans / sum;
}
int main()
{
#if !local
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if local
    system("pause");
#endif
    return 0;
}