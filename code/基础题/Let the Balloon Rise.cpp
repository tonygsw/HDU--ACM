#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;
map<string,int> c;
int main()
{
	string tem,ans;
	int num;
	while(cin>>num&&num!=0)
	{
		int max=0;
		for(int i=0;i<num;i++)
		{
			cin>>tem;
			c[tem]++;
			if(c[tem]>max)
			{
				ans=tem;
				max=c[tem];
			}
		}
		cout<<ans<<endl;
	}
}
