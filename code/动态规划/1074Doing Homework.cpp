#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
class node{
	public:
		char name[101];
		int d; int c;
};
class kode{
	public:
		int time;
		int score;
		int pr;int now;
};
node a[20];kode d[1<<15];
#define inf 1<<30;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i].name>>a[i].d>>a[i].c;
		int end=1<<n;
		for(int s=1;s<end;s++)
		{
			d[s].score=inf;
			for(int i=n-1;i>=0;i--)
			{
				int tem=1<<i;
				if(s&tem)
				{
					int past=s-tem;
					int st=d[past].time+a[i].c-a[i].d;
					if(st<0)st=0;
					if(st+d[past].score<d[s].score)
					{
						d[s].score=st+d[past].score;
						d[s].pr=past;
						d[s].time=d[past].time+a[i].c;
						d[s].now=i;
					}
				}
			}
		}
		int tem=end-1;
		cout<<d[tem].score<<endl;
		stack<int> ss;
		while(tem)
		{
			ss.push(d[tem].now);
			tem=d[tem].pr;
		} 
		while(!ss.empty())
		{
			cout<<a[ss.top()].name<<endl;
			ss.pop();
		}
	}
}
