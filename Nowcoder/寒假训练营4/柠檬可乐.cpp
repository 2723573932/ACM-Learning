#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,k;
    cin >> a >> b >> k;
    if(a>=b*k)cout<<"good\n";
    else cout<<"bad\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    //cin>>tt;
    while(tt--)solve();
    return 0;
}
