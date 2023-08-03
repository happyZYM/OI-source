#include<bits/stdc++.h>
using namespace std;
struct Time
{
	int hour,minute;
};
struct Node
{
	string name;
	int room, bed;
	int top,tbk;
	int sop,sbk;
};
typedef pair<int,int> P;
typedef pair<P,int> Q;
const int INF=100000000;
vector<P> rooms,beds;
priority_queue<Q,vector<Q>,greater<Q>> patient;
vector<Node> names;
map<string,int> IDcache;
int n,m,T,t1,t2,t3,cnt;
int tot_time;
int used[45];
inline void clear()
{
	memset(used, 0, sizeof(used));
	names.clear();
	IDcache.clear();
	rooms.clear();
	beds.clear();
	while(!patient.empty()) patient.pop();
}
Time std_time(int m)
{
	int hour=m/60;
	int minute=m%60;
	Time u={hour+T,minute};
	return u;
}
void print()
{
	puts(" Patient          Operating Room          Recovery Room");
	puts(" #  Name     Room#  Begin   End      Bed#  Begin    End");
	puts(" ------------------------------------------------------");
	for(int i=0;i<cnt;i++)
	{
		Node&p = names[i];
		Time u1 = std_time(p.sop), u2 = std_time(p.sop + p.top), u3 = std_time(p.sbk), u4 = std_time(p.sbk + p.tbk);
		printf("%2d  %-9s %2d  %3d:%02d  %3d:%02d    %3d  %3d:%02d  %3d:%02d\n", i + 1, p.name.c_str(), p.room + 1, u1.hour, u1.minute, u2.hour, u2.minute, p.bed + 1, u3.hour, u3.minute, u4.hour, u4.minute);
	}
	cout << "\n";
	puts("Facility Utilization");
	puts("Type  # Minutes  % Used");
	puts("-------------------------");
	for(int i=0;i<n;i++)
	{
		double rate = 0.0;
		if (tot_time>0)
			rate = (double)used[i] * 100 / tot_time;
		printf("Room %2d %7d %7.2lf\n", i + 1, used[i], rate);
	}
	for(int i=0;i<m;i++)
	{
		double rate = 0.0;
		if (tot_time > 0)
			rate = (double)100 * used[i + n] / tot_time;
		printf("Bed  %2d %7d %7.2lf\n", i + 1, used[n + i], rate);
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d%d%d%d%d%d", &n, &m, &T, &t1, &t2, &t3, &cnt)==7)
	{
		clear();
		tot_time=0;
		for(int i=0;i<cnt;i++)
		{
			string s;
			int top,tbk;
			cin>>s>>top>>tbk;
			Node u={s,0,0,top,tbk,0,0};
			names.push_back(u);
		}
		int count = -1;
		for(int i=0;i<n;i++)
			rooms.push_back(P(0, i));//³õÊ¼»¯ËùÓÐÊÖÊõÊÒ
		priority_queue<int, vector<int>, greater<int> >tl1;
		vector<int> tmp;//ÔÝÊ±´æ·ÅÃ¿Î»²¡ÈË½øÈë»Ö¸´ÊÒµÄÊ±¼ä
		for(int i=0;i<n;i++)
			tl1.push(0);
		while (!tl1.empty())//µÚÒ»½×¶Î£ºÑ¡ÔñÊÖÊõÊÒ
		{
			if (++count == cnt)break;
			int now = tl1.top(); tl1.pop();//È¡³ö×îÐ¡µÄÊ±¿Ì
			vector<P>::iterator it = rooms.begin();
			for (it; it->first != now; it++);//ÕÒ±àºÅ×îÐ¡µÄ¿ÉÓÃÊÖÊõÊÒ
			int id = it->second;//ÊÖÊõÊÒ±àºÅ
			Node&person = names[count];
			person.sop = now;
			person.room = id;
			used[id] += person.top;
			int Next = now + person.top + t2;//¸ÃÊÖÊõÊÒÏÂÒ»´Î¿ÉÒÔ±»Ê¹ÓÃµÄÊ±¿Ì
			it->first = Next;
			person.sbk = Next - t2 + t1;//×ªÒÆµ½»Ö¸´ÊÒµÄÊ±¼ä
			patient.push(Q(P(person.sbk, id),count));//»ñµÃ½øÈë»Ö¸´ÊÒµÄ¶ÓÁÐ£¬Ö÷ÒªÒÀ¾ÝsbkÀ´ÅÅ¶Ó,´ÎÒªÒÀ¾ÝÊÖÊõÊÒ±àºÅÅÅÐò
			tl1.push(Next);
		}
		for(int i=0;i<m;i++) beds.push_back(P(0, i));//³õÊ¼»¯»Ö¸´ÊÒ
		while(!patient.empty())//µÚ¶þ½×¶Î£ºÑ¡Ôñ»Ö¸´ÊÒ
		{
			Q u = patient.top(); patient.pop();//µ±Ç°ÐèÒª°²ÅÅµÄ²¡ÈË
			P v = u.first;
			int now = v.first - t1;
			vector<P>::iterator it = beds.begin();
			for (it; it->first > now; it++);//²éÕÒ±àºÅ×îÐ¡µÄ¿ÉÓÃ»Ö¸´ÊÒ
			int id = it->second;//»Ö¸´ÊÒ±àºÅ
			Node&person = names[u.second];
			person.bed = id;
			used[id + n] += person.tbk;
			int Next = person.sbk + person.tbk + t3;//ÏÂÒ»´Î¿ÉÒÔ±»Ê¹ÓÃµÄÊ±¿Ì
			tot_time = max(tot_time, person.sbk + person.tbk);
			it->first = Next;
		}
		print();
		cout<<endl;
	}
	return 0;
}
