#include<cstdio>
using namespace std;
bool isp[110];
int cha(char *a,int len)
{
	int sum[26]={0};
	for(int i=0;i<len;i++) sum[*(a+i)-'a']++;
	int max=-1,min=200;
	for(int i=1;i<26;i++)
	{
		if(max<sum[i]) max=sum[i];
		if(min>sum[i]&&sum[i]>0) min=sum[i];
	}
	return max-min;
}
int main()
{
	for(int i=2;i<110;i++) isp[i]=1;
	for(int i=2;i<110;i++)
		for(int j=2;j*i<110;j++)
			isp[j*i]=0;
	char a[110],len=0,w;
	while(w=getchar(),w!='\n') a[len++]=w;
	if(isp[cha(a,len)])
		printf("Lucky Word\n%d\n",cha(a,len));
	else
		printf("No Answer\n0\n");
	return 0;
}
