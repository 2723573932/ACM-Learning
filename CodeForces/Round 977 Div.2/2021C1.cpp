#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> a(n),ans(n);
    set<int> s;
    for(auto &x:a){
        cin>>x;
    }
    int cur=0;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        if(!s.contains(x)){
            s.insert(x);
            ans[cur++]=x;
        }
    }
    for(int i=0;i<n;i++)
        if(a[i]!=ans[i]&&ans[i]!=0)
        {
            cout<<"TIDAK\n";
            return;
        }
    cout<<"YA\n";
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}
