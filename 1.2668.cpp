#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;
int T,n,res,cnt[25];
void dfs(int x)
{
	if(x>=res) return;
	//顺子
	int k=0;//单顺子
	for(int i=3;i<=14;i++)
	{
		if(cnt[i]==0) k=0;
		else
		{
			k++;
			if(k>=5)
			{
				for(int j=i;j>=i-k+1;j--) cnt[j]--;
				dfs(x+1);
				for(int j=i;j>=i-k+1;j--) cnt[j]++;
			}
		}
	}
	k=0;//双顺子
	for(int i=3;i<=14;i++)
	{
		if(cnt[i]<=1) k=0;
		else 
		{
			k++;
			if(k>=3)
			{
				for(int j=i;j>=i-k+1;j--) cnt[j]-=2;
				dfs(x+1);
				for(int j=i;j>=i-k+1;j--) cnt[j]+=2;
			}
		}
	}
	k=0;//三顺子
	for(int i=3;i<=14;i++)
	{
		if(cnt[i]<=2) k=0;
		else 
		{
			k++;
			if(k>=2)
			{
				for(int j=i;j>=i-k+1;j--) cnt[j]-=3;
				dfs(x+1);
				for(int j=i;j>=i-k+1;j--) cnt[j]+=3;
			}
		}
	}
	//带牌(3 or 4)
	for(int i=2;i<=14;i++)
	{
		if(cnt[i]<=3)
		{
			if(cnt[i]<=2) continue;
			cnt[i]-=3;
			for(int j=2;j<=15;j++)
			{
				if(cnt[j]<=0||j==i) continue;
				cnt[j]--;
				dfs(x+1);
				cnt[j]++;
			}
			for(int j=2;j<=14;j++)
			{
				if(cnt[j]<=1||j==i) continue;
				cnt[j]-=2;
				dfs(x+1);
				cnt[j]+=2;
			}
			cnt[i]+=3;
		} 
		else
		{
			cnt[i]-=3;
			for(int j=2;j<=15;j++)
			{
				if(cnt[j]<=0||j==i) continue;
				cnt[j]--;
				dfs(x+1);
				cnt[j]++;
			}
			for(int j=2;j<=14;j++)
			{
				if(cnt[j]<=1||j==i) continue;
				cnt[j]-=2;
				dfs(x+1);
				cnt[j]+=2;
			}
			cnt[i]+=3;

			cnt[i]-=4;
			for(int j=2;j<=15;j++)
			{
				if(cnt[j]<=0||j==i) continue;
				cnt[j]--;
				for (int k=2;k<=15;k++)
				{
					if(cnt[k]<=0||j==k) continue;
					cnt[k]--;
					dfs(x+1);
					cnt[k]++;
				}
				cnt[j]++;
			}
			for(int j=2;j<=14;j++)
			{
				if(cnt[j]<=1||j==i) continue;
				cnt[j]-=2;
				for(int k=2;k<=14;k++) 
				{
					if(cnt[k]<=1||j==k) continue;
					cnt[k]-=2;
					dfs(x+1);
					cnt[k]+=2;
				}
				cnt[j]+=2;
			}
			cnt[i]+=4;
		}
	}
	for(int i=2;i<=15;i++) if(cnt[i]) x++;
	res=min(res,x);
}
int main() 
{
	scanf("%d%d",&T,&n);
	while(T-->0)
	{
		res=n;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
		{
			int x,y; scanf("%d%d",&x,&y);
			if(x==0) cnt[15]++;
			else if(x==1) cnt[14]++;
			else cnt[x]++;
		}
		dfs(0);
		printf("%d\n",res);
	}
	return 0;
}
//#include<cstdio>
//#include<cstring>
//#include<string>
//#include<map> 
//#include<algorithm>
//using namespace std;
//struct Staute { int p[14],last;};
//Staute st;
//int T,n,res;
//map<string,int> s_i;
//int id[20],shunzi[20];
//inline int count(int n)
//{
//	n=(n&0x55555555)+((n>>1)&0x55555555);
//	n=(n&0x33333333)+((n>>2)&0x33333333);
//	n=(n&0x0f0f0f0f)+((n>>4)&0x0f0f0f0f);
//	n=(n&0x00ff00ff)+((n>>8)&0x00ff00ff);
//	n=(n&0x0000ffff)+((n>>16)&0x0000ffff);
//	return n;
//}
//void init()
//{
//	s_i["1"]=1;
//	s_i["2"]=2;
//	s_i["3"]=3;
//	s_i["4"]=4;
//	s_i["5"]=5;
//	s_i["6"]=6;
//	s_i["7"]=7;
//	s_i["8"]=8;
//	s_i["9"]=9;
//	s_i["10"]=10;
//	s_i["11"]=11;
//	s_i["12"]=12;
//	s_i["13"]=13;
//	s_i["0"]=0;
//	
//	id[3]=1;
//	id[4]=2;
//	id[5]=3;
//	id[6]=4;
//	id[7]=5;
//	id[8]=6;
//	id[9]=7;
//	id[10]=8;
//	id[11]=9;
//	id[12]=10;
//	id[13]=11;
//	id[1]=12;
//	id[2]=13;
//	id[0]=14;
//	for(int i=0;i<14;i++) shunzi[id[i]]=i;
//}
//void read()
//{
//	char s[100]; int co;
//	memset(&st,0,sizeof(st)); st.last=n;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%s%d",s,&co);
//		st.p[s_i[s]]|=1<<co;
//	}
//}
//namespace Defs
//{
//	const int have_ZhaDan=(1<<1)|(1<<2)|(1<<3)|(1<<4);
//	const int have_HuoJian=(1<<1)|(1<<2);
//}
//void dfs(int step);
//inline void ShunZi(int minlen,int times,int step,Staute &backup)
//{
//	int l,r;
//	l=1; while(l<=11&&count(st.p[shunzi[l]])<times) l++; r=l;
//	while(r<=11)
//	{
//		if(r-l+1>=minlen)
//		{
//			for(int i=l;i<=r;i++)
//			{
//				int &val=st.p[shunzi[i]];
//				for(int j=0;j<times;j++) val^=(val&-val);
//			}
//			st.last-=(r-l+1);
//			dfs(step+1);
//			st=backup;
//		}
//		if(count(st.p[shunzi[r+1]])>=times) r++;
//		else
//		{
//			r+=2; l=r;
//			while(l<=11&&count(st.p[shunzi[l]])<times) l++; r=l;
//		}
//	}
//}
//inline void Del(int &val,int times) { while(times-->0) val^=val&-val; }
//void dfs(int step)
//{
//	if(step>=res) return;
//	if(st.last==0) { res=step; return; }
//	res=min(res,step+st.last);
//	Staute backup=st;
//	
//	using namespace Defs;
//	//HuoJian
//	if((st.p[13]&have_HuoJian)==have_HuoJian)
//	{
//		st.p[13]^=have_HuoJian;
//		st.last-=2;
//		dfs(step+1);
//		st.p[13]^=have_HuoJian;
//		st.last+=2;
//	}
//	//ZhaDan & SiDaiEr
//	for(int i=0;i<14;i++)
//		if((st.p[i]&have_ZhaDan)==have_ZhaDan)
//		{
//			//ZhaDan
//			st.p[i]^=have_ZhaDan;
//			st.last-=4;
//			dfs(step+1);
//			st.p[i]^=have_ZhaDan;
//			st.last+=4;
//			//SiDaiEr
//			for(int j=0;j<14;j++)
//				if(i!=j&&st.p[j])
//					for(int k=0;k<14;k++)
//						if(i!=k&&j!=k&&st.p[k])
//						{
//							st.p[i]^=have_ZhaDan;
//							Del(st.p[j],1);
//							Del(st.p[k],1);
//							st.last-=6;
//							dfs(step+1);
//							st=backup;
//							if(count(st.p[j])>=2&&count(st.p[k])>=2)
//							{
//								st.p[i]^=have_ZhaDan;
//								Del(st.p[j],2);
//								Del(st.p[k],2);
//								st.last-=8;
//								dfs(step+1);
//								st=backup;
//							}
//						}
//		}
//	//DanPai
//	for(int i=0;i<14;i++)
//		if(st.p[i])
//		{
//			int x=st.p[i]&-st.p[i];
//			st.p[i]^=x;
//			st.last-=1;
//			dfs(step+1);
//			st.p[i]^=x;
//			st.last+=1;
//		}
//	//Duizi
//	for(int i=0;i<14;i++)
//		if(count(st.p[i])>=2)
//		{
//			Del(st.p[i],2);
//			st.last-=2;
//			dfs(step+1);
//			st=backup;
//		}
//	//SanZhangPai & SanDaiYi & SanDaiEr
//	for(int i=0;i<14;i++)
//		if(count(st.p[i])>=3)
//		{
//			//SanZhangPai
//			Del(st.p[i],3);
//			st.last-=3;
//			dfs(step+1);
//			st=backup;
//			//SanDaiYi
//			for(int k=0;k<14;k++)
//				if(i!=k&&st.p[k])
//				{
//					Del(st.p[i],3);
//					Del(st.p[k],1);
//					st.last-=4;
//					dfs(step+1);
//					st=backup;
//				}
//			//SanDaiEr
//			for(int k=0;k<14;k++)
//				if(i!=k)
//					if(count(st.p[k])>=2)
//					{
//						Del(st.p[i],3);
//						Del(st.p[k],1);
//						st.last-=5;
//						dfs(step+1);
//						st=backup;
//					}
//		}
//	//DanShunZi
//	ShunZi(5,1,step,backup);
//	//ShuangShunZi
//	ShunZi(3,2,step,backup);
//	//SanShunZi
//	ShunZi(2,3,step,backup);
//	
//	st=backup;
//}
//int main()
//{
//#ifdef local
//	freopen("pro.in","r",stdin);
//#endif
//	scanf("%d%d",&T,&n);
//	init();
//	while(T-->0)
//	{
//		read();
//		res=n;
//		dfs(0);
//		printf("%d\n",res);
//	}
//	return 0;
//}
