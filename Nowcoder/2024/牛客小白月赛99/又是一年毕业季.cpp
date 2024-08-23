#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> prime;
bool isprime[(int)1e7];
void ini()
{
    memset(isprime, 1, sizeof(isprime));
    isprime[0] = isprime[1] = 0;
    for (ll i = 2; i < 1e7; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
        }
        for (ll j = 0; j < prime.size() && i * prime[j] < 1e7; j++)
        {
            isprime[i * prime[j]] = 0;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    unordered_set<int> st;
    while (n--)
    {
        ll x;
        cin >> x;
        st.insert(x);
    }
    for (const auto &i : prime)
    {
        if (!st.contains(i))
        {
            cout << i << '\n';
            return;
        }
    }
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    ini();
    ll tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}
