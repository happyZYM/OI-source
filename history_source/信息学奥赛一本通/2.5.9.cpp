#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char input[21][25],str[500],st;
char answer[100][25];
int n,res;
int lenof[21];
int times[21],t2[21];
#ifdef DEBUG
FILE *fout=fopen("result.txt","w");
void sync()
{
	fflush(stdout);
	fflush(fout);
}
#endif
bool equal(char* s1,char* s2,int len)
{
#ifdef DEBUG
	fprintf(fout,"\nin fuction equal: s1=%s s2=%s len=%d\n",s1,s2,len);
	sync();
#endif
	for(int i=0;i<len;i++)
		if(s1[i]!=s2[i])
		{
#ifdef DEBUG
			fprintf(fout,"\t%c!=%c i=%d\n\n",s1[i],s2[i],i);
			sync();
#endif
			return 0;
		}
#ifdef DEBUG
	fprintf(fout,"\tequal!\n\n");
	sync();
#endif
	return 1;
}
void dfs(int dep,int len)
{
#ifdef DEBUG
	fprintf(fout,"dep=%d str=%s len=%d\n",dep,str,len);
	sync();
		if(len>res)
		{
			printf("updated! now res=%d\n",len);
			printf("\t%s=%s",str,answer[0]);
			for(int i=1;i<dep;i++) printf("+%s",answer[i]);
			printf("\n\n");
			sync();
			
			fprintf(fout,"\t\t\t\t\t\t\t\t\t\tupdated! now res=%d\n",len);
			fprintf(fout,"\t%s=%s",str,answer[0]);
			for(int i=1;i<dep;i++) fprintf(fout,"+%s",answer[i]);
			fprintf(fout,"\n\n");
			sync();
		}
#endif
	res=max(res,len);
//	if(dep>=n*2) return;
	int i,j,k,maxlen,catlen,tl;
	for(i=0;i<n;i++)
	{
		if(t2[i]==0) continue;
#ifdef DEBUG
		fprintf(fout,"\ti=%d\n",i);
		sync();
		fprintf(fout,"\t\ttry to cat the string!\n");
		sync();
#endif
		maxlen=min(len,lenof[i]);
		catlen=k=0;
#ifdef DEBUG
		fprintf(fout,"\t\tmaxlen=%d k=%d\n",maxlen,k);
		sync();
#endif
		while(k<maxlen)
		{
#ifdef DEBUG
			fprintf(fout,"\t\t\tk=%d\n",k);
			fprintf(fout,"\t\t\tcall equal in place 1!\n");
			sync();
#endif
			if(!equal(str+len-k,input[i],k))
			{
#ifdef DEBUG
				fprintf(fout,"\t\t\t\tbreak in place 1!\n");
				sync();
#endif
				k++;
				continue;
			}
			catlen=k++;
		}
#ifdef DEBUG
		fprintf(fout,"\t\tcall equal in place 2!\n");
		sync();
#endif
		if(equal(str+len-maxlen,input[i],maxlen)) goto addr1;
#ifdef DEBUG
		fprintf(fout,"\t\tcat the %s after %s catlen=%d\n",input[i],str,catlen);
		sync();
#endif
		strcpy(str+len-catlen,input[i]);
		strcpy(answer[dep],input[i]);
		tl=len+lenof[i]-catlen;
		memset(times,0,sizeof(times));
#ifdef DEBUG
		fprintf(fout,"\t\tchecking the string before!\n");
		sync();
#endif
		for(j=0;j<n;j++)
			for(k=0;k+lenof[j]<=tl;k++)
			{
#ifdef DEBUG
				fprintf(fout,"\t\tcall equal in place 3!\n");
				sync();
#endif
				if(equal(str+k,input[j],lenof[j]))
				{
					times[j]++;
					if(times[j]>2) goto addr1;
				}
			}
		t2[i]--;
		dfs(dep+1,tl);
		t2[i]++;
addr1:
		continue;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",input[i]);
		lenof[i]=strlen(input[i]);
		t2[i]=2;
	}
	getchar();
	scanf("%c",&st);
#ifdef DEBUG
	printf("n=%d st=%c\n",n,st);
	for(int i=0;i<n;i++) printf("%s\n",input[i]);
	sync();
#endif
	for(int i=0;i<n;i++)
		if(input[i][0]==st)
		{
			strcpy(str,input[i]);
			strcpy(answer[0],input[i]);
			t2[i]--;
			dfs(1,lenof[i]);
			t2[i]++;
		}
	printf("%d\n",res);
	return 0;
}
/*
5
at
touch
cheat
choose
tact
a

atoucheatactactouchoose
at touch cheat tact touch choose

atcheatchoosetouchtactchoosetouchtact=at+cheat+choose+touch+tact+choose+touch+tact
*/
