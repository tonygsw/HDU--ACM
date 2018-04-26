#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<cstdio>
#include<stdio.h>
#include<map>
using namespace std;
#define ll long long
const ll mod=998244353;
const ll maxn=1e6+5;
int prime[maxn];
bool check[maxn];
map<int,int>zs;int tot=0;
void init()
{
	tot=0;
	for(int i=2;i<maxn;i++)
	{
		if(!check[i])
			prime[tot++]=i;
		for(int j=0;j<tot;j++)
		{
			if(i*prime[j]>maxn)break;
			check[i*prime[j]]=true;
		}
	}
}
ll fast_mod(ll a, ll b) {
    ll res = 1;
    while(b != 0) {
        if(b&1) res = (res * a) % mod;
        a = (a*a) % mod;
        b >>= 1;
    }
    return res;
}
bool judge(ll n)
{
	for(int i=0;i<sqrt(n);i++)
		if(n%prime[i]==0)return true;
	return false;
 } 
ll l,r,k;
int main()
{
	int t;
	init();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d%I64d%I64d",&l,&r,&k);
		zs.clear();
		if(l==1)l++;
		for(ll i=l;i<=r;i++)
		{
			ll temi=i;
			if(temi>=maxn&&judge(temi)==false)
			{
				zs[i]=2;
				continue;
			}
			if(temi<maxn&&!check[temi])
			{
				zs[i]=2;
				continue;
			}
			ll temans=1;
			for(int j=0;j<tot;j++)
			{
				ll ten=0;
				if(temi%prime[j]==0)
				{
					while(temi%prime[j]==0)
					{
						temi=temi/prime[j];
						ten++;
					}
				}
				temans=temans*(ten*k+1); 
			}
			zs[i]=temans;
		}
		ll ans=0;
		for(int i=l;i<=r;i++)
			ans+=zs[i]%mod;
		cout<<ans<<endl; 
			
	}
}
