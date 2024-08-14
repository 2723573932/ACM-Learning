#include <bits/stdc++.h>
using namespace std;
class segtree
{
private:
    vector<int> st;

public:
    segtree(int n) : st(4 * n, 0) {};
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
    }
    void update(int node, int l, int r, int pos, int k)
    {
        if (l == r)
        {
            st[node] = k;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(node * 2, l, mid, pos, k);
        else
            update(node * 2 + 1, mid + 1, r, pos, k);
    }
    int query(int node, int l, int r, int ql, int qr)
    {
        if (l > qr || r < ql)
            return 0;
        if (l >= ql && r <= qr)
            return st[node];
        int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, qr) + query(node * 2 + 1, mid + 1, r, ql, qr);
    }
};
void solve()
{
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
