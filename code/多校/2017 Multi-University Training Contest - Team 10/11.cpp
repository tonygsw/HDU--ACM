#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<cstdio>
#include<string.h>
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
#define ll long long
#define maxn 100005
class node{
	public:
		int no;
		ll len;
		friend bool operator< (node n1, node n2)
		{
			return n1.len>n2.len;
		}
};
vector<node> mari[maxn];int n,m;
bool vis[maxn];int numofway;ll minway;ll lenofway;
void init()
{
	numofway=0;
	minway=0x3f3f3f3f;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=n;i++)
		mari[i].clear();
}
void bfs()
{
	node be,tem,nex;
	priority_queue<node>way;
	be.no=1;be.len=0;
	way.push(be);
	vis[be.no]=1;
	while(!way.empty())
	{
		tem=way.top();
		if(tem)
		way.pop();
		vis[tem.no]=1;
		for(int i=1;i<=mari[tem.no].size();i++)
		{
			nex.no=mari[tem.no][i].no;
			nex.len=tem.len+mari[tem.no][i].len;
			if(!vis[nex.no])
				way.push(nex);
		}
	}
}
int main()
{
	int t;node tem;int x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		init();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%I64d",&x,&tem.no,&tem.len);
			mari[x].push_back(tem);
		}
	}
}
int main()
{
}
