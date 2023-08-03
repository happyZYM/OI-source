// luogu-judger-enable-o2
#include<cstdio>
int n,m,res=1,now,x;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&x);
    	if(now+x>m) res++,now=x;
    	else now+=x;
    }
    printf("%d\n",res);
    return 0;
}
