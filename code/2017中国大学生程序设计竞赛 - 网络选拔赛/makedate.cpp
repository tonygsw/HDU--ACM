#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
#define ran(m) rand()%m
int num[1000];
int main()
{
	srand((unsigned)time(NULL));
    freopen("input.txt","w",stdout);
    int t=rand()%10+1;
    cout<<t<<endl;
    while(t--)
    {
	    int n=rand()%10+2;
	    cout<<n<<endl;
	    for(int i=n-1;i>0;i--)
	    {
	    	for(int j=1;j<=i;j++)
	    	{
	    		cout<<rand()%2<<" "; 
			}
			cout<<endl;
	    }
	}

}
