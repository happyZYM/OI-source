#include<cstdio>
int main()
{
	char bs[110],ss[110],c,s[110];
	int lenb=0,lens=110,len=0;
	while(c=getchar(),c!='\n'&&c!='\r')
	{
		if(c==','||c==' ')
		{
			if(len>lenb)
			{
				lenb=len;
				for(int i=0;i<len;i++) bs[i]=s[i];
			}
			if(len<lens)
			{
				lens=len;
				for(int i=0;i<len;i++) ss[i]=s[i];
			}
			len=0;
		}
		else s[len++]=c;
	}
	if(len>lenb)
	{
		lenb=len;
		for(int i=0;i<len;i++) bs[i]=s[i];
	}
	if(len<lens)
	{
		lens=len;
		for(int i=0;i<len;i++) ss[i]=s[i];
	}
	bs[lenb]='\0';
	ss[lens]='\0';
	printf("%s\n%s\n",bs,ss);
	return 0;
}
/*
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char word[110],wmax[110],wmin[110];
	int l,maxl,minl;
	scanf("%s",word);
	strcpy(wmax,word);
	strcpy(wmin,word);
	while(getchar()!='\n')
	{
		scanf("%s",word);
		l=strlen(word);
		if(l>strlen(wmax)) strcpy(wmax,word);
		if(l<strlen(wmin)) strcpy(wmin,word);
	}
	printf("%s\n%s",wmax,wmin);
	return 0;
}
*/
/*
#include<cstdio>
int main()
{
	char bs[110],ss[110],c,s[110];
	int lenb=0,lens=110,len=0;
	while(c=getchar(),c!='\n'&&c!='\r')
	{
		if(c==','||c==' ')
		{
			if(len>lenb)
			{
				lenb=len;
				for(int i=0;i<len;i++) bs[i]=s[i];
			}
			if(len<lens)
			{
				lens=len;
				for(int i=0;i<len;i++) ss[i]=s[i];
			}
			len=0;
		}
		else s[len++]=c;
	}
	if(len>lenb)
	{
		lenb=len;
		for(int i=0;i<len;i++) bs[i]=s[i];
	}
	if(len<lens)
	{
		lens=len;
		for(int i=0;i<len;i++) ss[i]=s[i];
	}
	bs[lenb]='\0';
	ss[lens]='\0';
	printf("%s\n%s\n",bs,ss);
	return 0;
}
*/
