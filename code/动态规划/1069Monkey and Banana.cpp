#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class block{
	public:
		int x,y,z;
		int h;
};
block v[185];
int an[185];
bool camp(block a,block b)
{
	if(a.x==b.x){
		if(b.y==a.y)return a.z>b.z;
		return a.y<b.y;
	}
	else return a.x<b.x;
}
int main()
{
	int n;
	int cont=1;
	while(cin>>n&&n!=0)
	{
		memset(v,0,sizeof(v));
		memset(an,0,sizeof(an));
		for(int i=0;i<6*n;i=i+6)
		{
			cin>>v[i].x>>v[i].y>>v[i].z;//x y z 
			v[i+1].x=v[i].x; v[i+1].y=v[i].z; v[i+1].z=v[i].y;//x z y
			v[i+2].x=v[i].y; v[i+2].y=v[i].x; v[i+2].z=v[i].z;//y x z
			v[i+3].x=v[i].y; v[i+3].y=v[i].z; v[i+3].z=v[i].x;//y z x
			v[i+4].x=v[i].z; v[i+4].y=v[i].x; v[i+4].z=v[i].y;//z x y
			v[i+5].x=v[i].z; v[i+5].y=v[i].y; v[i+5].z=v[i].x;//z y x
		}
		sort(v,v+6*n,camp);
		v[0].h=v[0].z;
		for(int i=1;i<6*n;i++)
		{
			int max=0;
			for(int j=0;j<i;j++)
			{
				if(v[i].x>v[j].x&&v[i].y>v[j].y)
				{
					if(v[j].h>max)max=v[j].h;
				}
			}
			v[i].h=max+v[i].z;
		}
		int max=0;
		for(int i=0;i<6*n;i++)
		{
			if(max<v[i].h)max=v[i].h;
		}
		cout<<"Case "<<cont++<<": maximum height = ";
		cout<<max<<endl;
	}
}
