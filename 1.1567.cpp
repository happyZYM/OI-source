#include<cstdio>
int main()
{
    int last,x,cnt=1,res=1,n;
    scanf("%d%d",&n,&last);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&x);
        if(last<x) cnt++;
        else
        {
            if(cnt>res) res=cnt;
            cnt=1;
        }
        last=x;
    }
    if(cnt>res) res=cnt;
    printf("%d\n",res);
    return 0;
}
