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
	return 0;
}
