//without lazytag
#include <bits/stdc++.h>
using namespace std;
vector<long long> lst;
class SegmentTree
{
private:
    vector<long long> segm_tree;

public:
    SegmentTree(long long n)
    {
        segm_tree.resize((n + 1) << 2);
    }
    void rec(long long node)
    {
        segm_tree[node] = segm_tree[2 * node] + segm_tree[2 * node + 1];
    }
    void build(long long node, long long l, long long r)
    {
        if (l == r)
            segm_tree[node] = lst[l];
        else
        {
            long long mid = (l + r) / 2;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);
            rec(node);
        }
    }
    void update(long long node, long long l, long long r, long long x, long long y, long long k)
    {
        if (l == r)
            segm_tree[node] += k;
        else
        {
            long long mid = (l + r) / 2;
            if (x <= mid)
                update(2 * node, l, mid, x, y, k);
            if (y >= mid + 1)
                update(2 * node + 1, mid + 1, r, x, y, k);
            rec(node);
        }
    }
    long long query(long long node, long long l, long long r, long long x, long long y)
    {
        if (x <= l and r <= y)
            return segm_tree[node];
        else
        {
            long long ans = 0;
            long long mid = (l + r) / 2;
            if (x <= mid)
            {
                ans += query(2 * node, l, mid, x, y);
            }
            if (y >= mid + 1)
            {
                ans += query(2 * node + 1, mid + 1, r, x, y);
            }
            return ans;
        }
    }
};
void solve()
{
    long long n, m;
    cin >> n >> m;
    lst.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> lst[i];
    SegmentTree segtree(n);
    segtree.build(1, 1, n);
    while (m--)
    {
        int op, x, y, k;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            segtree.update(1, 1, n, x, y,k);
        }
        else
        {
            cin >> x >> y;
            cout << segtree.query(1, 1, n, x, y) << '\n';
        }
    }
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
