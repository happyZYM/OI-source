#include<cstdio>
#include<cstring>
char n[210];
int main()
{
	int k,x,len,m[500]={1};
	for(int i=1;i<500;i++) m[i]=(m[i-1]*2011)%10000; 
	scanf("%d",&k);
	while(k--)
	{
		scanf("%s",n);
		len=strlen(n);
		switch(len)
		{
			case 1:x=n[0]-'0';break;
			case 2:x=(n[0]-'0')*10+n[1]-'0';break;
			case 3:x=((n[0]-'0')*10+n[1]-'0')*10+n[2]-'0';break;
			default:x=0;
				for(int j=len-4;j<len;j++) x=x*10+n[j]-'0';
		}
		printf("%d\n",m[x%500]);
	}
	return 0;
}

