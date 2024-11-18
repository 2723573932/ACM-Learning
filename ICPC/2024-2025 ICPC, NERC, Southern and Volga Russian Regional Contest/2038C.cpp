#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll> lst(n);
    for (auto &i : lst)
        cin >> i;
    sort(lst.begin(), lst.end());
    ll a, b, c, d;
    a = b = c = d = 0;
    int p = 0;
    while (lst[p] != lst[p + 1] && p < n-1)
        p++;
    if (p == n)
    {
        cout << "NO\n";
        return;
    }
    a = lst[p];
    p += 2;
    while (lst[p] != lst[p + 1] && p < n-1)
        p++;
    if (p == n)
    {
        cout << "NO\n";
        return;
    }
    b = lst[p];
    p += 2;
    int q = n - 1;
    while (lst[q] != lst[q - 1] && q > p)
        q--;
    if (q <= p)
    {
        cout << "NO\n";
        return;
    }
    c=lst[q];
    q -= 2;
    while (lst[q] != lst[q - 1] && q > p)
        q--;
    if (q <= p)
    {
        cout << "NO\n";
        return;
    }
    d=lst[q];
    cout << "YES\n";
    cout<<a<<' '<<b<<' '<<a<<' '<<c<<' '<<d<<' '<<b<<' '<<d<<' '<<c<<'\n';
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
/*
a,c  d,c

a,b  d,b
*/