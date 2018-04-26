#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
#define ll long long
int main()
{
	int t,ca=1;
	cin>>t;
	while(t--)
	{
		ll n,x,y,c1=0,c2=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x>>y;
			while(x>1&&y>1)
			{
				x>>=1;y>>=1;
				c1++;c2++;
			}
			if(x==1)c2+=y-1;
			else c1+=x-1; 
		}
		cout<<"Case "<<ca++;
		if(c1>c2)cout<<": Alice";
		else cout<<": Bob";
		cout<<endl;
	}
}
