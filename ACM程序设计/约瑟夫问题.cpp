#include <bits/stdc++.h>
using namespace std;

void solve()
{
    queue<int> que;
    int n, k,cnt=1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        que.push(i);
    while (!que.empty())
    {
        if(cnt==k){
            cout<<que.front()<<' ';
            cnt=1;
        }
        else{
            que.push(que.front());
            cnt++;
        }
        que.pop();
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
