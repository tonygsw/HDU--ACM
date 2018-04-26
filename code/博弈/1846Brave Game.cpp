#include<iostream>
using namespace std;
int main()
{
    int c,n,m;
    cin>>c;
    while(c--)
    {
        cin>>n>>m;
        if(n<=m)cout<<"first"<<endl;
        else
        {
            if(n%(m+1)==0)
                cout<<"second"<<endl;
            else
                cout<<"first"<<endl;
        }
    }
    return 0;
}
