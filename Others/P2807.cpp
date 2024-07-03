#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int ans[507];
    ans[1] = 1;
    for(int i=2;i<=500;i++)
    {
        if(i%2==0)
            ans[i] = ans[i-1]+2;
        else
            ans[i] = ans[i-1]+1;
    }
    for(int i=2;i<=500;i++)
    {
        ans[i] += ans[i-1];
    }
    for(int i=2;i<=500;i++)
    {
        ans[i] += ans[i-1];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        cout<<ans[x]<<'\n';
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
