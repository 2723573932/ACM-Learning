#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, b, v = 4, u = 2, tmp = 0;
	cin >> n >> a >> b;
	int ans = 0;
	while (v > 0 || u > 0)
	{
		if (tmp<a&&tmp<b||v==0&&tmp<b||u==0&&tmp<a)
		{
			++ans;
			tmp = n;
		}
		if (tmp >= a && v > 0)
		{
			tmp -= a;
			v--;
		}
		if (tmp >= b && u > 0)
		{
			tmp -= b;
			u--;
		}
		
	}

	cout << ans;
}
