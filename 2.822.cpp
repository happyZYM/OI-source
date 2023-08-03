#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct topic
{
    int tid,num,t0,t,dt,q_num,finished;
};
struct member
{
    int pid,k,work_left,last;
    vector<int>pidk;
    inline bool operator <(const member&a) const
    {
        if(a.last==last) return a.pid>pid;
        else return a.last>last;
    }
};
vector<topic> topics;
vector<member> staff;
int m,n,kase,time,need,z,i,j,k,x;
int main()
{
#ifdef local
    freopen("pro.in","r",stdin);
#endif
    while(scanf("%d",&m)==1&&m)
    {
        time=need=z=0;
        while(m--)
        {
            topic a;
            scanf("%d%d%d%d%d",&a.tid,&a.num,&a.t0,&a.t,&a.dt);
            a.q_num=a.finished=0;
            topics.push_back(a);
        }
        scanf("%d",&n);
        while(n--)
        {
            z++;
            member a;
            a.work_left=a.last=0;
            scanf("%d%d",&a.pid,&a.k);
            a.pid=z;
            for(i=0;i<a.k;i++)
            {
                scanf("%d",&x);
                a.pidk.push_back(x);
            }
            staff.push_back(a);
        }
        while(true)
        {
            for(i=0;i<topics.size();i++)
                if(time>=topics[i].t0
                    &&topics[i].finished+topics[i].q_num<topics[i].num)
                {
                    topics[i].t0+=topics[i].dt;
                    topics[i].q_num=
                        min(++topics[i].q_num,topics[i].num-topics[i].finished);
                }
            sort(staff.begin(),staff.end());
            for(i=0;i<staff.size();i++)
            {
                if(!staff[i].work_left)
                    for(j=0;j<staff[i].pidk.size();j++)
                        for(k=0;k<topics.size();k++)
                            if(staff[i].pidk[j]==topics[k].tid&&topics[k].q_num)
                            {
                                staff[i].last=time;
                                staff[i].work_left=topics[k].t;
                                topics[k].q_num--;
                                need=max(need,topics[k].t);
                                
                                if(++topics[k].finished==topics[k].num)
                                {
                                    topics.erase(topics.begin()+k);
                                    if(!topics.size())
                                    {
                                        time+=need;
                                        goto END;
                                    }
                                }
                                goto NEXT_P;
                            }
            NEXT_P:
                continue;
            }
            time++;
            need=max(--need,0);
            for(i=0;i<staff.size();i++)
                staff[i].work_left=max(--staff[i].work_left,0);
        }
    END:
        printf("Scenario %d: All requests are serviced within %d minutes.\n"
            ,++kase,time);
        staff.clear();
        topics.clear();
    }
    return 0;
}
