#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, s, k;
    cin >> n >> s >> k;
    long long a[n];
    if (n == 1 && k == 0)
    {
        cout << s << '\n';
        return;
    
    }
    if(n==2&&k==0&&s>=2)
    {
        cout<<s-1<<' '<<1<<'\n';return;
    }
    if (k * 2 + 1 > n)
    {
        cout << "-1\n";
        return;
    }
    for (long long i = 0; i < n; i++)
        a[i] = 1;
    s -= n;
    if (s / (k + 1) < 1)
    {
        cout << "-1\n";
        return;
    }
    for (long long i = 0; i <= k; i++)
    {
        a[i * 2] += s / (k + 1);
    }
    s %= k + 1;
    if (s != 0 && 2 * k + 1 > n)
    {
        cout << "-1\n";
        return;
    }
    else
    {
        a[2 * k + 1] += s;
    }
    for (auto i : a)
        cout << i << ' ';
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
