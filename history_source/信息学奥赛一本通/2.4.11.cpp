#include<cstdio>
int s[20][6],h[20];//s[i][] i=sum{2^s[i][1~...]}
void print(int k)
{
	if(!k) {printf("0");return;}
	for(int i=1;i<=h[k];i++)
	{
		if(i!=1) printf("+");
		if(s[k][i]==1) {printf("2");continue;}
		printf("2(");
		print(s[k][i]);
		printf(")");
	}
}
void init(int x,int id)
{
	h[id]=0;
	int t=0;
	while(x)
	{
		if(x&1) s[id][++h[id]]=t;
		x/=2,t++;
	}
	for(int i=1;i<=h[id]/2;i++)
	{
		t=s[id][i];
		s[id][i]=s[id][h[id]-i+1];
		s[id][h[id]-i+1]=t;
	}
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=16;i++) init(i,i);
    init(n,17);
    print(17);
    return 0;
}
