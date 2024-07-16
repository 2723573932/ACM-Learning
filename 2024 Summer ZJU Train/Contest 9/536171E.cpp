#include <bits/stdc++.h>
using namespace std;
vector<long long> prime;
long long f[2 * (int)1e7 + 7];
long long pre[2 * (int)1e7 + 7];
void ini()
{
    f[1] = 1;
    for (int i = 2; i <= 2 * (int)1e7 + 3; i++)
    {
        if (!f[i])
        {
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= 2 * (int)1e7 + 3; j++)
        {
            f[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
        pre[i] = pre[i - 1] + !f[i];
    }
}
void solve()
{
    long long l, r;
    cin >> l >> r;
    long long ans = 0;
    l++;
    r++;
    ans=pre[r]-pre[l-1];
    if(l<=2&&r>=2)ans--;
    if(l<=4&&r>=4)ans++;
    cout << ans << '\n';
}
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    ini();
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
