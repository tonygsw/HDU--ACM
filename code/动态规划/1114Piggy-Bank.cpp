#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int  w[505];	int v[505];	int d[10005];		int t,e,f,n;
#define inf 1<<20
int main()
{
	cin>>t;
	while(t--)
	{
		memset(w,0,sizeof(w));
		memset(v,0,sizeof(v));
		cin>>e>>f>>n;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&v[i],&w[i]);
			//cin>>v[i]>>w[i];
		int tiji=f-e;
		for(int i=0;i<=tiji;i++)
		d[i]=inf;
		d[0]=0;
		for(int i=1;i<=n;i++)
		{	
			for(int j=w[i];j<=tiji;j++)
			{
				d[j]=min(d[j],d[j-w[i]]+v[i]);
			}
		}
		if(d[f-e]==inf)
			cout<<"This is impossible."<<endl;
		else cout<<"The minimum amount of money in the piggy-bank is "
					<<d[f-e]<<"."<<endl;
	}
}
