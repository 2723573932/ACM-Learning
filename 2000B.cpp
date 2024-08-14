#include <bits/stdc++.h>
using namespace std;

vector<int> lst(2e5 + 7);
vector<int> vis(2e5 + 7);
void solve()
{
    int n,f=1;
    cin >> n;
    fill(lst.begin(), lst.begin() + n + 4, 0);
    fill(vis.begin(), vis.begin() + n + 4, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(vis[x]){
            cout<<"NO\n";
            return;
        }vis[x]=1;
        if (i == 1)
        {
            lst[x]++, lst[x + 1]++, lst[x - 1]++;
        }
        else if (lst[x])
        {
            lst[x-1]++;
            lst[x+1]++;
        }
        else {
            f=0;
        }
    }
    if(f)
    cout<<"YES\n";
    else cout<<"NO\n";
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
