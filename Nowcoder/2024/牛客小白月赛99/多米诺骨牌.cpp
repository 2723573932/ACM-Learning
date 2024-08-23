#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> h(n + 1), x(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype([](pair<int, int> a, pair<int, int> b)
                                                                    { return a.second - a.first > b.second - b.first; })>
        pq;
    int pos=1;
    while(pos<=n)
    {
        int l=pos;
    }
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
