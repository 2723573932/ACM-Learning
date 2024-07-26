#include <bits/stdc++.h>
using namespace std;
vector<int> lst;
class SGT{
    private:
        struct Segment
        {
            int val;
            int add;
        };
        vector<Segment> st;
    public:
        SGT(int n):st(n<<2){};
        void cal(int node)
        {
            st[node].val=st[node*2].val+st[node*2+1].val;
        }
        void build(int node,int l,int r)
        {
            if(l==r)
                st[node].val=lst[l];
            else{
                int mid=(l+r)/2;
                build(node,l,mid);
                build(node,mid+1,r);
                cal(node);
            }
        }
        void pushdown(int node,int l,int r)
        {
            st[node].val+=st[node].add;
            if(l<r)
            {
                st[node*2].add+=st[node].add;
                st[node*2+1].add+=st[node].add;
            }
            st[node].add=0;
        }
        void update(int node,int l,int r,int x,int y)
        {
            pushdown(node,l,r);
            if(l==r)
        }
};
void solve()
{
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
