#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin >> n;
    struct node
    {
        ll w,v,c;
    };
    vector<node> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i].w >> a[i].v >> a[i].c;
    }
    sort(a.begin(),a.end(),[](node a,node b){return a.w*b.c>a.c*b.w;});
    ll ans=0;
    ll W=0;
    for(const auto &[w,v,c]:a)
    {
        ans+=v-W*c;
        W+=w;
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
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
system("pause");
#endif
    return 0;
}
