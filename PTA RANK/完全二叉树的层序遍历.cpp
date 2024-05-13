// https://pintia.cn/problem-sets/1769969385182269440/exam/problems/1769969798270881801?type=7&page=0
#include <bits/stdc++.h>
using namespace std;

int ans[(int)1e5], n;
void dfs(int x)
{
    if (x > n)
        return;
    dfs(x * 2);
    dfs(x * 2 + 1);
    int node;
    cin >> node;
    ans[x] = node;
}
void solve()
{
    cin >> n;
    dfs(1);
    cout<<ans[1];
    for(int i=1;i<=n;i++)
    if(i!=1)
    cout<<' '<<ans[i];
     
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}
