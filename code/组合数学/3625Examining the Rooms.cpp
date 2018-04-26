#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdio>
#include<stdio.h>
#include<string.h>
using namespace std;
#define ll long long
ll stir[25][25];
ll fac[25];
void init()
{
    int i,j;
    fac[1]=1;
    for(i=2;i<25;i++)
        fac[i]=i*fac[i-1];
    memset(stir,0,sizeof(stir));
    stir[0][0]=0;
    stir[1][1]=1;
    for(i=2;i<25;i++)
        for(j=1;j<=i;j++)
           stir[i][j]=stir[i-1][j-1]+(i-1)*stir[i-1][j];
}
int main()
{
    int t;
    init();
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        ll ans=0;
        for(int i=1;i<=k;i++)
            ans+=stir[n][i]-stir[n-1][i-1];
    //    cout<<ans<<endl;
     //   cout<<fac[n]<<endl;
        double t=double(((double)ans)/((double)fac[n]));
        printf("%.4lf\n",t);
    }
}
