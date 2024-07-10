#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);
int n, L;
double a[1003];
double dp[1003][1003];

double f(int l, int r)
{
    if ( l> r)
        return 0;
    if ((r - l) % 2 == 0)
        return INFINITY;
    if (dp[l][r] != -1)
        return dp[l][r];

    double res = INFINITY;
    for (int i = l + 1; i <= r; i++)
    {
        res = min(res, f(l + 1, i - 1) + f(i + 1, r) + sin((a[i] - a[l]) * pi));
    }
    return dp[l][r] = res;
}

void solve()
{
    cin >> n >> L;
    L *= 2;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i];
        a[i] /= L;
    }
    sort(a + 1, a + 2 * n + 1);

    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= 2 * n; j++)
            dp[i][j] = -1;

    cout << fixed << setprecision(12) << f(1, 2 * n) / 2 << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}