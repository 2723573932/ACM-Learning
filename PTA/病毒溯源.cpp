#include <bits/stdc++.h>
using namespace std;
struct EDGE
{
    int to;
    int next;
} edge[2000000];
int head[1000000];
int cnt;
int n;
int vis[1000000];
void adge(int from, int to)
{
    edge[cnt].to = to;
    edge[cnt].next = head[from];
    head[from] = cnt++;
}
string ans;
string s;
int maxdepth = 0;
void dfs(int node, int depth)
{
    s = s + " " + to_string(node);
    vis[node]=1;
    int t = depth;
    if (maxdepth < depth)
    {
        ans = to_string(t) + "\n" + s.substr(2 + to_string(n).size());
        maxdepth = depth;
    }
    for (int i = head[node]; ~i; i = edge[i].next)
    {
        int to = edge[i].to;
        if(!vis[to])
        dfs(to, depth + 1);
    }
    s=s.substr(0,s.size()-1-to_string(node).size());
}
int main()
{
    cin >> n;
    memset(head, -1, sizeof(head));
    for (int i = n - 1; i >= 0; i--)
        adge(n, i);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        vector<int> tmp(t);
        for (int j = 0; j < t; j++)
            cin >> tmp[j];
        sort(tmp.begin(), tmp.end(), greater<int>());
        for (auto x : tmp)
            adge(i, x);
    }
    dfs(n, 0);
    cout << ans;
}