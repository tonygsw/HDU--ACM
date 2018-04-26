#include<iostream>
#include<string.h> 
using namespace std;
int ship[3005][3005];int n,m;
int minn(int a,int b)
{
	if(a>b)return b;
	else return a;
}
int main()
{
	while(cin>>n>>m)
	{
		int u,v,w;
		memset(ship,0,sizeof(ship));
		for(int i=0;i<m;i++)
		{
			cin>>u>>v>>w;
			ship[u][v]+=w;
			ship[v][u]+=w;
		}
		int ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			int temans=0;
			for(int j=1;j<=n;j++)
				temans+=ship[i][j];
			ans=minn(temans,ans);
		}
		cout<<ans<<endl;
	}
}
