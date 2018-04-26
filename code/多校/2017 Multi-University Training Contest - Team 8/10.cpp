#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<cstdio>
#include<string.h>
#include<stdio.h>
using namespace std;
#define ll long long
ll jiec[2005];ll mod=1e9+7;
ll zuhe[2005][2005];
ll sum[2005][2005];
void init()
{
    jiec[0]=1;
    memset(zuhe,0,sizeof(zuhe));
    for(int i=1;i<=2000;i++)
        zuhe[i][1]=i,zuhe[i][0]=1,jiec[i]=jiec[i-1]*i%mod;
    for(int i=2;i<=2000;i++)
    {
    	for(int j=1;j<=i;j++)
    		zuhe[i][j]=(zuhe[i-1][j]+zuhe[i-1][j-1])%mod;
	}
    for(ll i=0;i<=2000;i++)
    {
        for(ll j=0;j<=2000;j++)
        {
            if(j==0||j>i)sum[i][j]=0;
            else if(i==j||j==1)sum[i][j]=1;
            else sum[i][j]=(sum[i-1][j-1]+j*sum[i-1][j])%mod;
        }
    }
}
int main()
{
    ll t,n,m;
    init();
    freopen("input.txt","r",stdin);
    freopen("2.txt","w",stdout); 
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d%I64d",&n,&m);//cin>>n>>m;
        ll ans=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i+j>m)break;
                ll tem1=jiec[i]*sum[n][i]%mod;
                ll tem2=jiec[j]*sum[n][j]%mod;
                ans=(ans+(zuhe[m][i]*tem1%mod)*(zuhe[m-i][j]*tem2%mod)%mod)%mod;
            }
        }
        printf("%I64d\n",ans);//cout<<ans<<endl;
    }
}
