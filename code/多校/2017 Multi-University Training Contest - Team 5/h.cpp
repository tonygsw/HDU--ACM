#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<cstdio>
#include<stdio.h>
#include<iostream>
using namespace std;
#define ll long long
int t;
ll n, m;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &n, &m);
		if(n==1)cout<<n<<endl;
		else if(m>=(n*(n-1)/2))cout<<(n*(n-1))<<endl;
		else if(m<=(n-1))cout<<(2*m*m+n*(n-m-1)*(m+n))<<endl;
		else cout<<2*((n-1)*(n-1)-(m-n+1))<<endl;
	}
}
#include<cstdio>  
using namespace std;  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        long long n,m,p,q;  
        scanf("%lld%lld",&n,&m);  
        long long ans=0;  
        int flag=0;  
        if(m>n*(n-1)/2)///�������Χ�ڴ���ÿ������֮�䶼����һ����������Ϊn*��n-1��  
        {  
            printf("%lld\n",n*(n-1));  
            flag=1;  
        }  
        else if(m>=n-1&&m<=n*(n-1)/2)///�������Χ����mΪn*��n-1��/2���ÿ��һ���߾ͼ���2  
      {  
            ans+=((n*(n-1)/2)-m)*2+n*(n-1);  
        }  
        else///�����Χ�ڷ�Ϊ�����ĵ�������һ��ĵ㣬���������  
        {  
            p=m+1;  
            q=n-m-1;  
            ans+=q*p*n*2+q*(q-1)*n+(p-1)*(p-1)*2;  
        }  
        if(flag==0)  
        printf("%lld\n",ans);  
    }  
}  
