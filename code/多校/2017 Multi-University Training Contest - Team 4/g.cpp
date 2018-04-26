#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>
#include<cstdio>
#include<math.h>
#include<stdio.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	ll n,num,flag,flag1;
	scanf("%d",&t);
	while(t--)
	{
		flag=0;flag1=0;
		scanf("%I64d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%I64d",&num);
			if(num%2==0)flag++;
			else flag1++;
		}
		if(flag>=flag1)cout<<2<<" "<<0<<endl;
		else cout<<2<<" "<<1<<endl;
	}
}
