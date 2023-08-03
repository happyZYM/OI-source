#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,pl[105],cnt[2100],F[105][70][70];
vector<int> S;
inline bool check(int i)
{
	while(i)
	{
		if(cnt[i&7]>1) return 0;
		i>>=1;
	}
	return 1;
}
inline bool valid(int i,int x) { return (x&pl[i])==0; }
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	// freopen("pro.out","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c;
		for(int j=0;j<m;j++)
		{
			cin>>c;
			pl[i]=(pl[i]<<1)+(c=='H');
		}
	}
	for(int i=0;i<(1<<m);i++) { cnt[i<<1]=cnt[i]; cnt[i<<1|1]=cnt[i]+1; }
	for(int i=0;i<(1<<m);i++) if(check(i)) S.push_back(i);
	// for(int i=0;i<S.size();i++) printf("%d ",S[i]); puts("");
	memset(F,-1,sizeof(F));
	F[0][0][0]=0; int res=0;
	for(int i=0;i<S.size();i++) if(valid(1,S[i]))
	{
		F[1][i][0]=cnt[S[i]];
		res=max(res,cnt[S[i]]);
	}
	// printf("res=%d\n",res);
	for(int i=2;i<=n;i++)
		for(int j=0;j<S.size();j++)
		{
			// printf("valid(%d,%d)=%d\n",i,S[j],valid(i,S[j]));
			if(valid(i,S[j]))
				for(int k=0;k<S.size();k++)
				{
					// printf("\tvalid(%d,%d)==%d\n",i-1,S[k],valid(i-1,S[k]));
					// printf("\t%d&%d=%d\n",S[j],S[k],S[j]&S[k]);
					// printf("\t%d\n",(valid(i-1,S[k])&&(S[j]&S[k])==0));
					if(valid(i-1,S[k])&&(S[j]&S[k])==0)
					{
						// printf("\t\ti=%d j=%d k=%d\n",i,S[j],S[k]);
						for(int l=0;l<S.size();l++) if((S[j]&S[l])==0&&valid(i-2,S[l])&&F[i-1][k][l]!=-1)
							F[i][j][k]=max(F[i][j][k],F[i-1][k][l]+cnt[S[j]]);
					}
				}
		}
	for(int j=0;j<S.size();j++) for(int k=0;k<S.size();k++)
		if((S[j]&S[k])==0&&valid(n,S[j])&&valid(n-1,S[k])) res=max(res,F[n][j][k]);
	cout<<res<<endl;
	return 0;
}