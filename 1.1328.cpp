#include<cstdio>
const int maxn=210;
int n,na,nb,cnta,cntb,a[maxn],b[maxn];
int tb[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int main()
{
    scanf("%d%d%d",&n,&na,&nb);
    for(int i=0;i<na;i++) scanf("%d",&a[i]);
    for(int i=0;i<nb;i++) scanf("%d",&b[i]);
    for(int i=0;i<n;i++)
    {
        cnta+=tb[a[i%na]][b[i%nb]]; 
        cntb+=tb[b[i%nb]][a[i%na]];
    }
    printf("%d %d\n",cnta,cntb);
    return 0;
}
