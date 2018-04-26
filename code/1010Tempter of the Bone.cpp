#include<iostream>
#include<queue>
#include<string.h>
//#include<bits/stdc++.h>
using namespace std;
int maze[10][10];int n,m,timee;
int flag=0;
int mark[10][10];
int to[4][2]={1,0,-1,0,0,1,0,-1};
class no{
	public:
		int x,y;
		int ti; 
};
no beg,tem,nex,endd;
bool judge(no a)
{
	if(mark[a.x][a.y]==1)return false;
	if(maze[a.x][a.y]==0)return false;
	if(a.x<0||a.x>=n||a.y<0||a.y>=m)return false;
	return true;
}
void dfs()
{
	queue<no> way;
	way.push(beg);
	while(!way.empty())
	{
		tem=way.front();//		cout<<tem.x<<"  "<<tem.y<<"  "<<tem.ti<<enddl; 
		way.pop();
		mark[tem.x][tem.y]=1;
		if(tem.x==endd.x&&tem.y==endd.y&&tem.ti==endd.ti)
		{
			flag=1;return;
		}
		if(flag==1)return;
		if(tem.ti>timee)continue;
		else
		{
			for(int i=0;i<4;i++)
			{
				nex.x=tem.x+to[i][0];
				nex.y=tem.y+to[i][1];
				nex.ti=tem.ti+1;	//	cout<<"nex="<<nex.x<<" "<<nex.y<<" "<<nex.ti<<enddl;
				if(judge(nex))
					way.push(nex);
			}
		}
	}
}
int main()
{
	char a;
	while(scanf("%d%d%d",&n,&m,&timee)&&n!=0)
	{
		memset(maze,0,sizeof(maze));
		memset(mark,0,sizeof(mark));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>a;
				if(a=='S')
				{
					beg.x=i;
					beg.y=j;
					beg.ti=0;
					maze[i][j]=1;
				}
				if(a=='X')
					maze[i][j]=0;
				if(a=='.')maze[i][j]=1;
				if(a=='D')
				{
					maze[i][j]=1;
					endd.x=i;
					endd.y=j;
					endd.ti=timee;
				}
			}
		}
		flag=0;
		dfs();
		if(flag==1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
/*
4 4 5
S.X.
....
..XD
....
3 4 5
S.X.
..X.
..XD
0 0 0
*/
