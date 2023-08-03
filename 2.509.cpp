#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=6500;
int d,s,b,n,kase;
char data[7][maxn];
bool parity;
bool read()
{
    scanf("%d%d%d\n",&d,&s,&b);
    if(!d) return false;
    memset(data,0,sizeof(data));
    parity=getchar()=='O',n=s*b;
    for(int i=0;i<d;++i)
        scanf("%s",data[i]);
    return true;
}
bool solve()
{
    for(int i;i<n;++i)
	{
        bool k=false;
        int broke=-1;
        for(int j=0;j<d;++j)
		{
            char& c=data[j][i];
            if(c=='1') k=!k;
            if(c=='x')
			{
                if(broke!=-1) return false;
                else broke=j;
            }
        }
        if(broke==-1&&k!=parity) return false;
        if(broke!=-1) data[broke][i]=k==parity?'0':'1';
    }
    return true;
}
void print(bool v)
{
    if(!v)
	{
		printf("invalid.\n");
		return;
	}
    printf("valid, contents are: ");
    int num=0,cnt=0,pos;
    for(int i=0;i<b;++i)
	{
        pos=i*s;
        for(int j=0;j<d;++j)
		{
            if(i%d==j) continue;
            for(int k=0;k<s;++k)
			{
                num<<=1,num+=data[j][pos+k]=='1',++cnt;
                if((cnt%=4)==0) printf("%X",num),num=0;
            }
        }
    }
    if(cnt) printf("%X",num<<(4-cnt));
    printf("\n");
    return;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    while(read())
	{
        printf("Disk set %d is ",++kase);
        print(solve());
    }
    return 0;
}
