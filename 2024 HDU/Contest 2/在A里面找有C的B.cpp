#include<bits/stdc++.h>
using namespace std;
#define int long long
using ull=unsigned long long;
vector<ull> p((int)1e5+7);
ull base=131;
void ini()
{
	p[0]=1;
	for(int i=1; i<=1e5+3; i++)
	{
		p[i]=p[i-1]*base;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt=1;
	ini();
	cin>>tt;
	while(tt--)
	{
		int n;
		cin>>n;
		string a,c;
		cin>>a>>c;
		int la=a.size(),lc=c.size();
		vector<ull> ha(la+1),hc(lc+1);
		for(int i=0; i<la; i++)
		{
			ha[i+1]=ha[i]*base+a[i];
		}
		for(int i=0; i<lc; i++)
		{
			hc[i+1]=hc[i]*base+c[i];
		}
		for(int i=0; i<n; i++)
		{
			string b,bb;
			cin>>b>>bb;
			int lb=b.size(),lbb=bb.size();
			vector<ull> hb(lb+1),hbb(lbb+1);
			for(int k=0; k<lb; k++)
			{
				hb[k+1]=hb[k]*base+b[k];
			}
			for(int k=0; k< lbb; k++)
			{
				hbb[k+1]=hbb[k]*base+bb[k];
			}
			int f1=0,f2=0;
			for(int pos=0; pos<=la-lb; pos++)
			{
				if(ha[pos+lb]-ha[pos]*p[lb]==hb[lb])
				{
					f1=1;
					break;
				}
			}
			for(int pos=0; pos<=lbb-lc; pos++)
			{
				if(hbb[pos+lc]-hbb[pos]*p[lc]==hc[lc])
				{
					f2=1;
					break;
				}
			}
			if(f1&&f2)
				cout<<i+1<<" ";
		}
		cout<<'\n';
	}

	return 0;
}
