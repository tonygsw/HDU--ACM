#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<cstdio>
#include<string.h>
#include<stdio.h>
using namespace std;
#define ll unsigned int
class node{
    public:
        int num;
        char zf;
};
node no[1005];int sum=0;int n;
int dp[1000005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&sum);
        for(int i=0;i<n;i++)
            scanf("%d",&no[i].num);
        for(int i=0;i<n;i++)
            scanf("%c",&no[i].zf);
        if(sum>=0)
        {
            dp[0]=0;
            for(int i=1;i<=sum;i++)
                dp[i]=-0x3f3f3f3f;
            for(int i=0;i<n;i++)
            {
                for(int j=sum;j>=0;j--)
            }
        }
    }
}
