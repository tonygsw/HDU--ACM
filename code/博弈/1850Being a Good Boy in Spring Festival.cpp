#include<iostream>
using namespace std;
#define ll long long
ll n[1000005];
ll num[1000005];
int main()
{
    int m;
    while(cin>>m&&m!=0)
    {
        int flag=0;
        for(int i=0;i<m;i++)
        {
            cin>>n[i];
            flag^=n[i];
        }
        int ans=0;
        if(flag==0)cout<<0<<endl;
        else
        {
            for(int i=0;i<m;i++)
                if(n[i]>=(flag^n[i]))ans++;
            cout<<ans<<endl;
        }

    }
}
