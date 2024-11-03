#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    int a,b;
    cin>>n;
    a=b=0;
    for(int i=1;i<=2*n;i++)
    {
        int x;
        cin>>x;
        if(x==1)
            a++;
        else
            b++;
    }
    if(a<b)swap(a,b);
    cout<<(a&1)<<' '<<b<<'\n';
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
