#include <bits/stdc++.h>
using namespace std;
long long prefix[(int)1e5+7];
void ini()
{
    for(long long x=1;x<=(long long)13000;x++)
    {
        long long y=0;
        while(y>0)
        {
            
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    cout<<prefix[n]-prefix[n-1]<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ini();
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
