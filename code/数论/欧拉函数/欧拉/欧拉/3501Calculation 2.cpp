#include<iostream>
using namespace std;
#define ll long long
const  ll mod=1000000007;
ll euler(ll n)
{
	ll res=n,a=n;
	for(int i=2;i*i<=a;i++)
	{
		if(a%i==0)
		{
			res=res/i*(i-1);//先进行除法是为了防止中间数据的溢出
			while(a%i==0)a/=i;
		}
	}
	if(a>1)res=res/a*(a-1);
	return res;
}
int main()
{
	ll n;
	while(cin>>n&&n!=0)
	{
		ll num=euler(n);
		ll ans=(n)*(n-1)/2;
		ans=(ans-(n*num/2))%mod;
		ans=(ans%mod+mod)%mod;
		cout<<ans<<endl;
	}
}
