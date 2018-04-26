#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ans=1;
int fast_fun(long long a,long long n)
{
	while(n>0)
	{
		if(n&1)
			ans*=a;
		a=a*a;
		ans=ans%10;
		a=a%10;
		n>>=1;
	}
	return ans%10;
}
int main()
{
	long long t,n,a;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=1;
		cout<<fast_fun(n,n)<<endl;
	}
}

