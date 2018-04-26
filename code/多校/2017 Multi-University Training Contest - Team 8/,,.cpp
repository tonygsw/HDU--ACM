#include <iostream>
#include <bits/stdc++.h> 
#include <stdio.h>
#define ll long long
using namespace std;
ll mod=1e9+7;
ll shang(ll i,ll j)
{
	if(i%j==0) return i/j;
	return i/j+1;
}
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int n=1;
	freopen("ans.txt","w",stdout);
	while(n++)
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(gcd(i,j)==1)
				ans+=shang(i,j)%mod;
			}
		}
		cout<<ans%mod<<",";
		if(n>=1000001) break;
	}
		
	
}
