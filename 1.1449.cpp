#include<cstdio>
typedef long long LL;
LL stk[1005]; int top;
LL now; char ch;
int main()
{
	while(ch=getchar(),ch!='@')
	{
		if(ch>='0'&&ch<='9') now=now*10+ch-'0';
		else if(ch=='.') stk[top++]=now,now=0;
		else if(ch=='+') stk[top-2]+=stk[top-1],--top;
		else if(ch=='-') stk[top-2]-=stk[top-1],--top;
		else if(ch=='*') stk[top-2]*=stk[top-1],--top;
		else if(ch=='/') stk[top-2]/=stk[top-1],--top;
	}
	printf("%lld\n",stk[0]);
	return 0;
}
