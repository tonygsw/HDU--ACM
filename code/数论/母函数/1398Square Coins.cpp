/*
    date:2017.8.29
    author:gsw
    problem:hdu 1398
    solve:Ä¸º¯Êý
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<cstdio>
using namespace std;
#define ll long long
int v[20];
int a[305],b[305];
int main()
{
    for(int i=0;i<17;i++)
        v[i]=(i+1)*(i+1);
    int n;
    while(cin>>n&&n!=0)
    {
        memset(a,0,sizeof(a));
        a[0]=1;
        for(int i=0;i<17;i++)
        {
            memset(b,0,sizeof(b));
            for(int j=0;j*v[i]<=n;j++)
                for(int k=0;k+j*v[i]<=n;k++)
                    b[k+j*v[i]]+=a[k];
            memcpy(a,b,sizeof(b));
        }
        cout<<a[n]<<endl;
    }
}
