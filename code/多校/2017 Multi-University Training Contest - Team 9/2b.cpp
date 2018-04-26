#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<cstdio>
#include<string.h>
#include<vector>
#include<stdio.h>
#include<queue>
using namespace std;
#define ll long long
const ll maxn=1e5+5;
vector<int> ma[maxn];
ll city[maxn];
int  n;
bool vis[maxn];
class node
{
	public:
		int num;
		ll money;
};
ll maxmony(int be,int en,int a,int b)
{
	node beg;
	memset(vis,0,sizeof(vis));
	beg.num=en;
	if(city[beg.num]>=a&&city[beg.num]<=b)beg.money=city[en];
	else beg.money=0;
	vis[en]=1;
	queue<node> way;
	way.push(beg);
	node tem,nex;
	while(!way.empty())
	{
		tem=way.front();
		way.pop();
		vis[tem.num]=1;
		if(tem.num==be)return tem.money;
		for(int i=0;i<ma[tem.num].size();i++)
		{
			nex.num=ma[tem.num][i];
			if(city[nex.num]>=a&&city[nex.num]<=b)
				nex.money=tem.money+city[nex.num];
			else nex.money=tem.money;
			if(nex.num==be)return nex.money;
			if(vis[nex.num]==0)
				way.push(nex);
		}
	}
}
int main()
{
    int quer;
    //freopen("input.txt","r",stdin);
    //freopen("ans.txt","w",stdout);
	scanf("%d%d",&n,&quer);
    while(~scanf("%d%d",&n,&quer))
    {
        for(int i=1;i<=n;i++)
            scanf("%I64d",&city[i]);
        int a,b;
        for(int i=1;i<=n;i++)
            ma[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            ma[a].push_back(b);
            ma[b].push_back(a);
        }
        int be,en;
        for(int i=0;i<quer;i++)
        {
        	scanf("%d%d%d%d",&be,&en,&a,&b);
        	if(i==0)printf("%I64d",maxmony(be,en,a,b));//cout<<maxmony(be,en,a,b);
			else printf(" %I64d",maxmony(be,en,a,b));//cout<<" "<<maxmony(be,en,a,b);
		}
		printf("\n");//cout<<endl;
    //}
}
