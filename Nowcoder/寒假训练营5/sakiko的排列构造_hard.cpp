#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
bool vis[maxn] = {0};
int prime[maxn];
void ini()
{
    int cnt = 0;
    for (int i = 2; i <= maxn; i++)
    {
        if (!vis[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] <= maxn; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int p[n + 1];
    for (int i = 1; i <= n; i++)
        p[i] = i;
    set<int> st;
    for (int i =1; i <= n; i++)
    {
        for(int j=1;j<=n;j++)
        {
            if()
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ini() int tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}
