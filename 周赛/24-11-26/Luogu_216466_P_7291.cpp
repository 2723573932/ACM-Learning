#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void solve()
{
    int n = read();
    ll ans = 0;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        ans = max(ans, a[i] * i);
    }
    int pos = n;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] > a[pos])
        {
            ans = max(ans, a[pos] * (pos + i));
            pos = i;
        }
        else
        {
            ans = max(ans, a[i] * (pos + i));
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    int tt = 1;
    // tt = read();
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}
