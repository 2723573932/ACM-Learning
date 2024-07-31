#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x, y;
};
void solve()
{
    string s;
    cin >> s;
    vector<node> lst(s.size() + 1);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'G')
        {
            lst[i + 1] = lst[i];
            lst[i + 1].x++;
        }
        else
        {
            lst[i + 1] = lst[i];
            lst[i + 1].y++;
        }
    }
    int ans=0;
    for(int l=0;l<=s.size();l++)
    for(int r=l+1;r<=s.size();r++)
    {
        if(lst[r].x-lst[l].x==lst[r].y-lst[l].y)
        {
            ans=max(ans,r-l);
        }
    }
    cout<<ans<<'\n';

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
