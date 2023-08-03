#include<cstdio>
inline int max(int a,int b){return a>b?a:b;}
int a[120][3],n,s,t,t1,t2,k,i,j,x,y;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s);
		for(j=1;j<=s;j++) scanf("%d",&(a[j][1]));
		t=0;
		for(j=1;j<=s;j++)
		{
			for(x=1;x<=s;x++)
			a[x][2]=1;
			t1=0;t2=0;
			for(x=j;x>=1;x--)
			{
				k=0;
				for(y=x+1;y<=j;y++)
					if(k<a[y][2]&&a[x][1]<a[y][1]) k=a[y][2];
				a[x][2]+=k;
				if(t1<a[x][2]) t1=a[x][2];
			}
			for(x=s;x>=j;x--)
			{
				k=0;
				for(y=x+1;y<=s;y++)
					if(k<a[y][2]&&a[x][1]>a[y][1]) k=a[y][2];
				a[x][2]+=k;
				if(t2<a[x][2]) t2=a[x][2];
			}
			t=max(max(t1,t2),t);
		}
		printf("%d\n",t);
	}
	return 0;
}
