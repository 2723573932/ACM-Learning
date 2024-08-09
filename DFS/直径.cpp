//图的直径
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> e1(1007), e2(1007);
vector<int> dis1, dis2;
void bfs(int node, vector<vector<int>> &e, vector<int> &dis)
{
    queue<int> que;
    que.push(node);
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (const auto &v : e[u])
        {
            if (dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
    }
}
void solve()
{
    int n1, m1, n2, m2;
    cin >> n1 >> m1;
    while (m1--)
    {
        int x, y;
        cin >> x >> y;
        e1[x].push_back(y);
        e1[y].push_back(x);
    }
    cin >> n2 >> m2;
    while (m2--)
    {
        int x, y;
        cin >> x >> y;
        e2[x].push_back(y);
        e2[y].push_back(x);
    }

    int min1, min2;
    int max1, max2;
    min1 = min2 = 0x3f3f3f3f;
    max1 = max2 = 0;
    for (int i = 0; i < n1; i++)
    {
        dis1.assign(n1, 0x3f3f3f3f);
        dis1[i] = 0;
        bfs(i, e1, dis1);
        int tmp = 0;
        for (int j = 0; j < n1; j++)
        {
            tmp = max(tmp, dis1[j]);
        }
        max1 = max(max1, tmp);
        min1 = min(min1, tmp);
    }
    for (int i = 0; i < n2; i++)
    {
        dis2.assign(n2, 0x3f3f3f3f);
        dis2[i] = 0;
        bfs(i, e2, dis2);
        int tmp = 0;
        for (int j = 0; j < n2; j++)
        {
            tmp = max(tmp, dis2[j]);
        }
        max2 = max(max2, tmp);
        min2 = min(min2, tmp);
    }
    cout << max(min1 + min2 + 1, max(max1, max2)) << ' ' << max1 + max2 + 1 << '\n';
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
