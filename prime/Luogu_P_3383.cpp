#include <bits/stdc++.h>
using namespace std;

bool is_prime[(int)1e8];
int prime[(int)1e8];
int cnt;
void solve()
{
    int n, q;
    cin >> n >> q;
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++)
        {
            is_prime[i*prime[j]]=0;
            if(i%prime[j]==0)break;
        }
    }
    int x;
    while(q--)
    {
        cin>>x;
        cout<<prime[x]<<'\n';
    }
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
