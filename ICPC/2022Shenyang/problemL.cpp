#include <bits/stdc++.h>
using namespace std;
vector<array<int, 3>> a(7), b(7);
int n, m;
double ans[3];
void dfs(int f, int p, int q, double t)
{
    // cout<<f<<" "<<p<<" "<<q<<" "<<t<<endl;
    if (p == q && q == 0)
    {
        ans[2] += t;
        return;
    }
    if (p == 0)
    {
        ans[1] += t;
        return;
    }
    if (q == 0)
    {
        ans[0] += t;
        return;
    }
    if (f)
    {
        int pos = n - 1;
        for (; pos >= 0; pos--)
        {
            if (a[pos][0] > 0)
                break;
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i][0] > 0 && a[i][2] == a[pos][2])
            {
                pos = i;
                break;
            }
        }
        a[pos][2]++;
        for (auto &x : b)
        {
            if (x[0] <= 0)
                continue;
            auto tmpa = a[pos][0];
            auto tmpb = x[0];
            int tmpp = p, tmpq = q;
            a[pos][0] -= x[1];
            x[0] -= a[pos][1];
            if (a[pos][0] <= 0)
                p--;
            if (x[0] <= 0)
                q--;
            dfs(!f, p, q, t / tmpq);
            p = tmpp;
            q = tmpq;
            a[pos][0] = tmpa;
            x[0] = tmpb;
        }
        a[pos][2]--;
    }
    else
    {
        int pos = m - 1;
        for (; pos >= 0; pos--)
        {
            if (b[pos][0] > 0)
                break;
        }
        for (int i = 0; i < m; i++)
        {
            if (b[i][0] > 0 && b[i][2] == b[pos][2])
            {
                pos = i;
                break;
            }
        }
        b[pos][2]++;
        for (auto &x : a)
        {
            if (x[0] <= 0)
                continue;
            auto tmpb = b[pos][0];
            auto tmpa = x[0];
            int tmpp = p, tmpq = q;
            b[pos][0] -= x[1];
            x[0] -= b[pos][1];
            if (b[pos][0] <= 0)
                q--;
            if (x[0] <= 0)
                p--;
            dfs(!f, p, q, t / tmpp);
            p = tmpp;
            q = tmpq;
            b[pos][0] = tmpb;
            x[0] = tmpa;
        }
        b[pos][2]--;
    }
}
void solve()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0];
        a[i][1] = a[i][0];
        a[i][2] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i][0];
        b[i][1] = b[i][0];
        b[i][2] = 0;
    }
    if (n > m)
    {
        dfs(1, n, m, 1);
    }
    else if (n < m)
    {
        dfs(0, n, m, 1);
    }
    else
    {
        dfs(0, n, m, 0.5);
        dfs(1, n, m, 0.5);
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] <<endl;
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    cout << fixed << setprecision(15);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}
