#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n+1];
    int now=0;
    for(int i=1;i<=k;i++)
    {
        int tmp=n/k*k+i;if(tmp>n) tmp-=k;//这个是从后往前第一个模 k 余 i 的位置
        if(i&1) for(int j=i;j<=n;j+=k) a[j]=++now;
        else for(int j=tmp;j>0;j-=k) a[j]=++now;
    }
    for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
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
