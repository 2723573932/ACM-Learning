#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ull> p(n + 1), a(n + 1);
    for (ull i = 1; i <= n; ++i)
    {
        cin >> p[i];
        p[i] = p[i] * p[i] + p[i - 1];
        a[i] = i * i + a[i - 1];
    }
    string s;
    cin >> s;
    s = " " + s;
    set<int> st;
    st.insert(0);
    st.insert(n);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'R' && s[i - 1] == 'L')
            st.insert(i - 1);
    }
    unordered_set<int> ans;
    for (auto it = next(st.begin()); it != st.end(); ++it)
    {
        if (a[*it] - a[*prev(it)] != p[*it] - p[*prev(it)])
        {
            ans.insert(*it);
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        if (s[x] == 'L')
        {
            s[x] = 'R';
            if (s[x + 1] == 'R')
            {
                st.erase(x);
                ans.erase(x);
            }
            if (s[x - 1] == 'L')
            {
                st.insert(x - 1);
            }
            auto it = st.lower_bound(x - 1);
            if (p[*it] - p[*prev(it)] != a[*it] - a[*prev(it)])
            {
                ans.insert(*it);
            }
            else
            {
                ans.erase(*it);
            }
            if (next(it) != st.end())
                if (p[*next(it)] - p[*it] != a[*next(it)] - a[*it])
                {
                    ans.insert(*next(it));
                }
                else
                {
                    ans.erase(*next(it));
                }
        }
        else
        {
            s[x] = 'L';
            if (s[x - 1] == 'L')
            {
                st.erase(x - 1);
                ans.erase(x - 1);
            }
            if (s[x + 1] == 'R')
                st.insert(x);
            auto it = st.lower_bound(x);
            if (p[*it] - p[*prev(it)] != a[*it] - a[*prev(it)])
            {
                ans.insert(*it);
            }
            else
            {
                ans.erase(*it);
            }
            if (next(it) != st.end())
                if (p[*next(it)] - p[*it] != a[*next(it)] - a[*it])
                {
                    ans.insert(*next(it));
                }
                else
                {
                    ans.erase(*next(it));
                }
        }
        cout << (ans.empty() ? "YES" : "NO") << '\n';
    }
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
