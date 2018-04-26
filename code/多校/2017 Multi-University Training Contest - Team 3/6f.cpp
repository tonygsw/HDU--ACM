#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<stdio.h>
#include<cstdio> //freopen("2.txt","w",stdout);
#define ll long long
const ll mod=998244353;
ll c[100005];ll n,m;
ll ans[100005];
ll tema[100005];
ll cn[2][100005];
using namespace std;
ll cc(ll n,ll r)
{
	ll ans=1;
	for(int i=0;i<r;i++)
		ans=ans*(n-i)/(i+1)%mod;
	return ans;
}
ll fast_pow(ll a, ll b) {
    ll res = 1;
    while(b != 0) {
        if(b&1) res = (res * a) %mod;
        a = (a*a) %mod;
        b >>= 1;
    }
    return res;
}
void init(ll x)
{
	tema[0]=1;
	for(int i=1;i<100005;i++)
		tema[i]=fast_pow(x,i)%mod;
}
int main()
{
//	cout<<((-2)%3)<<endl;
	while(~scanf("%I64d",&n))
	{
		for(int i=0;i<=n;i++)
			scanf("%I64d",&c[i]);
		scanf("%I64d",&m);
		ll toa=0,tem=0;
		for(int i=0;i<m;i++)
		{
			scanf("%I64d",&tem);
			toa+=tem;
		}
		init(-toa);
		memset(ans,0,sizeof(ans));
		cn[0][0]=1;cn[0][1]=1;
		cn[1][0]=1;cn[1][1]=1;
		ans[0]+=c[0]-c[1]*toa;
		ans[1]+=c[1];
		for(int i=2;i<=n;i++)
		{
			if(c[i]!=0)
				for(int j=0;j<=i;j++)
				{
					if(j==0)
						ans[i-j]+=c[i]*tema[j];
					else if(j==i)ans[0]+=c[i];
					else
					{
						ans[i-j]+=c[i]*(cn[(j-1)%2][j]+cn[(j-1)%2][j-1])*tema[j];
					//	cout<<cn[(j-1)%2][j]+cn[(j-1)%2][j-1]<<endl;
						cn[j%2][j]=cn[(j-1)%2][j]+cn[(j-1)%2][j-1];
					}
				}
		}
		for(int i=0;i<=n;i++)
			cout<<(ans[i]%mod+mod)%mod<<" ";
		cout<<endl;
	}
	return 0;
}
