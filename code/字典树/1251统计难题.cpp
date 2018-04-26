#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
class node{
    public:
        int ch[26];
        int num;
};
node tre[105];
int cnt=1;
void build(char *a)
{
    int now=0;
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        int id=a[i]-'a';
        if(tre[now].ch[id]==0)tre[now].ch[id]=cnt++;
        now=tre[now].ch[id];
        tre[now].num++;
    }
}
int fin(char *a)
{
    int now=0;int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        int id=a[i]-'a';
        if(tre[now].ch[id]!=0)
        {
            now=tre[now].ch[id];
            if(i==(len-1))return tre[now].num;
        }
        else return 0;
    }
}
int main()
{
    char a[12];
    cnt=1;
    while(gets(a)&&a[0]!=NULL)
   	  build(a);
    while(gets(a))
        cout<<fin(a)<<endl;
    return 0;
}
