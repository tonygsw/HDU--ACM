#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int jc(int n)
{
	if(n<=1)	return 1;
	else return jc(n-1)*n;
}
int main()
{
	double e=2.5;
	cout<<"n e"<<endl<<"- -----------"<<endl;
	printf("0 1\n");
 	printf("1 2\n");
 	printf("2 2.5\n");

	for(int i=3;i<10;i++)
	{
		double tem=(double)1/jc(i);
		e=e+tem;
		printf("%d %11.9f\n",i,e);
	}
}
