 #include <bits/stdc++.h>
 using namespace std;
 
 void solve()
 {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0]>>a[i][1];
    }
    sort(a.begin(), a.end(), [](array<int, 2> x, array<int, 2> y) {
        return x[0]+x[1]<y[0]+y[1];
    });
    for(const auto &[a,b]:a){
        cout<<a<<" "<<b<<" ";
    }
    cout<<'\n';
 }
 int main()
 {
 #if !LOCAL
     ios::sync_with_stdio(0);
     cin.tie(0);
 #endif
     int tt = 1;
     cin >> tt;
     while (tt--)
         solve();
 #if LOCAL
 system("pause");
 #endif
     return 0;
 }
 