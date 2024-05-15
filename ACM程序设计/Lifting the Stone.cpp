// https://jiudge.zuccacm.top/#/contest/188/problem/B
// 多边形重心问题
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    pair<double,double> a[n];
    for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
    double x=0,y=0,s=0;
    for(int i=1;i<n-1;i++)
    {
        double tmp=((a[i].first-a[0].first)*(a[i+1].second-a[0].second)-(a[i+1].first-a[0].first)*(a[i].second-a[0].second))/2;
        x+=(a[0].first+a[i].first+a[i+1].first)*tmp;
        y+=(a[0].second+a[i].second+a[i+1].second)*tmp;
        s+=tmp;
    }
    cout<<fixed<<setprecision(2)<<x/(3*s)<<" "<<y/(3*s)<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while(tt--)solve();
    return 0;
}
