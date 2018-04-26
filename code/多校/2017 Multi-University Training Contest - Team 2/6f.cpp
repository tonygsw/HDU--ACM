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
const ll mod=1e9+7;
ll ans=0;
ll f(ll m,ll n,ll N)
{
	if(m==1&&n==1)return 1;
	else if(m==1&&n==2)return 1;
	if(m==1)return f(1,n-1,N)+2*f(1,n-2,N);
	for(int x=n;x<=n+N-1;x++)
	{
		ans+=f(m-1,x,N)%mod;
		ans=ans%mod;
	}
	return ans;
}
int main()
{
	freopen("2.txt","w",stdout);
	cout<<f(3,1,3)<<endl;
	for(int i=1;i<10;i++)
	{
		for(int j=1;j<10;j++)
		{
			ans=0; 
			cout<<f((ll)i,1,(ll)j)<<" ";
			if(j%10==0)cout<<endl;
		}
		cout<<endl<<endl;
	}
	return 0;
}
