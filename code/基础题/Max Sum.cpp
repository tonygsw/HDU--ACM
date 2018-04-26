#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int num[100005];
long long ans,tem;
int main()
{
	int cas,n;
	cin>>cas;
	int c=1;
	while(cas--)
	{
		int ll=0,l=0,r=0;
		ans=-0xfffff;tem=0;
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		for(int i=0;i<n;i++)
		{
			tem=tem+num[i];
			if(tem>ans)
			{
				ans=tem;
				r=i;
				l=ll;
			 }
			 if(tem<0)
			 {
			 	tem=0;
			 	ll=i+1;
			 }
		}
		cout<<"Case "<<c++<<":"<<endl;
		cout<<ans<<" "<<l+1<<" "<<r+1<<endl;
		if(cas!=0)cout<<endl;
	}
}
