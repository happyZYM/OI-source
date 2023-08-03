#include<bits/stdc++.h>
using namespace std;
const string type[34]=
{
	"1T", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T",
	"1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S",
	"1W", "2W", "3W", "4W", "5W", "6W", "7W", "8W", "9W",
	"DONG", "NAN", "XI", "BEI", "ZHONG", "FA", "BAI"
};
map<string,int> id;
char s[10];
vector<string> mahjong,finish;
vector<string> temp;
int cnt[34];
bool cmp(const string &s1,const string &s2)
{ return id[s1]<id[s2]; }
bool DFS()
{
	if(temp.size()==0) return true;
	if(temp[0]==temp[1]&&temp[0]==temp[2])
	{
		temp.erase(temp.begin(),temp.begin()+3);
		return DFS();
	}
	if(temp[0][0]<'1'||temp[0][0]>'7') return false;
	int pos1=-1,pos2=-1;
	for(int i=0;i<temp.size();i++)
	{
		if(id[temp[i]]==id[temp[0]]+1) pos1=i;
		if(id[temp[i]]==id[temp[0]]+2) pos2 = i;
	}
	if(pos1==-1||pos2==-1) return false;
	temp.erase(temp.begin()+pos2);
	temp.erase(temp.begin()+pos1);
	temp.erase(temp.begin());
	return DFS();
}
bool judge(int x)
{
	finish.clear();
	finish.push_back(type[x]);
	for(int i=0;i<mahjong.size();i++)
		finish.push_back(mahjong[i]);
	sort(finish.begin(),finish.end(),cmp);
	int i=0;
	while(i<finish.size())
	{
		bool flag=false;
		while(i+1<finish.size()&&finish[i]==finish[i+1])
		{
			flag=true;
			i++;
		}
		if(flag)
		{
			temp.clear();
			for(int j=0;j<finish.size();j++)
				if(j<i-1||j>i) temp.push_back(finish[j]);
			if(DFS()) return true;
		}
		i++;
	}
	return false;
}
void input()
{
	mahjong.clear();
	mahjong.push_back(s);
	memset(cnt,0,sizeof(cnt));
	cnt[id[s]]++;
	for(int i=1;i<13;i++)
	{
		scanf("%s",s);
		mahjong.push_back(s);
		cnt[id[s]]++;
	}
}
void solve()
{
	bool ans=false;
	for(int i=0;i<34;i++)
	{
		if(cnt[i]<4&&judge(i))
		{
			if(ans) printf(" ");
			else ans=true;
			printf("%s",type[i].begin());
		}
	}
	if(!ans) printf("Not ready");
	printf("\n");
}
int Case;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	for(int i=0;i<34;i++) id[type[i]]=i;
	while(scanf("%s",s)&&s[0]!='0')
	{
		input();
		printf("Case %d: ",++Case);
		solve();
	}
	return 0;
}
