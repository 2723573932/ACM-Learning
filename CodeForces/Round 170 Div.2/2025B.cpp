#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1e9 + 7;

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int t;
    cin >> t;
    vector<int> n(t), k(t);
    for (int i = 0; i < t; i++)
        cin >> n[i];
    for (int i = 0; i < t; i++)
    {
        cin >> k[i];
    }
    for(int i=0;i<t;i++)
    {
        if(n[i]==k[i])cout<<"1\n";
        else cout<<qpow(2,k[i])<<'\n';
    }
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}
