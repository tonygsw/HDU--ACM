#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
#define ll long long
class point{
	public:
		ll num;
		ll numi;
};
point p[100005];
bool camp(point a,point b)
{
	return a.num>b.num;
}
int ans[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int num;
		scanf("%d",&num);
		for(int i=1;i<=num;i++)
		{
			scanf("%I64d",&p[i].num);
			p[i].numi=i;
		}
		sort(p+1,p+num+1,camp);
		///for(int i=1;i<=num;i++)
		//	cout<<"---="<<p[i].numi<<" "<<p[i].num<<endl;
		for(int i=2;i<=num;i++)
		{
			for(int j=1;j<=num;j++)
			{
				if(p[j].numi%i!=0)
				{
					ans[i]=p[j].num;
					break;
				}
			}
		}
		cout<<ans[2];
		for(int i=3;i<=num;i++)
			cout<<" "<<ans[i];
		cout<<endl; 
	}
}

