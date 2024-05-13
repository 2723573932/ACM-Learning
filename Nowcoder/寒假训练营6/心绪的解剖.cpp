#include <bits/stdc++.h>
using namespace std;
vector<long long> fib = {0, 1};
void ini()
{
    long long x = 0;
    while (x < 1000000000)
    {
        x = fib[fib.size() - 1] + fib[fib.size() - 2];
        fib.push_back(x);
    }
}
void solve()
{
    vector<long long> ans(3);
    long long q;
    cin >> q;
    for (int i = 0; i < 3; i++)
    {
        int it = lower_bound(fib.begin(), fib.end(), q,greater<long long>())-fib.begin();
        ans[i] = fib[it];
        q -= fib[it];
    }
    if (q == 0)
        for (auto i : ans)
        {
            cout << i << " ";
        }
    else
        cout << -1;
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    ini();
    reverse(fib.begin(), fib.end());
    while (tt--)
        solve();
    return 0;
}
