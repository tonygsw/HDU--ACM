#include <iostream>
#include <vector>
#include<stdio.h>
#include<cstdio>
#include <algorithm>
using namespace std;
#define ll long long
typedef struct node
{
    ll data;//时间值
    int flag;//0表示开始时间，1表示结束时间
}Node;
class noe
{
	public:
		ll beg;
		ll en;
};
Node no[200005];int n;noe te[100005];
bool compare(Node n1, Node n2)
{
	if(n1.data==n2.data)return n1.flag<n2.flag;
    return n1.data<n2.data;//升序排列
}
bool camp(noe a,noe b)
{
	if(a.en==b.en)return a.beg<b.beg;
	return a.en<b.en;
}
ll maxrepeat()//最大重叠数
{
    ll curr=0, sum=0;
    for(int i=0;i<n;i++)
    {
       if(!no[i].flag)
       {
           curr++;
           if(curr>sum)
               sum=curr;
       }
       else
           curr--;
    }
    return sum;
}
int main()
{
    int t;
    freopen("1010.in","r",stdin);
	freopen("ans.txt","w",stdout); 
    scanf("%d",&t);
    while(t--)
	{
		scanf("%d",&n);
		Node tem;
		for(int i=0;i<2*n;i++)
		{
			scanf("%I64d",&no[i].data);
			no[i].flag=i%2;
			if(no[i].flag==0)
				te[i/2].beg=no[i].data;
			else te[i/2].en=no[i].data;
		}
		sort(no,no+2*n,compare);
		sort(te,te+n,camp);

		ll ans=0;ll minend=0;ll minend2=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<n;i++)
		{
			if(te[i].beg>=minend)
			{
				if(minend!=0)ans+=te[i].en-minend;
				else ans+=te[i].en-te[i].beg;
				minend=min(minend2,te[i].en);
				minend2=max(minend2,te[i].en);
			}
			else
			{
				ans+=te[i].en-te[i].beg;
				if(minend<=te[i].en)minend2=te[i].en;
				else minend=te[i].en;
			}
		}
		ll ans1=0;ll minbe=0x3f3f3f3f3f3f3f;ll minbe2=0;
		for(int i=n-1;i>=0;i--)
		{
			if(te[i].en<=minbe)
			{
				if(minbe!=0x3f3f3f3f3f3f3f)ans1+=minbe-te[i].beg;
				else ans1+=te[i].en-te[i].beg;
				minbe=max(minbe2,te[i].beg);
				minbe2=min(minbe2,te[i].beg);
			}
			else
			{
				ans1+=te[i].en-te[i].beg;
				if(minbe>=te[i].beg)minbe2=te[i].beg;
				else minbe=te[i].beg;
			}
		}
		//cout<<ans<<"  "<<ans1<<endl; 
		ans=min(ans1,ans);
		cout<<maxrepeat()<<" "<<ans<<endl;
	}
}
