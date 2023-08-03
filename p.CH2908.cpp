//http://contest-hunter.org:83/contest/0x29%E3%80%8C%E6%90%9C%E7%B4%A2%E3%80%8D%E7%BB%83%E4%B9%A0/2908%20%E5%AD%97%E4%B8%B2%E5%8F%98%E6%8D%A2
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<set>
#include<string>
using namespace std;
char a[25],b[25],u[10][25],v[10][25];
int lim,cg,lu[10],lv[10];
set<string> st;
void dfs(int d)
{
	if(d==lim)
	{
		if(strcmp(a,b)==0)
		{
			printf("%d\n",lim);
			exit(0);
		}
		return;
	}
	if(st.find(a)!=st.end()) return;
	st.insert(a);
	char bk[25];
	for(int i=0;i<cg;i++)
	{
		int p=0,lena=strlen(a);
		while(p<lena)
		{
			int x=strstr(a+p,u[i])-a;
			if(x<0||x>=lena) break;
			memcpy(bk,a,sizeof(a));
			memcpy(a+x,v[i],lv[i]);
			memcpy(a+x+lv[i],bk+x+lu[i],lena-x-lu[i]);
			a[lena-lu[i]+lv[i]]=0;
			dfs(d+1);
			memcpy(a,bk,sizeof(bk));
			p=x+lu[i];
		}
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%s%s",a,b);
	while(scanf("%s%s",u[cg],v[cg])==2)
	{
		lu[cg]=strlen(u[cg]);
		lv[cg]=strlen(v[cg]);
		cg++;
	}
	if(strcmp(a,b)==0) { puts("0"); return 0; }
	for(int i=1;i<=10;i++)
	{
		lim=i;
		st.clear();
		dfs(0);
	}
	puts("NO ANSWER!");
	return 0;
}
