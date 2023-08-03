#include<cstdio>
#include<cstring>
char mp[1000][1000],buf[1000000];
inline void copy(int r,int c,int stp)
{
	for(int i=0;i<stp;i++) memcpy(mp[r+i]+c,mp[i],stp);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int n;
	while(scanf("%d",&n)==1&&n!=-1)
	{
		memset(mp,' ',sizeof(mp));
		if(n==1) { puts("X\n-"); continue; }
		mp[0][0]='X';
		int i=1,stp=1;
		for(;i<n;i++,stp*=3)
		{
			copy(0,stp*2,stp);
			copy(stp,stp,stp);
			copy(stp*2,0,stp);
			copy(stp*2,stp*2,stp);
		}
		for(int i=0;i<stp;i++) { mp[i][stp]=0; printf("%s\n",mp[i]); }
		puts("-");
	}
	return 0;
}
