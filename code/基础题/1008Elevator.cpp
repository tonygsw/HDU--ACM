#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int tem,fl=0;
	while(cin>>n&&n!=0)
	{
		fl=0;int ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&tem);
			int c=tem-fl;
			if(c>0)ans=ans+c*6+5;
			else if(c==0)ans=ans+5;
			else ans=ans+abs(c)*4+5;
			fl=tem;
		}
		cout<<ans<<endl;
	}
}
