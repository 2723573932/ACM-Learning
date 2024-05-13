#include <bits/stdc++.h>
using namespace std;

int tree[1000];
int f = 1;
void preorder(int node)
{
    if (tree[node] == -1)
        return;
    if (f)
    {
        cout << tree[node];
        f = 0;
    }
    else
        cout << " " << tree[node];
    preorder(tree[node] * 2);
    preorder(tree[node] * 2 + 1);
}
void inorder(int node)
{
    if (tree[node] == -1)
        return;
    inorder(tree[node] * 2);
    if (f)
    {
        cout << tree[node];
        f = 0;
    }
    else
        cout << " " << tree[node];
    inorder(tree[node] * 2 + 1);
}
void postorder(int node)
{
    if (tree[node] == -1)
        return;
    postorder(tree[node] * 2);
    postorder(tree[node] * 2 + 1);
    if (f)
    {
        cout << tree[node];
        f = 0;
    }
    else
        cout << " " << tree[node];
}
void solve()
{
    memset(tree, -1, sizeof(tree));
    tree[1] = 1;
    int n;
    cin >> n;
    while (n--)
    {
        int node, l, r;
        cin >> node >> l >> r;
        tree[node * 2] = l;
        tree[node * 2 + 1] = r;
    }
    preorder(1);
    cout << '\n';
    f = 1;
    inorder(1);
    cout << '\n';
    f = 1;
    postorder(1);
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}
