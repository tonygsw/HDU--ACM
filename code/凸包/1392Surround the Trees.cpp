#include<cmath>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include <iomanip>
using namespace std;
#define ll long long
class point
{
    public:
        double x,y;
};
point p[105];int n;
int Stack[105];int top;
point operator -(point a,point b)
{
    point tem;
    tem.x=a.x-b.x;tem.y=a.y-b.y;
    return tem;
}
double cross(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool camp(point a,point b)
{
    double tem=cross(a-p[0],b-p[0]);
    if(tem>0)return true;
    else if(tem==0&&(dis(p[0],a)-dis(b,p[0]))<0)return true;
    return false;
}

void input(int n)
{
    scanf("%lf%lf", &p[0].x, &p[0].y);//cin>>p[0].x>>p[0].y;
    double xx=p[0].x,yy=p[0].y;
    int id=0;
    for(int i=1;i<n;i++)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);//cin>>p[i].x>>p[i].y;
        if(p[i].y<yy||(p[i].y==yy&&p[i].x<xx))
        {
            xx=p[i].x;
            yy=p[i].y;
            id=i;
        }
    }
    point t;
    t=p[0];p[0]=p[id];p[id]=t;
    sort(p+1,p+n,camp);
}
void graham(int n)
{
    if(n==1){top=0;Stack[0]=0;}
    if(n==2)
    {
        top=1;
        Stack[0]=0;Stack[1]=1;
    }
    if(n>2)
    {
        top=1;
        Stack[0]=0;Stack[1]=1;
        for(int i=2;i<n;i++)
        {
            while(top>0&&cross(p[Stack[top]]-p[Stack[top-1]],p[i]-p[Stack[top-1]])<=0)top--;
            top++;
            Stack[top]=i;
        }
    }
}
int main()
{
    while(~scanf("%d",&n)&&n!=0)
    {
        input(n);
        graham(n);
    /*    cout<<"-----"<<endl;
        for(int i=0;i<=top;i++)
            cout<<p[Stack[i]].x<<"  "<<p[Stack[i]].y<<endl;
        cout<<"aaaaaaaaa"<<endl;
      */  double ans=0;
        for(int i=1;i<=top;i++)
        {
            ans+=dis(p[Stack[i]],p[Stack[i-1]]);
        }
        ans+=dis(p[Stack[top]],p[Stack[0]]);
        if(n==1)cout<<0<<endl;
        if(n==2)
        {
            cout<<setiosflags(ios::fixed)<<setprecision(2);
            cout<<dis(p[0],p[1])<<endl;
        }
        else
            cout<<fixed<<setprecision(2)<<ans<<endl;//
    }
}
