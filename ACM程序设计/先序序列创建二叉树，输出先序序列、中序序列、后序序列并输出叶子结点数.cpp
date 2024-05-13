    #include <bits/stdc++.h>
    using namespace std;

    char s[1000];
    int ans;
    string tree;
    int cnt=1;
    void build(int node)
    {
        s[node] = tree[cnt++];
        if (s[node] == '#')
            return;
        
        build(node * 2);
        build(node * 2 + 1);
    }
    void preorder(int node)
    {
        if (s[node] == '#')
            return;
        if (s[node * 2] == '#' && s[node * 2 + 1] == '#')
            ans++;
        cout << s[node];
        preorder(node * 2);
        preorder(node * 2 + 1);
    }
    void inorder(int node)
    {
        if (s[node] == '#')
            return;
        inorder(node * 2);
        cout << s[node];
        inorder(node * 2 + 1);
    }
    void postorder(int node)
    {
        if (s[node] == '#')
            return;
        postorder(node * 2);
        postorder(node * 2 + 1);
        cout << s[node];
    }
    void solve()
    {
        cin>>tree;
        if(tree[0]=='#')
        {
            cout<<0;;
            return;
        }
        tree=' '+tree;
        tree.resize(1000,'#');
        build(1);
        preorder(1);
        cout<<'\n';
        inorder(1);
        cout<<'\n';
        postorder(1);
        cout<<'\n';
        cout << ans;
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
