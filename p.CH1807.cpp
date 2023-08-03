//http://contest-hunter.org:83/contest/0x18%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E7%BB%83%E4%B9%A0/1807%20Necklace
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1000005;
int n; char a[maxn*2],b[maxn*2];
inline bool Diff(int p1,int p2)
{
	for(int i=0;i<n;i++) if(a[p1+i]!=b[p2+i]) return 1;
	return 0;
}
inline int GetMin(char *s)
{
	int i=0,j=1,k;
	while(i<n&&j<n)
	{
		for(k=0;k<n&&s[i+k]==s[j+k];k++);
		if(k==n) break;
		if(s[i+k]>s[j+k])
		{
			i+=k+1;
			if(i==j) i++;
		}
		else
		{
			j+=k+1;
			if(i==j) j++;
		}
	}
	return min(i,j);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%s%s",a,b);
	n=strlen(a);
	memcpy(a+n,a,n); memcpy(b+n,b,n);
	int p1=GetMin(a),p2=GetMin(b);
	if(Diff(p1,p2)) printf("No\n");
	else
	{
		printf("Yes\n");
		for(int i=0;i<n;i++) printf("%c",a[p1+i]); puts("");
	}
	return 0;
}
