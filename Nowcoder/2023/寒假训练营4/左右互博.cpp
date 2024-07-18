#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,a,f=1;
    cin>>n;
    while(n--)
    {
        cin>>a;
        if(!(a&1))
        {
            f=-f;
        }
    }
    if(f==-1)
    cout<<"gui\n";
    else cout<<"sweet\n";

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
