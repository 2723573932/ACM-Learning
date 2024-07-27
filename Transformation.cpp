#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;
const int N = 100007;
vector<int> lst(N);
int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
class sgt
{
private:
    struct seg
    {
        int val, add, mul = 1, set;
    };
    vector<seg> st;

public:
    sgt() : st(N << 2) {};
    void cal(int node)
    {
        st[node].val = st[node * 2].val + st[node * 2 + 1].val;
    }
    void build(int node, int l, int r)
    {
        if (l == r)
            st[node].val = lst[l];
        else
        {
            int mid = (l + r) >> 1;
            build(node * 2, l, mid);
            build(node * 2 + 1, mid + 1, r);
            cal(node);
        }
    }
    void pushdown(int node, int l, int r)
    {
        if (st[node].set)
            st[node].val = st[node].set * (r - l + 1) % mod;
        st[node].val = (st[node].val * st[node].mul + st[node].add * (r - l + 1)) % mod;
        if (l < r)
        {
            if (st[node].set)
            {
                st[node * 2].set = st[node * 2 + 1].set = st[node].set;
                st[node * 2].mul = st[node * 2 + 1].mul = 1;
                st[node * 2].add = st[node * 2 + 1].add = 0;
            }
            else
            {
                st[node * 2].mul = (st[node * 2].mul * st[node].mul) % mod;
                st[node * 2].add = (st[node * 2].add * st[node].mul + st[node].add) % mod;
                if (st[node * 2].set)
                    st[node * 2].set = (st[node * 2].set * st[node].mul + st[node].add) % mod;

                st[node * 2 + 1].mul = (st[node * 2 + 1].mul * st[node].mul) % mod;
                st[node * 2 + 1].add = (st[node * 2 + 1].add * st[node].mul + st[node].add) % mod;
                if (st[node * 2 + 1].set)
                    st[node * 2 + 1].set = (st[node * 2 + 1].set * st[node].mul + st[node].add) % mod;
            }
        }
        st[node].add = 0;
        st[node].mul = 1;
        st[node].set = 0;
    }
    void add(int node, int l, int r, int x, int y, int k)
    {
        pushdown(node, l, r);
        if (x <= l && r <= y)
        {
            st[node].add = (st[node].add + k) % mod;
        }
        else
        {
            int mid = (l + r) >> 1;
            if (x <= mid)
                add(node * 2, l, mid, x, y, k);
            if (y > mid)
                add(node * 2 + 1, mid + 1, r, x, y, k);
            cal(node);
        }
    }
    void mul(int node, int l, int r, int x, int y, int k)
    {
        pushdown(node, l, r);
        if (x <= l && r <= y)
        {
            st[node].mul = (st[node].mul * k) % mod;
            st[node].add = (st[node].add * k) % mod;
            st[node].set = (st[node].set * k) % mod;
        }
        else
        {
            int mid = (l + r) >> 1;
            if (x <= mid)
                mul(node * 2, l, mid, x, y, k);
            if (mid + 1 <= y)
                mul(node * 2 + 1, mid + 1, r, x, y, k);
            cal(node);
        }
    }
    void set(int node, int l, int r, int x, int y, int k)
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
            int mid = (l + r) >> 1;
            if (x <= mid)
                set(node * 2, l, mid, x, y, k);
            if (mid + 1 <= y)
                set(node * 2 + 1, mid + 1, r, x, y, k);
            cal(node);
        }
    }
    int query(int node, int l, int r, int x, int y, int p)
    {
        pushdown(node, l, r);
        if (l == r)
            return st[node].val * p % mod;
        int mid = (l + r) >> 1;
        int res = 0;
        if (x <= mid)
            res = (res + query(node * 2, l, mid, x, y, p)) % mod;
        if (mid + 1 <= y)
            res = (res + query(node * 2 + 1, mid + 1, r, x, y, p)) % mod;
        return res;
    }
}tree;

void solve(int n, int m)
{
    while(m--)
    {
        int op,x,y,k;
        cin>>op>>x>>y>>k;
        if(op==1)
        tree.add(1,1,n,x,y,k);
        else if(op==2)
        tree.mul(1,1,n,x,y,k);
        else if(op==3)
        tree.set(1,1,n,x,y,k);
        else
        {
            cout<<tree.query(1,1,n,x,y,k)<<'\n';
        }
    }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m && n && m)
        solve(n, m);
    return 0;
}
