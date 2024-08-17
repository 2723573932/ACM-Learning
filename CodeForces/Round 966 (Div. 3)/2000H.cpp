/*线段树二分*/
#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5e6;
class sgtree
{
private:
    vector<int> tree;

public:
    sgtree() : tree(2e7) {}
    void cal(int node)
    {
        tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    }
    void update(int node, int l, int r, int pos, int k)
    {
        if (l == r)
        {
            tree[node] = k;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(node << 1, l, mid, pos, k);
        else
            update(node << 1 | 1, mid + 1, r, pos, k);
        cal(node);
    }
    int query(int node, int l, int r, int k)
    {
        if (l == r)
            return l;
        int mid = (l + r) >> 1;
        if (tree[node << 1] >= k)
            return query(node << 1, l, mid, k);
        else
            return query(node << 1 | 1, mid + 1, r, k);
    }
    void clear(set<int> &st)
    {
        for (auto x : st)
            if (x != maxn)
                update(1, 1, maxn, x+1, 0);
    }
} sgt;
void solve()
{
    int n, m;
    cin >> n;
    set<int> st;
    st.insert(0);
    st.insert(maxn);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    auto it = st.begin();
    for (int i = 0; i <= n; i++)
    {
        sgt.update(1, 1, maxn, *it + 1, *next(it) - *it - 1);
        it++;
    }
    cin >> m;
    while (m--)
    {
        char op;
        int x;
        cin >> op >> x;
        if (op == '-')
        {
            auto it = st.lower_bound(x);
            int r = *next(it);
            int l = *prev(it);
            sgt.update(1, 1, maxn, l + 1, r - l - 1);
            sgt.update(1, 1, maxn, x + 1, 0);
            st.erase(x);
        }
        else if (op == '+')
        {
            st.insert(x);
            auto it = st.lower_bound(x);
            int r = *next(it);
            int l = *prev(it);
            sgt.update(1, 1, maxn, l + 1, x - l - 1);
            sgt.update(1, 1, maxn, x + 1, r - x - 1);
        }
        else
        {
            cout << sgt.query(1, 1, maxn, x) << ' ';
        }
    }
    cout << '\n';
    sgt.clear(st);
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
