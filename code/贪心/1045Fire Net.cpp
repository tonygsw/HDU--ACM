/*----------2017.4.12--------*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
char Map[5][5];	int Max=0;
bool build(int i,int j)
{
	for(int k=j;k>=0;k--)
	{
		if(Map[i][k]=='0')return false;
		if(Map[i][k]=='X')break;
	}
	for(int k=i;k>=0;k--)
	{
		if(Map[k][j]=='0')return false;
		if(Map[k][j]=='X')break;
	}
	return true;
}
void bfs(int x,int num)
{
	if(x==n*n)
	{
		if(Max<num)Max=num;
		return;
	}
	int i=x/n;	int j=x%n;
	if(Map[i][j]=='.'&&build(i,j))
	{
		Map[i][j]='0';
		bfs(x+1,num+1);
		Map[i][j]='.';
	}
	bfs(x+1,num);
}
int main()
{
	while(cin>>n&&n!=0)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>Map[i][j];
		Max=0;
		bfs(0,0);
		cout<<Max<<endl;
	}
}
