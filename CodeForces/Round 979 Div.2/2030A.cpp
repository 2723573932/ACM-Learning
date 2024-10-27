#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int maxn=0;
    int minn=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        maxn=max(maxn,x);
        minn=min(minn,x);
    }
    cout<<(maxn-minn)*(n-1)<<'\n';
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
