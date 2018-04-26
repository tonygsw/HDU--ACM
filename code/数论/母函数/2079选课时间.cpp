/*
    date:2017.8.29
    author:gsw
    problem:hdu 2079
    solve:Ä¸º¯Êý
*/
#include<iostream>
#include<math.h>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<cstdio>
#include<string.h>
using namespace std;
int a[45],b[45];
int v[40],num[40];int t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<k;i++)
            scanf("%d%d",&v[i],&num[i]);
        memset(a,0,sizeof(a));a[0]=1;
        for(int i=0;i<k;i++)
        {
            memset(b,0,sizeof(b));
            for(int j=0;j<=num[i]&&j*v[i]<=n;j++)
                for(int k=0;k+j*v[i]<=n;k++)
                    b[k+j*v[i]]+=a[k];
            memcpy(a,b,sizeof(b));
        }
        cout<<a[n]<<endl;
    }
}
