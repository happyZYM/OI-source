#include<cstdio>
#include<cstring>
int cnt[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
char s[205]; int len,res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	gets(s);
	len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]>='a'&&s[i]<='z') res+=cnt[s[i]-'a'];
		if(s[i]==' ') res++;
	}
	printf("%d\n",res);
    return 0;
}
