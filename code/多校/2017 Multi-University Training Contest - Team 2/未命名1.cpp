#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<cstdio>
using namespace std;
#define ll long long
string a0[100000];
string b1[100000];
void init()
{
	a0[1]="0";
	for(int i=2;i<1000;i++)
	{
			 a0[i]=a0[i-1]+"0";
		//	 cout<<a0[i]<<" "<<endl;
	} 
}
void init1()
{
	b1[1]="1";
	for(int i=2;i<1000;i++)
	{
		b1[i]=b1[i-1]+"1";
	//	cout<<b1[i]<<"  "<<endl;
	}
}
int minn(int a,int b)
{
	if(a>b)return b;
	else return a;
}
int main()
{
	double a,b,c,d;
	init();
	init1();
	while(cin>>a>>b>>c>>d)
	{
		string ans;
		while(a!=1||d!=1)
		{
			if(a>=b&&c>=d)
			{
				while(a>=b&&c>=d)
				{
					int tem=minn(a/b,c/d);
					a=a-(tem*b);
					c=c-(tem*d);
					ans=ans+a0[tem];
			//		cout<<"a="<<a<<" b="<<b<<" c="<<c<<" d="<<d<<ans<<endl;
				}
			}
			else
			{
				while(b>=a&&d>=c)
				{
					int tem=minn(b/a,d/c);
					b=b-(tem*a);
					d=d-(tem*c);
					ans=ans+b1[tem];
			//		cout<<"a="<<a<<" b="<<b<<" c="<<c<<" d="<<d<<" as="<<ans<<endl;
				}
			}
		}
		if(b!=0)ans+="1";
		if(c!=0)ans+="0"; 
		reverse(ans.begin(),ans.end());
		cout<<ans<<endl;
	}

	return 0;
}
