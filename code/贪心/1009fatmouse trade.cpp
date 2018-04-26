#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<iostream> 
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
struct node{
		double j;
		double f;
		double bl;
};
node a[1005]; 
bool camp(node a,node b)
{
	return a.bl>b.bl;
}
int main()
{
	double m; 
	int n;
	while(cin>>m>>n)
	{
		if(m==-1&&n==-1)
		break;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a[i].j,&a[i].f);
			a[i].bl=(double)a[i].j/a[i].f;
		}
		sort(a,a+n,camp);
	//	for(int i=0;i<n;i++)cout<<a[i].j<<" "<<a[i].f<<" "<<a[i].bl<<endl;
		double sum=0;
		for(int i=0;i<n;i++)
		{
			if(m>=a[i].f)
			{
				m=m-a[i].f;
				sum=sum+a[i].j;
			}
			else
			{
				sum=sum+m*(a[i].j/a[i].f);
				break;
			}
		}
		printf("%.3lf\n",sum); //cout<<fixed<<setprecision(3)<<sum<<endl;
	}
}
