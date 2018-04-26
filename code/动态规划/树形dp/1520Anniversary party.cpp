#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdio.h>
#define ll long long
using namespace std;
int n;int dp[6005][3];
int fa[6005],vis[6005];
void init()
{
    memset(dp,0,sizeof(dp));
    memset(fa,0,sizeof(fa));
    memset(vis,0,sizeof(vis));
}
void dfs(int we)
{
    vis[we]=1;
    for(int i=1;i<=n;i++)
    {
        if(fa[i]==we&&!vis[i])
        {
            dfs(i);
            dp[we][0]+=max(dp[i][0],dp[i][1]);
            dp[we][1]+=dp[i][0];
        }
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        init();
        for(int i=1;i<=n;i++)
            scanf("%d",&dp[i][1]);
        int a,b;
        while(scanf("%d%d",&a,&b))
        {
            if(a==0&&b==0)break;
            fa[a]=b;
        }
        int father=1;
        while(fa[father])father=fa[father];
        dfs(father);
        int  ans=0;
        ans=max(dp[father][1],dp[father][0]);
        printf("%d\n",ans);
    }
}
