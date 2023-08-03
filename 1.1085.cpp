#include<cstdio>
int a[8],b[8];
int main()
{
    for(int i=1;i<=7;i++) scanf("%d%d",a+i,b+i);
    int res=0;
    for(int i=1;i<=7;i++)
    	if(a[i]+b[i]>8&&a[i]+b[i]>a[res]+b[res]) res=i;
    printf("%d\n",res);
    return 0;
}
