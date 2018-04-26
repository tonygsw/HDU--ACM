#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class no{
	public:
		double x;
		double y;
};
no node[100005];int n;int c[100005]; 
inline double min2(double x,double y)
{
	if(x<y)return x;
	return y;
}
inline double min3(double x,double y,double z)
{
	double tem1=min2(x,y);
	double tem2=min2(y,z);
	return min2(tem1,tem2);
}
double cmpy(int t1,int t2)    
{    
  return node[t1].y<node[t2].y;    
}  
bool camp(no a,no b)
{
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x; 
}
inline double dis(no a,no b)
{
	double x=pow(a.x-b.x,2)+pow(a.y-b.y,2);
	return sqrt(x);
}
double find(int left,int right)  
{  
    if(left+1==right)  
        return dis(node[left],node[right]);  
    if(left+2==right)  
        return min(dis(node[left],node[right]),min(dis(node[left],node[left+1]),dis(node[left+1],node[right])));  
    int mid=(left+right)>>1;  
    double ans=min(find(left,mid),find(mid+1,right));  
    int i,j,cnt=0;    
    for(i=left;i<=right;i++)    
    {    
        if(node[i].x>=node[mid].x-ans&&node[i].x<=node[mid].x+ans)    
            c[cnt++]=i;    
    }    
    sort(c,c+cnt,cmpy);    
    for(i=0;i<cnt;i++)    
    {    
        for(j=i+1;j<cnt;j++)    
        {    
            if(node[c[j]].y-node[c[i]].y>=ans)   
                break;    
            ans=min(ans,dis(node[c[i]],node[c[j]]));    
        }    
    }     
    return ans;
} 
int main()
{
	while(scanf("%d",&n)&&n!=0)
	{
		for(int i=1;i<=n;i++)
			scanf("%1f%1f",&node[i].x,&node[i].y);//cin>>node[i].x>>node[i].y;
		sort(node+1,node+n+1,camp);
	//	for(int i=1;i<=n;i++)
	//		cout<<node[i].x<<" "<<node[i].y<<"   ";
	//	cout<<endl;
		printf("%.2f\n",find(1,n)/2);
	}
}
