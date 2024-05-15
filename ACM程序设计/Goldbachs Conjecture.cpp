//https://jiudge.zuccacm.top/#/contest/188/problem/C
#include<bits/stdc++.h>
using namespace std;
bool is_prime[((int)1e6)];
int prime[((int)1e6)];
int cnt;
void init()
{
    int n=1e5;
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime[cnt++]=i;
        }
        for (int j = 0; j < cnt && i * prime[j] <= n; j++)
        {
            is_prime[i*prime[j]]=0;
            if(i%prime[j]==0)break;
        }
    }
}

void solve()
{
    init();
    long long x;
    while(cin>>x&&x!=0)
    {
        long long ans=1;
        for(int i=0;i<cnt&&prime[i]<x;i++)
        if(is_prime[x-prime[i]])
        {
            ans++;
        }
        cout<<(ans)/2<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    // cin>>tt;
    while(tt--)solve();
    return 0;
}
