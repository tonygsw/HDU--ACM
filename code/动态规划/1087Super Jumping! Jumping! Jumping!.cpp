#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int num[1005];
int d[1005];
int dp(int n)
{
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)
	{
		int maxx=0;
		for(int j=i;j>=0;j--)
		{
			if(num[i]>num[j])
			{
				if(maxx<d[j])maxx=d[j];
			}
		}
		d[i]=maxx+num[i];
	}
	int max=d[1];
	for(int i=1;i<=n;i++)
	{
		if(d[i]>max)max=d[i];
	}
	return max;
}
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		cout<<dp(n)<<endl;
	}
}
