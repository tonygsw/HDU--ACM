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
ll num2[32];
ll a[500005];
ll num[32];
int les[500005];
void init()
{
	num2[0]=1;
	num2[1]=2;
	for(int i=2;i<=30;i++)
		num2[i]=num2[i-1]*2;
}
int main()
{
	ll t,n;
	init(); 
	scanf("%I46d",&t);
	while(t--)
	{
		scanf("%I64d",&n);
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++)
		{
			scanf("%I64d",&a[i]);
			for(int j=1;j<=30;j++)
				if(a[i]>=num2[j])
					num[j]++;
		}
		sort(a,a+n);
		ll ans=0;
		les[0]=0;
		for(int i=1;i<n;i++)
			if(a[i]>a[i-1])les[i]=les[i-1]+1;
	//	for(int i=0;i<n;i++)
	//		cout<<les[i]<<" ";
		for(int i=1;i<n-1;i++)
		{
			for(int j=1;j<=30;j++)
			{
				if(a[i]<num2[j])
				{
					ans+=les[i]*num[j];
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
