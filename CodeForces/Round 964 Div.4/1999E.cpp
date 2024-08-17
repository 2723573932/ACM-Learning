#include <bits/stdc++.h>
using namespace std;

int log3(int x)
{
    int ret = 0;
    while (x)
    {
        x /= 3;
        ret++;
    }
    return ret;
}
vector<int> pre(2e5+3);
void ini()
{
    pre[0] = 0;
    for (int i = 1; i < pre.size(); i++)
    {
        pre[i] = pre[i - 1] + log3(i);
    }
}
void solve()
{
    int l,r;
    cin>>l>>r;
    cout<<pre[r]-pre[l-1]+log3(l)<<'\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
ini();
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}
