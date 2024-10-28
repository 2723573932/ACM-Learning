#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int mp[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>mp[i][j];
        }
    }
    long long ans=0;
    for(int x=n;x>=1;x--)
    {
        int j=x;
        int minn=0;
        for(int i=1;i<=n;i++)
        {
            minn=min(minn,mp[i][j]);
            j++;
            if(j>n)break;
        }
        ans+=minn;
    }
    for(int y=2;y<=n;y++)
    {
        int i=y;
        int minn=0;
        for(int j=1;j<=n;j++)
        {
            minn=min(minn,mp[i][j]);
            i++;
            if(i>n)break;
        }
        ans+=minn;
    }
    cout<<-ans<<'\n';
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
