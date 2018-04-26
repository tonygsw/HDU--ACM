#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<stdio.h>
#include<cstdio> //freopen("2.txt","w",stdout);
#define ll long long
using namespace std;
const int maxn=1e5+5;
const ll mod=1e9+7;
ll a[200005];int n;
int prime[maxn];
bool check[maxn];
int mi[maxn+5];
ll minn(ll a,ll b)
{
	if(a<b)return a;
	else return b;
}
ll maxxn(ll a,ll b)
{
	if(a>b)return a;
	else return b;
}
void init()
{
	mi[1]=1;
	int tot=0;
	for(int i=2;i<maxn;i++)
	{
		if(!check[i])
		{
			mi[i]=-1;
			prime[tot++]=i;
		}
		for(int j=0;j<tot;j++)
		{
			if(i*prime[j]>maxn)break;
			check[i*prime[j]]=true;
			if(i%prime[j]==0)
			{
				mi[i*prime[j]]=0;
				break;
			}
			else
				mi[i*prime[j]]=-mi[i];
		}
	}
}
ll fast_pow(ll a,ll x)
{
	ll ans=1;
	while(x)
	{
		if(x&1)ans=ans*a%mod;
		a=a*a%mod;
		x>>=1;
	}
	return ans;
}
int main()
{
	int t,tem,ca=1;
	init();
	freopen("1009.in","r",stdin);
	cin>>t;
	while(t--)
	{
		
		cin>>n;
		ll mina=0x3f33f3ff3f3f;
		ll maxa=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			cin>>tem;
			a[tem]++;
			mina=minn(mina,tem);
		}
		for(int i=1;i<200005;i++)
			a[i]=a[i-1]+a[i];  
		ll sum=0;
		for(ll i=2;i<=mina;i++)
		{
			ll gg=1;
			for( j=1;j*i<maxn;j++)
				gg=gg*fast_pow((ll)j,a[(j+1)*i-1]-a[j*i-1])%mod;
			sum=(sum-mi[i]*gg+mod)%mod;
			
		}
		cout<<"Case #"<<ca++<<": "<<sum<<endl;
	}
	return 0;
}
