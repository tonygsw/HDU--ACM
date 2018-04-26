/*
    problem:hdu 1232
    date:2017.9.3
    author:gsw_甘世维
    solve:并查集
*/

#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;
#define ll long long
#define maxn 1005
int pre[maxn];int n,m;
void init()
{
    for(int i=1;i<maxn;i++)
        pre[i]=i;
}
int findd(int x)
{
    int r=x;
    while(r!=pre[r])
        r=pre[r];
    int i=x,j;
    while(pre[i]!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void combine(int a,int b)
{
    a=findd(a);b=findd(b);
    if(a!=b)pre[a]=b;
}
int main()
{
    int x,y;
    while(scanf("%d",&n)&&n!=0)
    {
        init();
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            combine(x,y);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(findd(i)==i)ans++;
        cout<<ans-1<<endl;
    }
}
