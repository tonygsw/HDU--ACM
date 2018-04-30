/*
    author:gsw
    data:2018.04.30
    link:http://acm.hdu.edu.cn/showproblem.php?pid=2586
    account:tonysave
*/
#define ll long long
#define IO ios::sync_with_stdio(false);
#define maxn 40005

#include<vector>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t,n,m;
class Node{
    public:
        int nex,len;
};
vector<Node> tree[maxn];
int dis[maxn];int deep[maxn];
int fa[maxn];

void init()
{
    for(int i=0;i<n;i++)
        tree[i].clear();
    memset(dis,0,sizeof(dis));
    memset(deep,0,sizeof(deep));
    memset(fa,0,sizeof(fa));
}
Node ne;
void dfs(int num,int faa)
{
    for(int i=0;i<tree[num].size();i++)
    {
        ne=tree[num][i];
        if(ne.nex!=faa)
        {
            fa[ne.nex]=num;
            deep[ne.nex]=deep[num]+1;
            dis[ne.nex]=dis[num]+ne.len;
            dfs(ne.nex,num);
        }
    }
}
int lca(int a,int b)
{
    if(deep[a]>deep[b])
        swap(a,b);
    while(deep[b]>deep[a])
        b=fa[b];
    while(a!=b)
        a=fa[a],b=fa[b];
    return a;
}

int main()
{
    int a,b,c;Node tem;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            tem.nex=b;tem.len=c;
            tree[a].push_back(tem);
            tem.nex=a;
            tree[b].push_back(tem);
        }
        dfs(1,0);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            int ans=lca(a,b);
            ans=dis[a]+dis[b]-2*dis[ans];
            printf("%d\n",ans);
        }
    }
}
