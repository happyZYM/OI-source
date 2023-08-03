#include<cstdio>
#include<cstring>
#define P1 printf(" -- is not a palindrome.\n\n")
#define P2 printf(" -- is a regular palindrome.\n\n")
#define P3 printf(" -- is a mirrored string.\n\n")
#define P4 printf(" -- is a mirrored palindrome.\n\n")
using namespace std;
char a[128];
#define f(x,y) a[#x[0]]=#y[0]
int init()
{
	memset(a,-128,sizeof(a));
	f(A,A);
	f(E,3);
	f(H,H);
	f(I,I);
	f(J,L);
	f(L,J);
	f(M,M);
	f(O,O);
	f(S,2);
	f(T,T);
	f(U,U);
	f(V,V);
	f(W,W);
	f(X,X);
	f(Y,Y);
	f(Z,5);
	f(1,1);
	f(2,S);
	f(3,E);
	f(5,Z);
	f(8,8);
}
bool hws(char *s)
{
	int len=strlen(s);
	for(int i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-i-1])
			return false;
	}
	return true;
}
bool jxc(char *s)
{
	int len=strlen(s);
	for(int i=0;i<len/2+1;i++)
		if(a[s[i]]!=s[len-i-1]||a[s[i]]==-128)
			return false;
	return true;
}
char s[1000005];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	init();
	while(scanf("%s",s)==1)
	{
		printf("%s",s);
		bool a1=hws(s),a2=jxc(s);
		if(a1&&a2)P4;
		else if(a1)P2;
		else if(a2)P3;
		else P1;
	}
	return 0;
}
