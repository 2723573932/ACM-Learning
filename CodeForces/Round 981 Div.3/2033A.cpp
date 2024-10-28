#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int ans=0;
    int f=1;
    int i=1;
    while(abs(ans)<=n)
    {
        f=-f;
        ans+=f*(2*i-1);
        i++;
    }
    if(f==1)cout<<"Kosuke\n";
    else cout<<"Sakurako\n";
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
