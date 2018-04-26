#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<cstdio>
#include<vector>
using namespace std;
#define maxn 10005
#define ll long long
vector<int> ma[maxn];
int Stack[maxn];int dfn[maxn];int low[maxn];
int flag[maxn];int top=-1;int cont=1;
int n,m;int num=0;int belong[maxn];
void init()
{
    //memset(Stack,0,sizeof(Stack));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(belong,0,sizeof(belong));
    memset(flag,0,sizeof(flag));
    top=-1;cont=1;num=0;
    for(int i=0;i<=n;i++)
        ma[i].clear();
}
void tarjan(int u)
{
    dfn[u]=low[u]=cont++;
    flag[u]=1;Stack[++top]=u;
    for(int i=0;i<ma[u].size();i++)
    {
        int v=ma[u][i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(flag[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        num++;int x;
        do
        {
            x=Stack[top--];
            flag[x]=0;
            belong[x]=num;
        }while(x!=u);
    }
    return;
}
int main()
{
	//freopen("input.txt","r",stdin);
//	freopen("b.txt","w",stdout); 
    while(cin>>n>>m,n+m)
    {
        int a,b;
        init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            ma[a].push_back(b);
        }
        for(int i=1;i<=n;i++)
            if(!dfn[i])
            	tarjan(i);
        if(num==1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
