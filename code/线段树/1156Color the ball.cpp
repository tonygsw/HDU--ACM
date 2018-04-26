#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ball[100005];
int main()
{
	int n,a,b;
	while(scanf("%d",&n)&&n!=0)
	{
		memset(ball,0,sizeof(ball));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			ball[a]++;
			ball[b+1]--;
		}
		for(int i=1;i<=n;i++)
		{
			ball[i]=ball[i]+ball[i-1];
		}
		printf("%d",ball[1]);
		for(int i=2;i<=n;i++)
			printf(" %d",ball[i]);
		printf("\n");
	}
}
