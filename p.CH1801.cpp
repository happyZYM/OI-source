//http://contest-hunter.org:83/contest/0x18%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E7%BB%83%E4%B9%A0/1801%20%E6%8B%AC%E5%8F%B7%E7%94%BB%E5%AE%B6
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
const int maxn=100005;
char s[maxn],hsh[128];
int n,p,res=0;
void Match()
{
	stack<char> stk;
	int done=0;
#define EXIT { res=max(res,done); return; }
	while(p<n)
	{
		switch(s[p])
		{
			case '[': case '(': case '{':
				stk.push(s[p]);
				break;
			case ']': case ')': case '}':
				if(stk.empty()) EXIT;
				if(hsh[stk.top()]!=s[p]) EXIT;
				stk.pop();
				done+=2;
				break;
		}
		p++;
	}
	res=max(done,res);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%s",s); n=strlen(s);
	hsh['(']=')'; hsh['[']=']'; hsh['{']='}';
	while(p<n)
	{
		Match();
		p++;
	}
	printf("%d\n",res);
	return 0;
}
