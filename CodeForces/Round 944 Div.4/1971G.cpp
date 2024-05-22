#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin>>n;
    long long lst[n];
    map<long long,priority_queue<long long>> mp;
    for(long long i=0;i<n;i++)
    {
        long long x,y;
        cin>>lst[i];
        mp[lst[i]>>2].push(-lst[i]);
    }
    for(long long i=0;i<n;i++)
    {
        cout<<-mp[lst[i]>>2].top()<<' ';
        mp[lst[i]>>2].pop();
    }
    cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
