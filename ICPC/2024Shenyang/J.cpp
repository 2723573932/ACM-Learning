#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string A,B;
    int a,b;
    a=b=0;
    for(int i=0;i<4;i++)
    {
        string name;
        int score;
        cin>>name>>score;
        if(score>a)
        {
            A=name;
            a=score;
        }
    }
    for(int i=0;i<4;i++)
    {
        string name;
        int score;
        cin>>name>>score;
        if(score>b)
        {
            B=name;
            b=score;
        }
    }
    if(a<b)
        swap(A,B);
    cout<<format("{} beats {}",A,B);
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
system("pause");
#endif
    return 0;
}
