#include<cstdio>
int n,x;
bool flag;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&x),flag|=x;
	if(flag) printf("HARD\n");
	else printf("EASY\n");
	return 0;
}
