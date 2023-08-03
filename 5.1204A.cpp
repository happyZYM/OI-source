#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[105]; int n;
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%s",s); n=strlen(s);
	if(n==1&&(s[0]=='0'||s[0]=='1')) { puts("0"); return 0; }
	int res=0;
	res+=n/2;
	if((n-1)%2==0)
		for(int i=1;i<n;i++) if(s[i]=='1') { res++; break; }
	printf("%d\n",res);
	return 0;
}