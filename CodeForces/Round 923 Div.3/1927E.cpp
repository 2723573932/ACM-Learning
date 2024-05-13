#include<bits/stdc++.h>
using namespace std;

int a[200007];
void solve()
{
    memset(a, 0,sizeof(a));
    int n,k;
    cin>>n>>k;
    int cnt = 0;
    for(int i=1;i<=n-k+1;i++)
    {
        if(a[i]==0)
        a[i]=i+cnt++;
        a[i+k]=a[i]+1;
        cout<<a[i]<<' ';
    }
    for(int i=n-k+1;i<=n;i++)
    cout<<a[i]<<' ';
    cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while(tt--)solve();
    return 0;
}
