/*
    author:tony
    data:2018.9.20
    link:http://acm.hdu.edu.cn/showproblem.php?pid=1176
*/
#define ll long long
#define maxn 100005

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;

int n,maxt;
int dp[maxn][15];
void init()
{
    maxt=0;
    memset(dp,0,sizeof(dp));
}
void ans()
{
    for(int i=maxt;i>0;i--)
    {
        for(int j=1;j<=11;j++)
        {
            dp[i-1][j]+=max(max(dp[i][j],dp[i][j+1]),dp[i][j-1]);
        }
    }
    printf("%d\n",dp[0][6]);
}
int main()
{
    int a,b;
    while(scanf("%d",&n)&&n)
    {
        init();
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            dp[b][a+1]++;
            maxt=max(maxt,b);
        }
        ans();
    }
}
