#include<iostream>
#include<cmath>
#include<string>
using namespace std;
//�ø�Ԫ�ظ�����ӽ���������Ϊɢ�б�Ĵ�С
#define NHASH 299897
#define MULT 131
unsigned int hash(string p)
{
    unsigned int h = 0;
    for (int i=0;i<p.length();i++)
        h = MULT *h +p[i];
    return h % NHASH;
}
int main()
{
	string a;
	while(cin>>a)
	{
		cout<< hash(a)<<endl;
	}
}
