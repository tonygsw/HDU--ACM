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
class Node
{
    public:
        int a[2];
        ll v;
};
Node node[32*maxn];int cnt=0;
void init()
{
    cnt=0;
    memset(node,0,sizeof(node));
}
void update(ll num)
{
    int p=0;
    for(int i=32;i>=0;i--)
    {
        int c=((num>>i)&1);
        if(!node[p].a[c])
            node[p].a[c]=++cnt;
        p=node[p].a[c];
    }
    node[p].v=num;
}
ll query(ll num)
{
    int p=0;
    for(int i=32;i>=0;i--)
    {
        int c=((num>>i)&1);
        if(node[p].a[(c^1)])p=node[p].a[(c^1)];
        else p=node[p].a[c];
    }
    return node[p].v;
}
int main()
{
    int ca,n,m;ll tem;
    while(~scanf("%d",&ca))
    {
        for(int i=1;i<=ca;i++)
        {
        	init();
            scanf("%d%d",&n,&m);
            for(int j=1;j<=n;j++)
            {
                scanf("%lld",&tem);
                update(tem);
            }
            printf("Case #%d:\n",i);
            for(int j=1;j<=m;j++)
            {
                scanf("%lld",&tem);
                printf("%lld\n",query(tem));
            }
        }
    }
}
