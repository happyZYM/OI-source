#include<cstdio>
#include<stack>
using namespace std;
stack<char> stk;
int main()
{
	char t;
	while(t=getchar(),t!='@')
	{
		if(t=='(') stk.push('(');
		else if(t==')')
		{
			if(stk.empty())
			{
				printf("NO\n");
				return 0;
			}
			if(stk.top()=='(') stk.pop();
		}
	}
	if(stk.size()==0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
