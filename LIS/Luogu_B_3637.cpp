//最长上升子序列
#include <bits/stdc++.h>
using namespace std;

vector<int> low;
void solve()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    low.push_back(x);
    while (--n)
    {
        cin >> x;
        auto it = lower_bound(low.begin(), low.end(), x);
        if (it != low.end())
        *it=x;
        else low.push_back(x);
    }
    cout<<low.size();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}
