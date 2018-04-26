

#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
using namespace std;
#define ll long long
class Point{
	public:
		double x;
		double y;
};
Point p,q,p1,q1;
double r;
double dist(Point a,Point b)
{
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
int main()
{
	int t;Point o;o.x=0;o.y=0;
//	freopen("1002.in","r",stdin);
//	freopen("ans.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&r);
		scanf("%lf%lf",&p.x,&p.y);
		scanf("%lf%lf",&q.x,&q.y);
		if(p.x==0&&p.y==0)
		{
			printf("%.7f\n",2*r);
			continue;
		}
		if(p.x==q.x&&p.y==q.y)
		{
			double k=sqrt(r*r/(pow(p.x,2)+pow(p.y,2)));
			Point fina;
			fina.x=k*p.x;fina.y=k*p.y;
			printf("%.7f\n",2*dist(fina,p));
			continue;
		}
		double k1=r*r/(p.x*p.x+p.y*p.y);
		p1.x=p.x*k1;p1.y=p.y*k1;
		double k2=r*r/(q.x*q.x+q.y*q.y);
		q1.x=q.x*k2;q1.y=q.y*k2;
		double dis=0;Point mid;
		//cout<<"p1.x="<<p1.x<<" p1.y="<<p1.y<<"  q"<<q1.x<<"  "<<q1.y<<endl;
		Point finall;double ans=0;
		if(p1.x==q1.x)
		{
			if(abs(p1.x)<=r)
			{
				finall.x=p1.x;
				finall.y=sqrt(pow(r,2)-pow(p1.x,2));
				ans=dist(finall,p)+dist(finall,q);
			}
			else
			{
				if(p1.x<0)finall.x=-r;
				else finall.x=r;
				finall.y=0;
				ans=dist(finall,p)+dist(finall,q);
			}
		}
		else
		{
			mid.x=(p1.x+q1.x)/2;
			mid.y=(p1.y+q1.y)/2;
			dis=dist(mid,o);
			if(dis<=r)
			{
				double k=(p1.y-q1.y)/(p1.x-q1.x);
				double b=p1.y-k*p1.x;
				double A=1+pow(k,2);
				double B=2*k*b;
				double C=pow(b,2)-pow(r,2);
				finall.x=(-B+sqrt(B*B-4*A*C))/(2*A);
				finall.y=k*finall.x+b;
				ans=dist(finall,p)+dist(finall,q);
			}
			else
			{
				double k=sqrt((r*r)/(mid.x*mid.x+mid.y*mid.y));
				finall.x=k*mid.x;finall.y=k*mid.y;
				ans=dist(finall,p)+dist(finall,q);
			}
		}
		printf("%.7f\n",ans);//cout<<ans<<endl;
	}
}
/*
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
const double esp=0.000000005;
double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
	freopen("1002.in","r",stdin);
	freopen("ans1.txt","w",stdout);
    int T;scanf("%d",&T);
    while(T--)
    {
        double r,x[2],y[2];
        scanf("%lf%lf%lf%lf%lf",&r,&x[0],&y[0],&x[1],&y[1]);
        double op=dis(0.0,0.0,x[0],y[0]);
        if(x[0]==x[1]&&y[0]==y[1]){printf("%.7lf\n",2.0*(r-op));continue;}
        if(op==r){printf("%.7lf\n",dis(x[0],y[0],x[1],y[1]));continue;}
        double o=acos((x[0]*x[1]+y[0]*y[1])/op/op)/2.0;
        double d=r*r/op;
        double h=d*cos(o);
        if(h<=r){printf("%.7lf\n",2.0*r*sin(o));continue;}
        double a=h-r,b=d*sin(o);
        printf("%.7lf\n",op*sqrt(a*a+b*b)*2.0/r);
    }
    return 0;
}*/
