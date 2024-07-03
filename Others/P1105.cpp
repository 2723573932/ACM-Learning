#include <bits/stdc++.h>
using namespace std;
struct plat
{
    int h, x, y, num;
};
void solve()
{
    int n;
    cin >> n;
    vector<plat> lst;
    pair<int, int> ans[n + 1];
    lst.push_back({0, 0, 0, 0});
    for (int i = 1; i <= n; i++)
    {
        int x, y, h;
        cin >> h >> x >> y;
        lst.push_back({h, x, y, i});
    }
    sort(lst.begin() + 1, lst.end(), [](plat a, plat b)
         {
        if(a.h==b.h)
        {
            return a.num<b.num;
        }
        return a.h>b.h; });
    for (int i = 1; i <= n; i++)
    {
        int x = lst[i].x, y = lst[i].y, h = lst[i].h, num = lst[i].num;
        int ansx = 0, ansy = 0;
        for (int j = i + 1; j <= n; j++)
        {
            if (ansx == 0)
                if (lst[j].x < x && lst[j].y > x && lst[j].h < h)
                {

                    ansx = lst[j].num;
                }
            if (ansy == 0)
                if (lst[j].x < y && lst[j].y > y && lst[j].h < h)
                {
                    ansy = lst[j].num;
                }
            if (ansx != 0 && ansy != 0)
                break;
        }
        ans[num].first = ansx, ans[num].second = ansy;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
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
