#include<cstdio>
#include<algorithm>
using namespace std;
int boy,girl;
char lst,now,shb[128];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	lst='.';
	shb['.']='.';
	shb['b']='o';
	shb['o']='y';
	shb['g']='i';
	shb['i']='r';
	shb['r']='l';
	while(now=getchar(),now!=EOF&&now!='\n'&&now!='\r')
	{
	//	printf("read %c expect %c\n",now,shb[lst]);
	//	if(now=='.') goto nxt;
		if((shb[lst]!=now&&lst!='y'&&lst!='l')||((lst=='y'||lst=='l')&&now!='.'))
		{
			if(now=='b'||now=='o'||now=='y') boy++;
			else girl++;
		}
		nxt: lst=now;
	}
	printf("%d\n%d\n",boy,girl);
	return 0;
}
