#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstdio>
#include<math.h>
#include<string>
#include<string.h>
#include<cmath>
#include<map>
using namespace std;
#define ll long long
int s[200];int k;int h[105];
int sg[10005];int vis[10005];
void findsg()
{
    int i,j;
    sg[0]=0;
    for(i=1;i<=10000;i++)
    {
        memset(vis,0,sizeof(vis));
        for(j=0;j<k;j++)
        {
            if(i>=s[j])
            vis[sg[i-s[j]]]=1;
        }
        for(j=0;j<=10000;j++)
            if(!vis[j])
            {
                sg[i]=j;
                break;
            }
    }
}
int main()
{
  //  freopen("ww.txt","w",stdout);
    while(~scanf("%d",&k))//cin>>k&&k!=0)
    {
        if(k==0)break;
        int m,l;
        for(int i=0;i<k;i++)
            scanf("%d",&s[i]);//cin>>s[i];
        findsg();
/*
        for(int i=0;i<100;i++)
            cout<<sg[i]<<" ";
        cout<<endl;
*/
        scanf("%d",&m);//cin>>m;
        //string ans;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&l);//cin>>l;
            int flag=0;
            for(int j=0;j<l;j++)
            {
                scanf("%d",&h[j]);//cin>>h[j];
                flag=flag^sg[h[j]];
            }
            if(flag)
                 printf("W");//cout<<"W";
            else
                printf("L");// cout<<"L";//ans+="L";
        }
            printf("\n"); //cout<<endl;
    }
    return 0;
}
