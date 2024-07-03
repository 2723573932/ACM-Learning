#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, P;
    cin >> V >> P;

    vector<int> villages(V);
    for (int i = 0; i < V; i++)
    {
        cin >> villages[i];
    }
    sort(villages.begin(), villages.end());
    
    return 0;
}