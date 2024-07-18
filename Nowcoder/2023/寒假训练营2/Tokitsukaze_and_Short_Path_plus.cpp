#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    long long a[n + 1];
    long long ans=0;
    for (long long i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(long long i=1;i<n;i++)
    ans+=a[i+1]*i;
    cout<<4*ans<<'\n';
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
