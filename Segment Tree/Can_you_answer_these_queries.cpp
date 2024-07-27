#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 100007;
vector<long long> lst(N);
class SGT
{
private:
    vector<ll> st;

public:
    SGT(int n) : st(n << 2) {};
    void cal(int node)
    {
        st[node] = st[node * 2] + st[node * 2 + 1];
    }
    void build(int node, int l, int r)
    {
        if (l == r)
            st[node] = lst[l];
        else
        {
            int mid = (l + r) / 2;
            build(node * 2, l, mid);
            build(node * 2 + 1, mid + 1, r);
            cal(node);
        }
    }
    void update(int node, int l, int r, int x, int y)
    {
        if (l == r)
            st[node] = sqrt(st[node]);
        else if (st[node] == r - l + 1 && x <= l && r <= y)
            return;
        else
        {
            int mid = (l + r) / 2;
            if (x <= mid)
                update(node * 2, l, mid, x, y);
            if (mid + 1 <= y)
                update(node * 2 + 1, mid + 1, r, x, y);
            cal(node);
        }
    }
    ll query(int node, int l, int r, int x, int y)
    {
        if (x <= l && r <= y)
            return st[node];
        else
        {
            int mid = (l + r) / 2;
            ll ret = 0;
            if (x <= mid)
                ret += query(node * 2, l, mid, x, y);
            if (mid + 1 <= y)
                ret += query(node * 2 + 1, mid + 1, r, x, y);
            return ret;
        }
    }
} tree(N);
void solve(int n)
{
    for (int i = 1; i <= n; i++)
        cin >> lst[i];
    tree.build(1, 1, n);
    int m;
    cin >> m;
    while (m--)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        if (x > y)
            swap(x, y);
        if (t == 0)
        {
            tree.update(1, 1, n, x, y);
        }
        else
        {
            cout << tree.query(1, 1, n, x, y) << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, tt = 1;
    while (cin >> n)
    {
        cout << format("Case #{}:\n", tt++);
        solve(n);
    }
    return 0;
}
