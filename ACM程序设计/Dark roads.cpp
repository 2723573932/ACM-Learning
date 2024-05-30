/*最小生成树DSU+Kruskal*/
#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> e;

    DSU(int N) : e(N, -1) {}

    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool connected(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y)
    {
        x = get(x), y = get(y);
        if (x == y)
        {
            return false;
        }
        if (e[x] > e[y])
        {
            swap(x, y);
        }
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};
template <class T>
T kurskal(int N, vector<pair<T, pair<int, int>>> edges)
{
    sort(edges.begin(), edges.end());
    T ans = 0;
    DSU D(N + 1);
    for (pair<T, pair<int, int>> &e : edges)
    {
        if (D.unite(e.second.first, e.second.second))
        {
            ans += e.first;
        }
    }
    return (D.size(1) == N ? ans : -1);
}

void solve(int n,int m)
{
    unsigned long long sum=0;
    vector<pair<unsigned long long, pair<int, int>>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        unsigned long long c;
        cin >> a >> b;
        cin>>c;
        sum+=c;
        edges.push_back({c, {a, b}});
    }
    unsigned long long ans = kurskal(n, edges);
    cout<<sum-ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            break;
        solve(n,m);
    }
    return 0;
}
