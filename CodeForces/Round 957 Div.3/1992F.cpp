#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<long long> lst;
    lst.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a < x && a != 1 && x % a == 0)
            lst.emplace_back(a);
    }
    // sort(lst.begin(), lst.end());
    set<long long> st;
    int ans = 1;
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        vector<long long> tmp;
        if (!st.contains(x / *it))
        {
            for (const auto &i : st)
            {

                if (*it * i > x)
                    break;
                else
                {
                    tmp.emplace_back(*it * i);
                }
            }
        }
        else
        {
            ans++;
            st.clear();
        }
        st.insert(tmp.begin(), tmp.end());
        st.insert(*it);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
