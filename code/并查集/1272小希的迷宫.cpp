/*
    problem:hdu 1272
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
#define maxn 100005
int pre[maxn];int flag=0;
bool mark[maxn];
void init()
{
    for(int i=1;i<maxn;i++)
        pre[i]=i;
    memset(mark,0,sizeof(mark));
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
void combine(int x,int y)
{
    x=findd(x);y=findd(y);
    if(x!=y)
        pre[x]=y;
    else
        flag=1;
}
int main()
{
    int x,y;
    while(scanf("%d%d",&x,&y)&&(x!=-1||y!=-1))
    {
        if(x==0&&y==0)
        {
            printf("Yes\n");
            continue;
        }
        init();
        flag=0;
        combine(x,y);mark[x]=1;mark[y]=1;
        while(scanf("%d%d",&x,&y)&&(x!=0||y!=0))
        {
            combine(x,y);mark[x]=1;mark[y]=1;
        }
        int flag1=0;
        for(int i=1;i<maxn;i++)
        {
            if(mark[i])
            {
                if(findd(i)==i)
                    flag1++;
            }
        }
        //cout<<flag1<<endl;
        if(flag==1||flag1!=1)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}
