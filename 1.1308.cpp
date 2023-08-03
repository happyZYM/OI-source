#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
char obj[20],b1[10],s[1000005],b2[10];
int pos=-1,cnt=0;
int main()
{
	scanf("%s",obj);
	fgets(s,sizeof(s),stdin);
	fgets(s,sizeof(s),stdin);
	int lena=strlen(obj),lenb=strlen(s);
	s[lenb--]=' ';
	*(s-1)=' ';
	for(int i=0;i<lena;i++) obj[i]=tolower(obj[i]);
	for(int i=0;i<lenb;i++) s[i]=tolower(s[i]);
	for(int i=0;i+lena<=lenb;i++)
	{
		bool ok=1;
		for(int j=0;j<lena;j++)
			if(obj[j]!=s[i+j])
			{
				ok=0;
				break;
			}
		if(!(s[i-1]==' '&&s[i+lena]==' ')) ok=0;
		if(ok)
		{
			if(pos==-1) pos=i;
			cnt++;
		}
	}
	if(pos==-1) printf("-1\n");
	else printf("%d %d\n",cnt,pos);
	return 0;
}
