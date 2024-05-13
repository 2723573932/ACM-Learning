#include <bits/stdc++.h>
using namespace std;
double a, b, c, x[10], y[10], ans;

int main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b >> c >> x[1] >> y[1] >> x[2] >> y[2];
    ans = fabs(x[1] - x[2]) + fabs(y[1] - y[2]);
    x[3] = x[1];
    y[3] = (-a * x[1] - c) / b;
    x[4] = (-b * y[1] - c) / a;
    y[4] = y[1];
    x[5] = x[2];
    y[5] = (-a * x[2] - c) / b;
    x[6] = (-b * y[2] - c) / a;
    y[6] = y[2];
    for (int i = 3; i <= 4; i++)
        for (int j = 5; j <= 6; j++)
        {
            ans = min(ans, fabs(x[1] - x[i]) + fabs(y[1] - y[i]) +
                               sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) +
                               fabs(x[2] - x[j]) + fabs(y[2] - y[j]));
        }
    cout << setprecision(12) << ans << endl;
    return 0;
}