#include <bits/stdc++.h>
using namespace std;
#define int long long



void solve()
{
    int n;
    vector<int> a[100];
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        bitset<66> bt(x);
        for(int j=0;j<66;j++){
            if(bt[j]){
                a[j].push_back(i);
            }
        }
    }
    int f=1;
    vector<int> ans1;
    vector<int>ans2;
    for(int i=0;i<100;i++){
        int xi=-1;
        f=1;
        for(int j=0;j<70;j++){
            if(a[j].size()>0){
                f=0;
                if(a[j].size()==2){
                    xi=j;
                    break;
                }
            }
        }
        if(f==1){
            break;
        }
        if(xi==-1){
            cout<<"-1\n";
            return;
        }
        int x=a[xi][0],y=a[xi][1];
        int an=0;
        for(int j=0;j<70;j++){
            int fx=-1,fy=-1;
            for(int k=0;k<a[j].size();k++){
                if(a[j][k]==x){
                    fx=k;
                }
                if(a[j][k]==y){
                    fy=k;
                }
            }
            if(fx!=-1&&fy!=-1){
                if(fx>fy){
                    a[j].erase(a[j].begin()+fx);
                    a[j].erase(a[j].begin()+fy);
                }
                else{
                    a[j].erase(a[j].begin()+fy);
                    a[j].erase(a[j].begin()+fx);
                }
                an+=(1LL<<j);
            }
        }
        ans1.push_back(an);
        ans2.push_back(x);
    }
    if(f==0){
        cout<<"-1\n";
        return;
    }
    cout<<ans1.size()<<"\n";
    for(int i=0;i<ans1.size();i++){
        cout<<ans2[i]<<" "<<ans1[i]<<"\n";
    }
    return;
}
signed main()
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
