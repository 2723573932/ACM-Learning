#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    queue<int> q;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (st.contains(x))
        {
            cout << 0 << " ";
            continue;
        }
        int ans = 0;
        while (q.front() != x)
        {
            st.insert(q.front());
            q.pop();
            ans++;
        }
        q.pop();
        cout << ans + 1 << " ";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
