#include<iostream>
using namespace std;
#define ll long long
ll bi[105];
ll n,m,a,b,c;
unsigned x,y,z;
unsigned rng61()
{
	unsigned t;
	x^=x<<16;
	x^=x>>5;
	x^=x<<1;
	t=x;
	x=y;
	y=z;
	z=t^x^y;
	return z;
}
int main()
{
	cin>>n>>m>>a>>b>>c;
	for(int i=1;i<=m;i++)
		cin>>bi[i];
	x=a,y=b,z=c;
	for(int i=1;i<=n;i++)
		cout<<rng61()<<endl;
}
