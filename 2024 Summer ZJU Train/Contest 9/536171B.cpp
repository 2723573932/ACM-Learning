#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n + 1);
    vector<int> t(n + 1);
    t[0] = d;
    int mex = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        t[i] = min(t[i - 1], abs(a[i] - t[i - 1]));
    }
    stack<int> stk;
    for (int i = n; i > 0; i--)
    {
        if (mex <= t[i-1])
        {
            stk.push(1);
        }
        else
            stk.push(0);
        if (abs(mex - a[i]) < mex)
        {
            mex = mex + a[i];
        }
    }
    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
