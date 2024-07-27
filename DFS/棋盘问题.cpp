#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void dfs(vector<pair<int, int>>& mp, vector<int>& xx, vector<int>& yy, int len, int k, int& ans, int pos, int cnt) {
    if (cnt == k) {
        ans++;
    } else {
        for (int i = pos; i < len; i++) {
            int x = mp[i].first;
            int y = mp[i].second;
            if (!xx[x] && !yy[y]) {
                xx[x] = yy[y] = 1;
                dfs(mp, xx, yy, len, k, ans, i, cnt + 1);
                xx[x] = yy[y] = 0;
            }
        }
    }
}

void solve() {
    int n, k;
    while (cin >> n >> k && !(n == -1 && k == -1)) {
        vector<pair<int, int> > mp;
        vector<int> xx(n + 1), yy(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                char x;
                cin >> x;
                if (x == '#') {
                    mp.push_back(make_pair(i, j));
                }
            }
        }
        int len = mp.size();
        int ans = 0;
        dfs(mp, xx, yy, len, k, ans, 0, 0);
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
