#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5 * (int)1e5;
bool isprime(int x)
{
    if (x <= 2)
        return 1;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
void solve()
{
    int k, t;
    cin >> k >> t;
    for (int i = N / t; i > 0; i--)
    {
        if (isprime(i))
        {
            for (int j = 1; j < i; j++)
            {
                for (int x = 0; x < t; x++)
                    cout << j + i * x << ' ';
                k--;
                if (k == 0)
                    return;
                cout << '\n';
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}