#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int p = 0;
    int tmp = 0;
    int cnt = 0;
    int ans=0;
    while (p < s.size())
    {
        if (tmp)
        {
            tmp--;
            p++;
            continue;
        }
        if(s[p]=='1')
        {
            cnt=0;
            p++;
        }
        else
        {
            cnt++;
            if(cnt==m){
                ans++;
                tmp=k-1;
                cnt=0;
            }
            p++;
        }
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
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}
