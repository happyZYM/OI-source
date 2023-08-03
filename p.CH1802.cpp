//http://contest-hunter.org:83/contest/0x18%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E7%BB%83%E4%B9%A0/1802%20%E8%A1%A8%E8%BE%BE%E5%BC%8F%E8%AE%A1%E7%AE%974
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
const int maxn=35;
char s[maxn]; int n;
inline int num(int L,int R)
{
	int flg=1;
	if(s[L]=='-') L++,flg=-1;
	int res=0;
	for(int i=L;i<=R;i++) res=res*10+s[i]-'0';
	return res*flg;
}
inline int ksm(int a,int b)
{
	int res=1;
	for(;b;a=a*a,b>>=1) b&1?res=res*a:0;
	return res;
}
int cal(int L,int R)
{
//	printf("cal [%d,%d] ",L,R);
//	for(int i=L;i<=R;i++) putchar(s[i]);
//	puts("");
	if(s[L]=='-') return -cal(L+1,R);
	int cnt=0,La=-1,Lb=-1,Lc=-1;
	for(int i=L;i<=R;i++)
	{
		if(s[i]=='(') cnt++;
		if(s[i]==')') cnt--;
		if(cnt==0)
		{
			switch(s[i])
			{
				case '+': La=i*2+1; break;
				case '-': if(s[i-1]!='-') La=i*2; break;
				case '*': Lb=i*2+1; break; 
				case '/': Lb=i*2; break;
				case '^': Lc=i*2; break; 
			}
		}
	}
	if(La>=0) return (La&1)?(cal(L,La/2-1)+cal(La/2+1,R)):(cal(L,La/2-1)-cal(La/2+1,R));
	if(Lb>=0) return (Lb&1)?(cal(L,Lb/2-1)*cal(Lb/2+1,R)):(cal(L,Lb/2-1)/cal(Lb/2+1,R));
	if(Lc>=0) return ksm(cal(L,Lc/2-1),cal(Lc/2+1,R));
	cnt=0;
	if(s[L]=='(') cnt=1,L++;
	if(s[R]==')') cnt=1,R--;
	if(cnt) return cal(L,R);
	return num(L,R);
}
int main()
{
#ifdef local
	freopen("in.txt","r",stdin);
#endif
	scanf("%s",s);
	n=strlen(s);
	printf("%d\n",cal(0,n-1));
	return 0;
}
