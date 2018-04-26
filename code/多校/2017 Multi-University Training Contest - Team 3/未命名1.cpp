#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<stdio.h>
#include<cstdio> //freopen("2.txt","w",stdout);
#define ll long long
using namespace std;
int main()
{
	int falg=0;
	freopen("2.txt","w",stdout);
	for(int i=0;i<=10;i++)
	{
		for(int j=0;j<=10;j++)
		{
			for(int k=0;k<=10;k++)
			{
				if((i^j)<(j^k))
				{
					cout<<i<<" "<<j<<" "<<k<<"  "<<(i^j)<<" "<<(j^k)<<"     ";
				//	 falg++;
				//	 if(falg%10==0)cout<<endl; 
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
