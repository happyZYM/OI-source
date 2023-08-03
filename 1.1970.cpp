#include<cstdio>
int n,h[1000005],res=1,st;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    if(h[2]>=h[1]) st=1;
    for(int i=1;i<=n;i++)
    {
        if(st==0&&i==n) { res++; break; }
        if(st==1) if(h[i+1]<h[i]) { res++; st=0; continue; }
        if(st==0) if(h[i+1]>h[i]) { res++; st=1; continue; }
    }
    printf("%d\n",res);
    return 0;
}
