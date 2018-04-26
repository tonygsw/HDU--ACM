#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include <iomanip>
#define eps 1e-8
#define MAXN 10005
using namespace std;
int minn(int a,int b)
{
	if(a<b)return a;
	else return b;
}
int maxx(int a,int b)
{
	if(a>b)return a;
	else return b;
}
struct Point
{
    double x, y;
    Point(){}
    Point(double X, double Y)
	{
        x=X;y=Y;
    }
};
Point P[MAXN];
int dcmp(double x)
{
    if(fabs(x)<eps)
        return 0;
    else
        return x<0?-1:1;
}
Point operator -(Point A,Point B)
{
    return Point(A.x-B.x, A.y-B.y);
}
Point operator + (Point A, Point B)
{
    return Point(A.x+B.x, A.y+B.y);
}
Point operator * (Point A, double p)
{
    return Point(A.x*p, A.y*p);
}
double Cross(Point A, Point B)//叉积
{
    return A.x*B.y - A.y*B.x;
}
double Dot(Point A, Point B)//点积
{
    return A.x*B.x + A.y*B.y;
}
double Dis(Point A, Point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}
bool operator == (Point A, Point B){
    return dcmp(A.x-B.x) == 0 && dcmp(A.y-B.y) == 0;
}
bool cmp(Point A, Point B)//按极角升序排序，若角度相等距离小的在前面
{
    double temp =Cross(A-P[0],B-P[0]);
    if(dcmp(temp)>0) return true;
    if(dcmp(temp) ==0&&dcmp(Dis(P[0], A) - Dis(P[0], B)) < 0) return true;
    return false;
}
int Stack[MAXN], top;//下标从0开始计数到top
void input(int n)
{
    scanf("%lf%lf", &P[0].x, &P[0].y);
    double xx = P[0].x, yy = P[0].y;
    int id = 0;//找到y坐标最小的点，若有多个选择x坐标最小的记录下标
    for(int i=1;i<n;i++)
    {
        scanf("%lf%lf", &P[i].x, &P[i].y);
        if(P[i].y<yy||(P[i].y==yy &&P[i].x<xx))
        {
            xx=P[i].x;
            yy=P[i].y;
            id=i;
        }
    }
    Point T;
    T = P[0];P[0]=P[id];P[id]=T;
    sort(P+1, P+n, cmp);//极角排序
}
void Graham(int n)
{
    if(n == 1){top=0;Stack[0] =0;}
    else if(n == 2)
    {
        top=1;
        Stack[0]=0;
        Stack[1]=1;
    }
    else
    {
        for(int i=0;i<=1;i++)
            Stack[i]=i;
        top=1;
        for(int i = 2; i <n; i++)
        {   //如果和上一条边成左旋关系，压栈继续；反之一直弹栈直到和栈顶两点的边成左转关系，压栈继续。
            while(top > 0 && dcmp(Cross(P[Stack[top]]-P[Stack[top-1]], P[i]-P[Stack[top-1]])) <= 0) top--;
            top++;
            Stack[top] = i;
        }
    }
}
int main()
{
    int t,n,r;
    scanf("%d",&t);
    double pi=3.14159926;
    while(t--)
    {
        scanf("%d%d",&n,&r);
        input(n);
        Graham(n);
        double ans=0;
        for(int i=1;i<=top;i++)
            ans+=Dis(P[Stack[i]],P[Stack[i-1]]);
        ans+=Dis(P[Stack[top]],P[Stack[0]]);
        ans+=2*r*pi;
        int an=ans;
        if(ans-an>=0.5)an=an+1;
        cout<<an<<endl;
        if(t>0)cout<<endl;
    }
}
