#include<iostream>
using namespace std;
#define ll long long
int main()
{
	ll ans=1;
	int cas=1;
	freopen("1.out","w",stdout);
	for(int i=0;i<1000000007;i=i+10000000)
	{
		for(int j=i+1;j<=i+10000000;j++)
			ans=ans*j%1000000007;
		cout<<ans<<",";
		if((cas++)%5==0)cout<<endl;
	}
	
}
