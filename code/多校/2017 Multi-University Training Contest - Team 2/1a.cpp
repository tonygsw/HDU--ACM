#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<stdio.h>
#include<cstdio> //freopen("2.txt","w",stdout);
#define ll long long
using namespace std;
string ansx,ansy;
int main()
{
	int t,n,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&x,&y);
		cin>>ansx>>ansy;
		ll same=0,diff=0;
		for(int i=0;i<n;i++)
		{
			if(ansx[i]!=ansy[i])diff++;
			else same++;
		}
	//	cout<<same<<" "<<diff<<endl;
		ll zuo=0,you=0;
		int flag=0;
		for(int i=0;i<=same;i++)
		{
			if(y-i>=0&&(y-i)<=diff)
			{	
				zuo=i;you=2*i+diff-y;
			//	cout<<"zuo="<<zuo<<"  you="<<you<<endl; 
				if(x>=zuo&&x<=you)
					flag=1;
			}
		}
		if(flag==1)cout<<"Not lying"<<endl;
		else cout<<"Lying"<<endl;
	}
	return 0;
}
