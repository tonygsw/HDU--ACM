#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#define maxn 1010
#define maxm 20010

using namespace std;

struct node
{
    int to,next;
}edge[maxm],edge2[maxm];
int head[maxn],cnt,n;
int clk,top,s[maxn],scc,dfn[maxn],low[maxn],belong[maxn];
bool instack[maxn],vis[maxn];
int head2[maxn],cnt2,in[maxn];

typedef pair<int,int> PII;
vector<PII> xx;
queue<int> q;

void add(int x,int y)
{
    edge[cnt].to = y;
    edge[cnt].next = head[x];
    head[x] = cnt++;
}

void add2(int x,int y)
{
    edge2[cnt2].to = y;
    edge2[cnt2].next = head2[x];
    head2[x] = cnt2++;
}

void dfs(int x)
{
    dfn[x] = low[x] = clk++;
    s[top++] = x;
    instack[x] = true;
    for(int i=head[x];i!=-1;i = edge[i].next)
    {
        int u = edge[i].to;
        if(dfn[u]==-1)
        {
            dfs(u);
            low[x] = min(low[u],low[x]);
        }
        else if(instack[u])
        {
            low[x] = min(low[x],dfn[u]);
        }
    }
    if(low[x]==dfn[x])
    {
        int u;
        scc++;
        do
        {
            u = s[--top];
            instack[u]=false;
            belong[u] = scc;
        }while(u!=x);
    }
}

void tarjan()
{
    memset(dfn,-1,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    memset(belong,0,sizeof(belong));
    clk = top = scc = 0;
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==-1)
            dfs(i);
    }
}

bool topo()
{
    memset(vis,0,sizeof(vis));
    int c = 0;
    while(!q.empty())
        q.pop();
    for(int i=1;i<=scc;i++)
    {
        if(!in[i])
        {
            c++;
            q.push(i);
        }
    }
    if(c>1) return false;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        c = 0;
        for(int i=head2[u];i!=-1;i=edge2[i].next)
        {
            int v = edge2[i].to;
            in[v]--;
            if(!in[v])
            {
                q.push(v);
                c++;
            }
        }
        if(c>1)
            return false;
    }
    return true;
}

int main()
{
    int m,a,b,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));
        memset(in,0,sizeof(in));
        xx.clear();
        cnt = 0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            xx.push_back(make_pair(a,b));
        }
        tarjan();
        memset(head2,-1,sizeof(head2));
        cnt2 = 0;
        for(int i=0;i<xx.size();i++)
        {
            int u = xx[i].first,v = xx[i].second;
            if(belong[u]!=belong[v])
            {
                add2(belong[u],belong[v]);
                in[belong[v]]++;
            }
        }
        if(topo()) printf("I love you my love and our love save us!\n");
        else printf("Light my fire!\n");
    }
    return 0;
}
