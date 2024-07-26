//with multitags
#include <bits/stdc++.h>
using namespace std;
long long mod;
vector<long long> lst;
class TREE
{
private:
    struct segment
    {
        long long val;
        long long add = 0;
        long long mul = 1;
    };
    vector<segment> ST;

public:
    TREE(long long n) : ST((n + 1) << 2) {};
    void cal(long long node)
    {
        ST[node].val = (ST[node * 2].val + ST[node * 2 + 1].val) % mod;
    }
    void build(long long node, long long l, long long r)
    {
        if (l == r)
            ST[node].val = lst[l] % mod;
        else
        {
            long long mid = (l + r) / 2;
            build(node * 2, l, mid);
            build(node * 2 + 1, mid + 1, r);
            cal(node);
        }
    }
    void pushdown(long long node, long long l, long long r)
    {
        ST[node].val = (ST[node].val * ST[node].mul % mod + ST[node].add * (r - l + 1)) % mod;
        if (l < r)
        {
            // ST[node * 2].val = (ST[node * 2].val * ST[node].mul) % mod;
            // ST[node * 2 + 1].val = (ST[node * 2 + 1].val * ST[node].mul) % mod;
            ST[node * 2].mul = (ST[node * 2].mul * ST[node].mul) % mod;
            ST[node * 2 + 1].mul = (ST[node * 2 + 1].mul * ST[node].mul) % mod;
            ST[node * 2].add = (ST[node * 2].add * ST[node].mul) % mod;
            ST[node * 2 + 1].add = (ST[node * 2 + 1].add * ST[node].mul) % mod;

            ST[node * 2].add = (ST[node * 2].add + ST[node].add) % mod;
            ST[node * 2 + 1].add = (ST[node * 2 + 1].add + ST[node].add) % mod;
        }
        ST[node].add = 0;
        ST[node].mul = 1;
    }
    void add(long long node, long long l, long long r, long long x, long long y, long long k)
    {
        pushdown(node, l, r);
        if (x <= l && r <= y)
            ST[node].add = (k + ST[node].add) % mod;
        else
        {
            long long mid = (l + r) / 2;
            if (x <= mid)
            {
                add(node * 2, l, mid, x, y, k);
            }
            if (mid + 1 <= y)
            {
                add(node * 2 + 1, mid + 1, r, x, y, k);
            }
            pushdown(node * 2, l, mid);
            pushdown(node * 2 + 1, mid + 1, r);
            cal(node);
        }
    }
    void mul(long long node, long long l, long long r, long long x, long long y, long long k)
    {
        pushdown(node, l, r);
        if (x <= l && r <= y)
        {
            ST[node].mul = k * ST[node].mul % mod;
            ST[node].add = k * ST[node].add % mod;
        }
        else
        {
            long long mid = (l + r) / 2;
            if (x <= mid)
            {
                mul(2 * node, l, mid, x, y, k);
            }
            if (mid + 1 <= y)
            {
                mul(2 * node + 1, mid + 1, r, x, y, k);
            }
            pushdown(node * 2, l, mid);
            pushdown(node * 2 + 1, mid + 1, r);
            cal(node);
        }
    }
    long long query(long long node, long long l, long long r, long long x, long long y)
    {
        pushdown(node, l, r);
        if (x <= l && r <= y)
        {
            return ST[node].val;
        }
        else
        {
            long long ans = 0;
            long long mid = (l + r) / 2;
            if (x <= mid)
            {
                ans = (ans + query(node * 2, l, mid, x, y)) % mod;
            }
            if (mid + 1 <= y)
            {
                ans = (query(node * 2 + 1, mid + 1, r, x, y) + ans) % mod;
            }
            return ans;
        }
    }
};
void solve()
{
    long long n, q;
    cin >> n >> q >> mod;
    lst.resize(n + 1);
    for (long long i = 1; i <= n; i++)
        cin >> lst[i];
    TREE sgt(n);
    sgt.build(1, 1, n);
    while (q--)
    {
        long long op, x, y, k;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            sgt.mul(1, 1, n, x, y, k);
        }
        else if (op == 2)
        {
            cin >> x >> y >> k;
            sgt.add(1, 1, n, x, y, k);
        }
        else
        {
            cin >> x >> y;
            cout << sgt.query(1, 1, n, x, y) << '\n';
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
