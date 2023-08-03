#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
char str[130];
int len;
bool chk()
{
	stack<char> stk;
	for(int i=0;i<len-1;i++)
	{
		if(str[i]=='('||str[i]=='[') stk.push(str[i]);
		else
		{
			if(stk.empty()) return 0;
			if((str[i]==')'&&stk.top()!='(')||(str[i]==']'&&stk.top()!='[')) return 0;
			stk.pop();
		}
	}
	return (stk.size()==0);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	fgets(str,130,stdin);
	for(int i=0;i<n;i++)
	{
		fgets(str,130,stdin);
		len=strlen(str);
		if(chk()) printf("Yes\n");
		else printf("No\n"); 
	}
	return 0;
}
