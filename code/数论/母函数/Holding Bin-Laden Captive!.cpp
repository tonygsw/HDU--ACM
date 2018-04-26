/*
    date:2017.8.29
    author:gsw
    problem:hdu 1171
    solve:Ä¸º¯Êý
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<cstdio>
using namespace std;
int n[3],a[9000],b[9000];
int v[3]={1,2,5};int last,last2;
int main()
{
    while(cin>>n[0]>>n[1]>>n[2]&&(n[0]!=0||n[1]!=0||n[2]!=0))
    {
        memset(a,0,sizeof(a));last=0;a[0]=1;
        for(int i=0;i<=2;i++)
        {
            last2=last+n[i]*v[i];
            memset(b,0,sizeof(int)*(last2+1));
            for(int j=0;j<=n[i];j++)
                for(int k=0;k<=last;k++)
                    b[k+j*v[i]]+=a[k];
            memcpy(a,b,sizeof(int)*(last2+1));
            last=last2;
        }int i=0;
        for(;i<=last;i++)
            if(a[i]==0)break;
        cout<<i<<endl;
    }
}
