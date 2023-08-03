#include<cstdio> 
int main()
{
	int n;
	scanf("%d",&n);
	int sr[n];
	int fb[25];
	fb[0]=0;
	fb[1]=fb[2]=1;
	for(int i=3;i<25;i++) fb[i]=fb[i-1]+fb[i-2];
	for(int i=0;i<n;i++) scanf("%d",sr+i);
	for(int i=0;i<n;i++) printf("%d\n",fb[sr[i]]);
	return 0;
}
