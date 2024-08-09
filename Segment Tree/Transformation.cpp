#include <bits/stdc++.h>
using namespace std;
const long long mod = 10007;
const long long N = 100007;
vector<long long> lst(N);
class sgt
{
private:
    struct seg
    {
        long long val, val2, val3, add, mul = 1, set;
    };
    vector<seg> st;

public:
    sgt() : st(N << 2) {};
    void cal(long long node)
    {
        st[node].val = (st[node * 2].val + st[node * 2 + 1].val) % mod;
        st[node].val2 = (st[node * 2].val2 + st[node * 2 + 1].val2) % mod;
        st[node].val3 = (st[node * 2].val3 + st[node * 2 + 1].val3) % mod;
    }
    void build(long long node, long long l, long long r)
    {
        if (l == r)
            st[node].val = lst[l];
        else
        {
            long long mid = (l + r) >> 1;
            build(node * 2, l, mid);
            build(node * 2 + 1, mid + 1, r);
            cal(node);
        }
    }
    void pushdown(long long node, long long l, long long r)
    {
        if (st[node].set)
        {
            st[node].val = st[node].set * (r - l + 1) % mod;
            st[node].val2 = st[node].set * st[node].set % mod * (r - l + 1) % mod;
            st[node].val3 = st[node].set * st[node].set % mod * st[node].set % mod * (r - l + 1) % mod;
        }
        st[node].val = (st[node].val * st[node].mul) % mod;
        st[node].val2 = (st[node].val2 * st[node].mul % mod * st[node].mul) % mod;
        st[node].val3 = (st[node].val3 * st[node].mul % mod * st[node].mul % mod * st[node].mul) % mod;

        st[node].val3 = (st[node].val3 + 3 * st[node].val2 * st[node].add % mod + 3 * st[node].val * st[node].add % mod * st[node].add % mod + st[node].add * st[node].add % mod * st[node].add % mod * (r - l + 1)) % mod;
        st[node].val2 = (st[node].val2 + 2 * st[node].val * st[node].add % mod + st[node].add * st[node].add % mod * (r - l + 1)) % mod;
        st[node].val = (st[node].val + st[node].add * (r - l + 1)) % mod;

        if (l < r)
        {
            if (st[node].set)
            {
                st[node * 2].set = st[node * 2 + 1].set = st[node].set;
                st[node * 2].mul = st[node * 2 + 1].mul = 1;
                st[node * 2].add = st[node * 2 + 1].add = 0;
            }
            // else
            // {
                st[node * 2].mul = (st[node * 2].mul * st[node].mul) % mod;
                st[node * 2].add = (st[node * 2].add * st[node].mul + st[node].add) % mod;
                // if (st[node * 2].set)
                //     st[node * 2].set = (st[node * 2].set * st[node].mul + st[node].add) % mod;

                st[node * 2 + 1].mul = (st[node * 2 + 1].mul * st[node].mul) % mod;
                st[node * 2 + 1].add = (st[node * 2 + 1].add * st[node].mul + st[node].add) % mod;
                // if (st[node * 2 + 1].set)
                //     st[node * 2 + 1].set = (st[node * 2 + 1].set * st[node].mul + st[node].add) % mod;
            // }
        }
        st[node].add = 0;
        st[node].mul = 1;
        st[node].set = 0;
    }
    void add(long long node, long long l, long long r, long long x, long long y, long long k)
    {
        pushdown(node, l, r);
        if (x <= l && r <= y)
        {
            st[node].add = (st[node].add + k) % mod;
        }
        else
        {
            long long mid = (l + r) >> 1;
            if (x <= mid)
                add(node * 2, l, mid, x, y, k);
            if (y > mid)
                add(node * 2 + 1, mid + 1, r, x, y, k);
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
            st[node].mul = (st[node].mul * k) % mod;
            st[node].add = (st[node].add * k) % mod;
        }
        else
        {
            long long mid = (l + r) >> 1;
            if (x <= mid)
                mul(node * 2, l, mid, x, y, k);
            if (mid + 1 <= y)
                mul(node * 2 + 1, mid + 1, r, x, y, k);
            pushdown(node * 2, l, mid);
            pushdown(node * 2 + 1, mid + 1, r);
            cal(node);
        }
    }
    void set(long long node, long long l, long long r, long long x, long long y, long long k)
    {
        pushdown(node, l, r);
        if (x <= l && r <= y)
        {
            st[node].set = k;
            st[node].add = 0;
            st[node].mul = 1;
        }
        else
        {
            long long mid = (l + r) >> 1;
            if (x <= mid)
                set(node * 2, l, mid, x, y, k);
            if (mid + 1 <= y)
                set(node * 2 + 1, mid + 1, r, x, y, k);
            pushdown(node * 2, l, mid);
            pushdown(node * 2 + 1, mid + 1, r);
            cal(node);
        }
    }
    long long query(long long node, long long l, long long r, long long x, long long y, long long p)
    {
        pushdown(node, l, r);
        if (x <= l && r <= y)
        {
            if (p == 1)
                return st[node].val;
            else if (p == 2)
                return st[node].val2;
            else
                return st[node].val3;
        }
        long long mid = (l + r) >> 1;
        long long res = 0;
        if (x <= mid)
            res = (res + query(node * 2, l, mid, x, y, p)) % mod;
        if (mid + 1 <= y)
            res = (res + query(node * 2 + 1, mid + 1, r, x, y, p)) % mod;
        return res;
    }
    void rebuild()
    {
        fill(st.begin(), st.end(), seg());
    }
} tree;

void solve(long long n, long long m)
{
    while (m--)
    {
        long long op, x, y, k;
        cin >> op >> x >> y >> k;
        if (op == 1)
            tree.add(1, 1, n, x, y, k);
        else if (op == 2)
            tree.mul(1, 1, n, x, y, k);
        else if (op == 3)
            tree.set(1, 1, n, x, y, k);
        else
        {
            cout << tree.query(1, 1, n, x, y, k) << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    while (cin >> n >> m && n && m)
    {
        solve(n, m);
        fill(lst.begin(), lst.end(), 0);
        tree.rebuild();
    }
    return 0;
}
