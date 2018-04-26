#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e9;
int main()
{
    freopen("input.txt","w",stdout);
    srand((unsigned)time(NULL));
    int t=rand()%5+1;
    cout<<t<<endl;
    while(t--)
    {
    	int n=rand()%10+1;
    	cout<<n<<endl;
    	for(int i=0;i<n;)
    	{
    		int x=rand()%10;int y=rand()%10+1;
    		if(x<y)
    		{
    			i++;
    			cout<<x<<" "<<y<<endl;
			}
		}
	}
}
int main()
{
    {
        cout<<<endl;
    }
}
