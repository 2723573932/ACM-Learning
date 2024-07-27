#include <bits/stdc++.h>
using namespace std;

vector<long long> lst;
class SGT
{
private:
    struct Segment
    {
        long long val;
        long long add;
    };
    vector<Segment> st;

public:
    SGT(long long n) : st(n << 2) {};
    void cal(long long node)
    {
        st[node].val = st[node * 2].val + st[node * 2 + 1].val;
    }
    void build(long long node, long long l, long long r)
    {
        if (l == r)
            st[node].val = lst[l];
        else
        {
            long long mid = (l + r) / 2;
            build(node*2, l, mid);
            build(node*2+1, mid + 1, r);
            cal(node);
        }
    }
    void pushdown(long long node, long long l, long long r)
    {
        st[node].val += st[node].add * (r - l + 1);
        if (l < r)
        {
            st[node * 2].add += st[node].add;
            st[node * 2 + 1].add += st[node].add;
        }
        st[node].add = 0;
    }
    void update(long long node, long long l, long long r, long long x, long long y, long long k)
    {
        pushdown(node, l, r);
        if (x <= l && r <= y)
            st[node].add += k;
        else
        {
            long long mid = (r + l) / 2;
            if (x <= mid)
                update(node * 2, l, mid, x, y, k);
            if (mid + 1 <= y)
                update(node * 2 + 1, mid + 1, r, x, y, k);
            pushdown(node * 2, l, mid);
            pushdown(node * 2 + 1, mid + 1, r);
            cal(node);
        }
    }
    long long query(long long node, long long l, long long r, long long x, long long y)
    {
        pushdown(node, l, r);
        if (x <= l && r <= y)
            return st[node].val;
        else
        {
            long long mid = (l + r) / 2;
            long long ans = 0;
            if (x <= mid)
                ans += query(node * 2, l, mid, x, y);
            if (mid + 1 <= y)
                ans += query(node * 2 + 1, mid + 1, r, x, y);
            return ans;
        }
    }
};
void solve()
{
    long long n, f;
    cin >> n >> f;
    long long m = 0;
    cin >> m;
    lst.resize(n);
    for (long long i = 1; i <= n - 1; i++)
    {
        cin >> lst[i];
    }
    SGT tree(n+1);
    tree.build(1, 1, n - 1);
    while (f--)
    {
        long long op;
        cin >> op;
        switch (op)
        {
        case 1:
        {
            long long l, r, k;
            cin >> l >> r >> k;
            l--, r--;
            if (l == 0)
            {
                m += k;
                l = 1;
            }
            tree.update(1, 1, n - 1, l, r, k);
            break;
        }
        case 2:
        {
            long long k;
            cin >> k;
            m += k;
            break;
        }
        case 3:
        {
            long long k;
            cin >> k;
            m -= k;
            break;
        }
        case 4:
        {
            long long l, r, ans = 0;
            cin >> l >> r;
            l--, r--;
            if (l == 0)
            {
                ans += m;
                l = 1;
            }
            ans += tree.query(1, 1, n - 1, l, r);
            cout << ans << '\n';
        }
        break;
        case 5:
        {
            cout << m << '\n';
            break;
        }
        default:
            break;
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
