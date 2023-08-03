#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=51000005;
int n,R[maxn],ans;
char a[maxn],s[maxn<<1];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%s",a); n=strlen(a);
	s[0]=s[1]='#';
	for(int i=0;i<n;i++) s[i*2+2]=a[i],s[i*2+3]='#';
	n=2*n+2;
	int maxright=0,mid=0;
	for(int i=1;i<n;i++)
	{
		if(i<maxright) R[i]=min(R[mid*2-i],R[mid]+mid-i);
		else R[i]=1;
		while(s[i-R[i]]==s[i+R[i]]) ++R[i];
		if(R[i]+i>maxright) { maxright=R[i]+i; mid=i; }
	}
	ans=1;
	for(int i=0;i<n;i++) ans=max(ans,R[i]-1);
	printf("%d\n",ans);
	return 0;
}
/*
orzro
*/
