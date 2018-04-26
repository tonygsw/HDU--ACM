#include<iostream>
#include<map>
#include<bits/stdc++.h>
using namespace std;
map <int,int> a;
int main()
{
	int n;
	while(cin>>n)
	{
		a.clear();
		int tem,ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&tem);
			a[tem]++;
			if(a[tem]>=(n+1)/2)
			{
				ans=tem;
			}
		}
		cout<<ans<<endl;
	}
}
