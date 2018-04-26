#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string>
#include<cmath> 
#include<string.h>
#include<stdio.h>
#include<cstdio> //freopen("2.txt","w",stdout);
using namespace std;
#define ll long long
const ll mod=109+7;
ll euler(ll n)
{
	ll res=n,a=n;
	for(int i=2;i*i<=a;i++)
	{
		if(a%i==0)
		{
			res=res/i*(i-1);			// 先进行除法是为了防止中间数据的溢出 
			while(a%i==0)a/=i;
		}
	}
	if(a>1)res=res/a*(a-1);
	return res;
}
ll fast_pow(ll x,ll y)//快速幂 
{
	ll ans=1;
	while(y>0)
	{
		if(y&1)
			ans=ans*x;
		x=x*x;
		y>>=1; 
	}
	return ans;
}
int main()
{
	ll n,k;
	while(cin>>n>>k)
	{
		ll ans=0,tem=0;
		ll len=fast_pow((ll)n,(ll)k);
		cout<<len<<endl; 
		for(int i=1;i<=len;i++)
		{
		//	cout<<"((int)sqrt((len/i)))="<<((int)sqrt((len/i)))<<endl;
			ans+=euler(i)*euler(i)*((int)sqrt((len/i)))%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
