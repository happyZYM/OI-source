#include<cstdio>
#include<cstring>
#define maxn 100000
struct node
{
	int id;
	long long step;
};
int *tu[maxn+1],num[maxn+1],n,p,c,i,j,a,b,head,tail;
long long m;
node queue[maxn+5];
char mem[maxn/8+5];
bool r(int idx)
{
	return mem[idx/8]&(1<<(idx%8));
}
int w(int idx,int v)
{
	mem[idx/8]&=~(1<<(idx%8));
	mem[idx/8]|=1<<(idx%8);
	return v;
}
inline char get()
{
	static char ch;
	fread(&ch,1,1,stdin);
	return ch;
}
inline long long read()
{
	static long long a;
	static char ch;
	a=0;
	while(ch=get(),!(ch>='0'&&ch<='9'));
	a=ch-'0';
	while(ch=get(),ch>='0'&&ch<='9') a=a*10+ch-'0';
	return a;
}
int main()
{
	freopen("candy.in","rb",stdin);
	freopen("candy.out","w",stdout);
	n=read();p=read();c=read();
	m=read();
	for(i=0;i<p;i++)
	{
		a=read();b=read();
		num[a]++;
		num[b]++;
	}
	freopen("candy.in","rb",stdin);
	for(i=1;i<=n;i++) tu[i]=new int[num[i]];
	n=read();p=read();c=read();
	m=read();
	memset(num,0,sizeof(num));
	for(i=0;i<p;i++)
	{
		a=read();b=read();
		tu[a][num[a]++]=b;
		tu[b][num[b]++]=a;
	}
	node t,t2;
	t.id=c;
	t.step=1;
	queue[tail++]=t;
	w(c,1);
	while(head<tail)
	{
		t=queue[head++];
		for(i=0;i<num[t.id];i++)
			if(!r(tu[t.id][i]))
			{
				queue[tail].id=tu[t.id][i];
				queue[tail].step=t.step+1;
				w(queue[tail++].id,1);
			}
	}
	printf("%lld\n",queue[tail-1].step+m);
	return 0;
}
