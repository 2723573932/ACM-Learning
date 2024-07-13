#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> prime;
vector<ll> is_prime(1e6, 1);
void ini()
{
    is_prime[0] = is_prime[1] = 0;
    for (ll i = 2; i < 1e6; i++)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
            for (ll j = i * i; j < 1e6; j += i)
                is_prime[j] = 0;
        }
    }
}
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
void solve()
{

    ll n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << "Alice\n";
        return;
    }
    for (const auto &i : prime)
    {

        if (i * i > n || qpow(i, k) > n)
            break;
        if (n % qpow(i, k) == 0)
        {
            cout << "Alice\n";
            return;
        }
    }
    cout << "Bob\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ini();
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
