#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<cstdio>
#include<string.h>
#include<stdio.h>
using namespace std;
#define ll unsigned int
ll num[200005];
int main()
{
    int t;
    freopen("input.txt","r",stdin);
    freopen("ss.txt","w",stdout);
    scanf("%d",&t);

    while(t--)
    {
        ll n,m;
        memset(num,0,sizeof(num));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        int mod=8;int j=1;
        int len=0;
        if(m%8==0)len=m/8;
        else len=m/8+1;
        for(int i=1;i<=len;i++)
        {
            for(int j=1;j<=m%(i*8);j++)
            {
                for(int k=8*i-7;k<=(8*i+1)&&k<=n;k++)
                {
                    num[k]=num[k]^num[k-1];
                }
            }
        }
        cout<<num[1];
        for(int i=2;i<=n;i++)
        {
             if(i%5==0)cout<<endl;
              cout<<" "<<num[i];
        }

        cout<<endl;

    }
}
