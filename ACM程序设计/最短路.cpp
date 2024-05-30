#include <bits/stdc++.h>
using namespace std;

void solve(int N, int M)
{
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INT_MAX));
    for (int i = 1; i <= N; i++)
    {
        graph[i][i] = 0;
    }

    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A][B] = C;
        graph[B][A] = C;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    cout << graph[1][N] << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0)
    {
        solve(n, m);
    }
    return 0;
}
