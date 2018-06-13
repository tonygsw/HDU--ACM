/*
    data:2018.04.26
    author:gswycf
    link:http://acm.hdu.edu.cn/showproblem.php?pid=4825
    accout:tonysave
*/
#define ll long long
#define IO ios::sync_with_stdio(false);
#define maxn 100005

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
using namespace std;

class Node{
    public:
        int cnt,ls,rs;
};
int n,m,cnt,aa,bb;
Node tr[32*maxn];
int weight[maxn];int root[maxn];int deep[maxn],f[maxn][31];
vector<int>  g[maxn];

inline void init()
{
    memset(tr,0,sizeof(tr));
    memset(weight,0,sizeof(weight));
    memset(root,0,sizeof(root));
    memset(deep,0,sizeof(deep));
    memset(f,0,sizeof(f));
	cnt=0;
    for(int i=0;i<=n;i++)
        g[i].clear();
}
int in(int pre,int x,int deep)
{
    int num=++cnt;
    tr[num]=tr[pre];
    tr[num].cnt=tr[pre].cnt+1;
    if(deep<0)return num;
    if(!((x>>deep)&1))tr[num].ls=in(tr[pre].ls,x,deep-1);
    else tr[num].rs=in(tr[pre].rs,x,deep-1);
    return num;
}
int query(int l,int r,int x,int deep)
{
    if(deep<0)return 0;
    if(!((x>>deep)&1))
    {
        if(tr[tr[r].rs].cnt>tr[tr[l].rs].cnt)return (1<<deep)+query(tr[l].rs,tr[r].rs,x,deep-1);
        else return query(tr[l].ls,tr[r].ls,x,deep-1);
    }
    else
    {
        if(tr[tr[r].ls].cnt>tr[tr[l].ls].cnt)return (1<<deep)+query(tr[l].ls,tr[r].ls,x,deep-1);
        else return query(tr[l].rs,tr[r].rs,x,deep-1);
    }
}
void bfs(int node,int fa)
{
    root[node]=in(root[fa],weight[node],16);
    f[node][0]=fa;deep[node]=deep[fa]+1;
	for(int i=0;i<g[node].size();i++)
    {
        if(g[node][i]!=fa)
            bfs(g[node][i],node);
    }
}
inline void init2()
{
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
}
int lca(int a,int b,int c)
{
    if(deep[a]>deep[b])swap(a,b);
    int d=deep[b]-deep[a];
	for(int i=0;i<30;i++)
    	if((1<<i)&d)b=f[b][i];
    if(a==b)return a;
    for(int i=29;i>=0;i--)
    {
    	if(f[a][i]!=f[b][i])
    		a=f[a][i],b=f[b][i];
	}
	b=f[b][0];
	return b;
}

int main()
{
	int a,b,c;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=1;i<=n;i++)scanf("%d",&weight[i]);
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bfs(1,0);init2();
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            int k=lca(a,b,c);
            printf("%d\n",max(query(root[k-1],root[a],c,16),
							  query(root[k-1],root[b],c,16)));
        }
    }
}
/*
3 4
1 2 3
1 2
1 3
2 2 2
2 3 1
1 3 1
3 2 1
这题wa了，找了半天没写出来。 
*/

