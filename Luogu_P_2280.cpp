#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;
int mp[N][N];
void solve()
{
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        int x, y, v;
        cin >> x >> y >> v;
        mp[x][y] = v;
    }
    int ans=0;
    for(int i=0;i<N-m;i++)
    {
        for(int j=0;j<N-m;j++)
        {
            int sum=0;
            for(int x=i;x<i+m;x++)
            {
                for(int y=j;y<j+m;y++)
                {
                    sum+=mp[x][y];
                }
            }
            if(sum>ans)
            {
                ans=sum;
            }
        }
        
    }
    cout<<ans;
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
