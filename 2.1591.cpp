#include<cstdio>
#include<cstring>
const int MAXN=31;
long long N,K,temp;
int Sp,Sq,minA,minB,A,B;
bool first;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    while(scanf("%d%d%d",&N,&Sp,&Sq)==3)
	{
        first=true;
        minA=minB=0;
        for(A=0;A<=MAXN;A++)
		{
            for(B=0;B<=MAXN;B++)
			{
                temp=0;
                temp=(((N-1)*Sp+(((N-1)*Sp)<<A))>>B)+Sq;  
                if(temp<Sq*N) break;
                if(first)
				{
					K=temp;
					minA=A;
					minB=B;
					first=false;
				}
                else if(K>temp)
				{
                    K=temp;
                    minA=A;
                    minB=B;
                }
            }
        }
        printf("%lld %d %d\n",K,minA,minB);
    }
    return 0;
}
