#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cstdio>
using namespace std;
#define ll long long
int maxx(int a,int b)
{
	if(a>b)return a;
	else return b;
}
int minn(int a,int b)
{
	if(a>b)return b;
	else return a;
}
int min3(int a,int b,int c)
{
	int tem=minn(a,b);
	int tem2=min(b,c);
	return minn(tem,tem2);
}
int main()
{
	int t,num;
	int a,b,c,ab,ac,bc,A,B,C,AB,AC,ABC,BC;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&num);
		int ans=0;
		for(int i=0;i<num;i++)
		{
			cin>>A>>B>>C>>AB>>BC>>AC>>ABC;
			a=A-AB-AC+ABC;
			b=B-AB-BC+ABC;
			c=C-AC-BC+ABC;
			ab=AB-ABC;
			ac=AC-ABC;
			bc=BC-ABC;
			if(a<0||b<0||c<0||ab<0||ac<0||bc<0)continue; 
			if(ABC>min3(A,B,C))continue;
			if(AB>minn(A,B))continue;
			if(BC>minn(B,C))continue;
			if(AC>minn(A,C))continue;
			if(ABC>min3(AB,AC,BC))continue;
			ans=maxx(ans,A+B+C+ABC-AB-AC-BC);
		}
		cout<<ans<<endl;
	}
}

