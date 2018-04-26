#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,u,d;
int main()
{
	while(cin>>n>>u>>d&&n!=0)
	{
		int i=1;
		while(n>0)
		{
			if(i%2==0)n=n+d;
			else n=n-u;
			i++;
		}
		cout<<i-1<<endl;
	}
}
