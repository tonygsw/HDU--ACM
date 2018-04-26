#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<math.h>
using namespace std;
int n;int v[55];int num[55];
int a[250010],b[250010];
int main()
{
    while(scanf("%d",&n)&&n!=-1)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&v[i],&num[i]);
        a[0]=1;int last,last2;
        last=0;
        for(int i=0;i<n;i++)
        {
            last2=last+v[i]*num[i];
            memset(b,0,sizeof(int)*(last2+1));
            for(int j=0;j<=num[i];j++)
                for(int k=0;k<=last;k++)
                    b[k+j*v[i]]+=a[k];
            memcpy(a,b,sizeof(int)*(last2+1));
            last=last2;
        }
        int i;
        for(i=last/2;i>=0&&a[i]==0;i--);
        cout<<last-i<<" "<<i<<endl;
    }
}
