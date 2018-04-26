#include<iostream>
#include<math.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll tema,temb,a,b;
void cg() 
{
	if(a>b)
	{
		temb=a;
		tema=b;
	}
	else
	{
		tema=a;
		temb=b;
	}
}
int main()
{
	while(cin>>a>>b)
	{
		cg();
		ll minx=(temb-tema)*1.61803398875;
		if(minx==tema)
			cout<<"0"<<endl;
		else
			cout<<"1"<<endl; 
	}
}
