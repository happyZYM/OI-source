#include<cstdio>
#define For(i,a,b) for(int i=a;i<=b;i++)
int hws[100005],cnt;
int L,R;
inline bool isp(int n)
{
	for(int i=2;i*i<=n;i++) if(n%i==0) return false;
	return n>=2;
}
int main()
{
	scanf("%d%d",&L,&R);
	For(a,0,9) For(b,0,9) For(c,0,9) For(d,0,9) For(e,0,9)
	{
		if(d==0&&c==0&&b==0&&a==0&&e==9) hws[cnt++]=11;
		if(d==0&&c==0&&b==0&&a==0)	hws[cnt++]=e;
        else if(c==0&&b==0&&a==0)	hws[cnt++]=e*10+d*101;
        else if(b==0&&a==0)			hws[cnt++]=e*100+d*1010+c*10001;
        else if(a==0)				hws[cnt++]=e*1000+d*10100+c*100010+b*1000001;
        else						hws[cnt++]=e*10000
											   +d*101000+c*1000100+b*10000010
											   +a*100000001;
	}
	for(int i=0;i<cnt;i++)
		if(L<=hws[i]&&hws[i]<=R&&isp(hws[i])) printf("%d\n",hws[i]); 
	return 0;
}
