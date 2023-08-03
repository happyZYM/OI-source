#include<cstdio>
#include<cstring>
int len;
char str[100];
void solve()
{
	scanf("%s",str);
	len=strlen(str);
	char *p=str,t;
	int cnt=0;
	double sum=0;
	while(p<str+len)
	{
		t=*p++;
		cnt=0;
		while(*p>='0'&&*p<='9')
		{
			cnt=cnt*10+*p-'0';
			p++;
		}
		if(cnt==0) cnt=1;
		switch(t)
		{
			case 'C':
				sum+=12.01*cnt;
				break;
			case 'H':
				sum+=1.008*cnt;
				break;
			case 'O':
				sum+=16.00*cnt;
				break;
			case 'N':
				sum+=14.01*cnt;
				break;
		}
	}
	printf("%.3lf\n",sum);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) solve();
	return 0;
}
/*
Sample Input
4
C
C6H5OH
NH2CH2COOH
C12H22O11
Sample Output
12.010
94.108
75.070
342.296
*/
