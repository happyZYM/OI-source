#include<cstdio>
using namespace std;
int main()
{
	int le[26]={0};
	char x;
	while(x=getchar(),x!='\n') le[x-'a']++;
	int ans=0;
	for(int i=1;i<26;i++) if(le[i]>le[ans]) ans=i;
	printf("%c %d\n",ans+'a',le[ans]);
	return 0;
}

