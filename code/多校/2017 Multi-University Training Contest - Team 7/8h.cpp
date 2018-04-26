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
    freopen("ans.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        ll n,m;
        memset(num,0,sizeof(num));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        for(int i=1;i<=m;i++)
        {
            for(int j=2;j<=n;j++)
                num[j]=(num[j]^num[j-1]);
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
