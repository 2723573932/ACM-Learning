#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n,k,q;
    cin>>n>>k>>q;
    long long a[k+1],b[k+1];
    a[0]=b[0]=0;
    for(long long i=1;i<=k;i++) cin>>a[i];
    for(long long i=1;i<=k;i++) cin>>b[i];
    while(q--)
    {
        long long tmp;
        cin>>tmp;
        if(tmp==n){
            cout<<b[k]<<' ';
            continue;
        }
        long long pos=upper_bound(a,a+k+1,tmp,less<long long>())-a-1;
        long long ans=b[pos];
        ans+=(tmp-a[pos])*((b[pos+1]-b[pos]))/((a[pos+1]-a[pos]));
        cout<<ans<<' ';
    }
    cout<<'\n';

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
