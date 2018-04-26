/*
    date:2017.8.30
    author:gsw
    problem:hdu 2082
    solve:Ä¸º¯Êý
*/
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<math.h>
#include<cmath>
using namespace std;
#define ll long long
int v[30];int num[30];ll a[100];ll b[100];
void init()
{
    for(int i=1;i<=26;i++)
        v[i]=i;
}
int main()
{
    init();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=26;i++)
            scanf("%d",&num[i]);
        memset(a,0,sizeof(a));
        a[0]=1;
        for(int i=1;i<=26;i++)
        {
            memset(b,0,sizeof(b));
            for(int j=0;j<=num[i]&&j*v[i]<=50;j++)
                for(int k=0;k+j*v[i]<=50;k++)
                    b[k+j*v[i]]+=a[k];
            memcpy(a,b,sizeof(b));
        }
        ll ans=0;
        for(int i=1;i<=50;i++)
            ans+=a[i];
        cout<<ans<<endl;
    }
}
