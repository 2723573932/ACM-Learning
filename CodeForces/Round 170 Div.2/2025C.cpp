#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    map<long long, long long> mp;
    while (n--)
    {
        long long x;
        cin >> x;
        mp[x]++;
    }
    auto p = mp.begin(), q = mp.begin();
    long long ans = 0, tmp = 0;
    while (p != mp.end())
    {
        if (p == q)
            for (long long i = 0; i < k; i++)
            {
                if (q->first - p->first == i)
                {
                    tmp += q->second;
                    q = next(q);
                    ans = max(ans, tmp);
                    if (q == mp.end())
                    {
                        ans = max(ans, tmp);
                        cout << ans << '\n';
                        return;
                    }
                }
                else
                {
                    ans = max(ans, tmp);
                    tmp = 0;
                    p = q;
                    break;
                }
            }
        else
        {

            if (q->first - p->first == k)
            {
                tmp += q->second - p->second;
                q = next(q);
                if (q == mp.end())
                {
                    ans = max(ans, tmp);
                    cout << ans << '\n';
                    return;
                }
                p = next(p);
                ans = max(ans, tmp);
            }
            else{
                ans = max(ans, tmp);
                tmp = 0;
                p = q;
            }
        }
    }
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    long long tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}
