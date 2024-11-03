#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans=INT_MAX;
    sort(a.begin(),a.end());
    for (int i=0;i<n-1;i++)
    {
        int tmp=distance(a.begin(),lower_bound(a.begin(),a.end(),a[i]+a[i+1]));
        ans=min(ans,n-tmp+i);
    }
    cout<<ans<<'\n';
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
