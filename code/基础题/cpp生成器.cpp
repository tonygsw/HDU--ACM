#include<bits/stdc++.h>
using namespace std;
int main(){
for(int i=1001;i<1020;i++)
{
	
    sprintf(filename,"%d",i);//ָ���ļ���Ϊ��0��ʼ��������ÿ�μ�1
    fp = fopen(filename,"w");//���ļ�
    fprintf(fp,"#include<bits/stdc++.h> %i\n");//д�㶫��
    fprintf(fp,"using namespace std; %i\n");
    fclose(fp);//�ر��ļ�
}
}
