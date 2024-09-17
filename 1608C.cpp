#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    ans[a[n - 1].second] = 1;
    vector<int> b(n);
    set<int> bs;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        bs.insert(b[i]);
    }
    int maxn = 0, minn = b[a[n - 1].second];
    bs.erase(b[a[n - 1].second]);
    for (int i = n - 2; i >=0; i--)
    {
        maxn = *bs.rbegin();
        if(maxn >= minn)
        {
            ans[a[i].second]=1;
        }
        else{
            break;
        }
        minn = min(b[a[i].second],minn);
        bs.erase(b[a[i].second]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
    }
    cout <<'\n';
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
