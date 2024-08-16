#include <bits/stdc++.h>
using namespace std;
class segtree
{
private:
    vector<int> st;

public:
    segtree() : st(1e7, 0) {};
    void cal(int node)
    {
        st[node] = st[node * 2] + st[node * 2 + 1];
    }
    void build(int node, int l, int r, vector<int> &lst)
    {
        if (l == r)
        {
            st[node] = lst[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, lst);
        build(node * 2 + 1, mid + 1, r, lst);
        cal(node);
    }
    void update(int node, int l, int r, int pos, int k)
    {
        if (l == r)
        {
            st[node] = max(st[node] + k, 0);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(node * 2, l, mid, pos, k);
        else
            update(node * 2 + 1, mid + 1, r, pos, k);
        cal(node);
    }
    int query(int node, int l, int r, int x, int y)
    {
        if (x <= l && r <= y || st[node] == 0)
            return st[node];
        int mid = (l + r) / 2;
        int ret = 0;
        if (x <= mid)
            ret += query(node * 2, l, mid, x, y);
        if (y > mid)
            ret += query(node * 2 + 1, mid + 1, r, x, y);
        return ret;
    }
    void clear()
    {
        st.assign(st.size(), 0);
    }
} sgt;
vector<int> lst;
constexpr int maxn = 2e6 + 3;
void solve()
{
    // sgt.clear();
    lst.assign(maxn, 0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        lst[x] = 1;
    }
    sgt.build(1, 1, maxn, lst);
    int m;
    cin >> m;
    while (m--)
    {
        char op;
        int x;
        cin >> op >> x;
        if (op == '+')
            sgt.update(1, 1, maxn, x, 1);
        else if (op == '-')
            sgt.update(1, 1, maxn, x, -1);
        else
        {
            int l =x, r = maxn;
            while (l < r)
            {
                int mid=l+r>>1;
                if (sgt.query(1, 1, maxn, 1, mid) <=mid-x)
                    r = mid;
                else
                    l = mid + 1;
            }
            cout<<r-x+1<<' ';
        }
    }
    cout << '\n';
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
