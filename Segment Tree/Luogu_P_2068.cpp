#include <bits/stdc++.h>
using namespace std;

long long N = 100007; 
vector<long long> lst(N);
class ST
{
private:
    struct Segment
    {
        long long val;
        long long add;
    };
    vector<Segment> st;

public:
    ST(long long n) : st(n << 2) {};
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
            build(node * 2, l, mid);
            build(node * 2 + 1, mid + 1, r);
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
        {
            st[node].add += k;
        }
        else
        {
            long long mid=(l+r)/2;
            if(x<=mid)update(node*2,l,mid,x,y,k);
            if(mid+1<=y)update(node*2+1,mid+1,r,x,y,k);
            pushdown(node*2,l,mid);
            pushdown(node*2+1,mid+1,r);
            cal(node);
        }
    }
    long long query(long long node,long long l,long long r,long long x,long long y)
    {
        pushdown(node,l,r);
        if(x<=l&&r<=y)
        {
            return st[node].val;
        }
        else{
            long long mid=(l+r)/2;
            long long ans=0;
            if(x<=mid)ans+=query(node*2,l,mid,x,y);
            if(mid+1<=y)ans+=query(node*2+1,mid+1,r,x,y);
            return ans;
        }
    }
}tree(N+1);
void solve()
{
    long long n,w;
    cin>>n>>w;
    tree.build(1,1,n);
    while(w--)
    {
        char op;long long a,b;
        cin>>op>>a>>b;
        if(op=='x')
        tree.update(1,1,n,a,a,b);
        else
            cout<<tree.query(1,1,n,a,b)<<'\n';
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
