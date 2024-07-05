#include <bits/stdc++.h>
using namespace std;

void solve()
{
    double s,a,b;
    cin>>s>>a>>b;
    double ans=(2+(b-a)/(a+b))*s/b/(2-(b-a)/(a+b));
    cout<<fixed<<setprecision(6)<<ans;
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
// t1*b s-t1*b
// t1*a s-t1*a

// t1*b + t2*a s-t1*b-t2*a
// (t1+t2)*a s-(t1+t2)*a

// t3*a=s-t1*b-t2*a==t1*a
// t3*b=s-(t1+t2)*a

// (t1-t2)*b=(t1+t2)*a
// t2(a+b)=t1(b-a)
//t2=t1(b-a)/(a+b)

//(t3+t2)*a+t1*b=s
//(t1+t2)*a+t3*b=s
//(t1-t2+t3)*b=s
//(t1(2-(b-a)/(a+b)))=s/b
// t1=s/b/(2-(b-a)/(a+b))
//(t3-t2)b==(t3+t2)a
// t*(a+b)+t2(a-b)=2s
