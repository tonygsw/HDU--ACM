#include<bits/stdc++.h>
using namespace std;
int main(){
for(int i=1001;i<1020;i++)
{
	
    sprintf(filename,"%d",i);//指定文件名为从0开始的整数，每次加1
    fp = fopen(filename,"w");//打开文件
    fprintf(fp,"#include<bits/stdc++.h> %i\n");//写点东西
    fprintf(fp,"using namespace std; %i\n");
    fclose(fp);//关闭文件
}
}
