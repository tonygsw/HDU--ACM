#include<iostream>
#include<string.h>
using namespace std;
int map[1005][1005];int map1[1005][1005];
int vis[1005];
#define INF 0xfffff;
int n,m;	int a,b,ans=0;
void djksl(){
	
}
void bfs(int k)
{
	if(k==2)
	{
		ans++;return;
	}
	for(int i=1;i<=n;i++)
	{
		if(map[k][i]!=0&&vis[i]==0&&map1[k][2]>map1[i][2])
		{
		//	cout<<i<<" "<<endl;
			vis[i]=1;
			bfs(i);
			vis[i]=0;
		}
	}
}
int main()
{
	while(cin>>n&&n!=0)
	{
		cin>>m;
		memset(map,0,sizeof(map));
		memset(map1,1,sizeof(map1));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;i++)
		{
			cin>>a>>b;
			cin>>map[a][b];
			map[b][a]=map[a][b];
			map1[a][b]=map1[b][a]=map[a][b];
		}
		for(int i=1;i<=n;i++){
			map1[i][i]=0;
		}
		ans=0;
		vis[1]=1;
		bfs(1);
		cout<<ans<<endl;
	}
}
