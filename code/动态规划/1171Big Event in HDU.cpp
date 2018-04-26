/*-----------2017.4.11---------*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m;	int cont=1;
int v[5005];	int sum=0;
int d[255555];
void dp()
{
	memset(d,0,sizeof(d));
	for(int i=0;i<cont;i++)
	{
		for(int j=(sum/2);j>=v[i];j--)
		{
			d[j]=max(d[j],d[j-v[i]]+v[i]);
		}
	}
}
int main()
{
	
	int vi;
	while(~scanf("%d",&n)&&n>0)
	{
		memset(v,0,sizeof(v));
		sum=0;cont=0;
		for(int j=0;j<n;j++)
		{
			 scanf("%d%d",&vi,&m);//cin>>vi>>m;
			for(int i=0;i<m;i++)
			{
				v[cont]=vi;
				cont++;
				sum=sum+vi;
			}
		}
		dp();
		 printf("%d %d\n",sum-d[sum/2],d[sum/2]);  
	//	cout<<sum-d[sum/2]<<" "<<d[sum/2]<<endl;
	}
	return 0;
}
