#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k, sum = 0, ans = 0;
    cin >> n >> k;
    int a[n+1];
    memset(a, 0, sizeof(a));
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = (a[i] + a[i - 1]) % k;
    }
    for (auto i : a)
    {
        if (st.find(i) == st.end())
            st.insert(i);
        else
        {
            ans++;
            st.clear();
            st.insert(i);
        }
    }
    cout<<ans;
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
