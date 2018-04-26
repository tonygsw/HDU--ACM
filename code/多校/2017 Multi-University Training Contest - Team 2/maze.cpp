#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
#define ll long long
inline int minn(int a,int b)
{
	if(a<b)return a;
	else return b;
}
string sub(string a,string b)
{
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int temlen=minn(a.length(),b.length());
	int jz=0;int i=0;
	for(;i<temlen;i++)
	{
		a[i]=a[i]-b[i]+jz+'0';
		if(a[i]<'0')
		{
			a[i]+=10;
			jz=-1;
		}
		else jz=0;
	}
	for(;i<a.length();i++)
	{
		if(jz==0)break;
		else
		{
			a[i]=a[i]+jz;
			if(a[i]<'0')
			{
				a[i]+=10;
				jz=-1;
			}
			else jz=0;
		}
	}
	reverse(a.begin(),a.end());
	//cout<<"a="<<a<<endl;
	while(a[0]=='0'&&a.length()>1)
		a.erase(0,1);
	return a;
}
bool judge(string a,string b)//a>b
{
	if(a.length()<b.length())return false;
	if(a.length()>b.length())return true;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>b[i])return true;
		if(b[i]>a[i])return false;
	}
	return false;
} 
int main()
{
	string a,b,c,d;
	while(cin>>a>>b>>c>>d)
	{
	//	cout<<"a="<<a<<"b="<<b<<"c="<<c<<"d="<<d<<endl;
		string ans;
		while(true)
		{
			if(a=="1"&&b=="0"&&c=="0"&&d=="1")break;
			if(judge(a,b)||judge(c,d))
			{
				a=sub(a,b);
				c=sub(c,d);
				ans+="0";
			//	cout<<"ans=="<<ans<<endl; 
			}
			else
			{
				b=sub(b,a);
				d=sub(d,c);
				ans+="1";
			//	cout<<"aa="<<ans<<endl; 
			}
			//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		}
		reverse(ans.begin(),ans.end());
		cout<<ans<<endl;
	}
}
