#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;

int degree[10055]; //记录每一个顶点的度数 
int color[10055];  //记录每一个顶点的颜色 
int maxDegree; //记录最大度数 


/************
图论常用： 链式向前星 -->邻接表记录 图结构 
***********/
int head[10055];  
struct e{
    int v , nxt;
}edge[200505]; 
int Ecnt;

void addEdge(int u , int v){
    edge[Ecnt].v = v;
    edge[Ecnt].nxt = head[u];
    head[u]=Ecnt++;
}


int colorUsed[10005];//该颜色是否被相邻的顶点用过 
int used[10055]; //该顶点是否 进入过队列 


void BFS(int src){
    queue<int> q;
    q.push(src);

    memset(used , 0 ,sizeof(used));
    used[src] =1;

    while(!q.empty()){
        int index = q.front();
        q.pop();    
        memset(colorUsed , 0 , sizeof(colorUsed));

        for(int i=head[index] ; i!=-1 ; i=edge[i].nxt){
            int v = edge[i].v;

            if(color[v]!=-1) {  //记录下 周围顶点已经 用过的颜色          
                colorUsed[color[v]]=1;          
            }else if(used[v] == 0){ //若 周围顶点未进入过 队列 则入队 
                    used[v] = 1;
                    q.push(v);
            }
        }

        int j;
        for(j=1 ;j<=maxDegree ; ++j){//用最小的 未被用过颜色 来涂当前顶点 
            if(!colorUsed[j]){
                color[index] = j;
                break;
            }
        }
    }
}

//初始化 
void Init(){
    Ecnt = 0 ;
    maxDegree = 0;
    memset(head , -1 , sizeof(head));
    memset(degree , 0 ,sizeof(degree)); 
    memset(color , -1 ,sizeof(color));
}


int main(){
    bool first = true;
    int n, m;
    while(scanf("%d %d",&n , &m)!=EOF){ 

        Init();
        if (first)
           first = false;
        else
             printf("\n");

        int u ,v;
        for(int i=0 ; i<m ; ++i){
            scanf("%d %d",&u,&v);
            if(u == v) continue;
            addEdge(u,v);
            addEdge(v,u);
            degree[u]++;
            degree[v]++;
        }   
        for(int i=1 ;i<=n ; ++i){
            if(maxDegree < degree[i]){
                maxDegree = degree[i];
            }
        }

        if(maxDegree%2 == 0) maxDegree++;

        BFS(1);

        printf("%d\n",maxDegree);

        for(int i=1 ;i<=n ;++i)
            printf("%d\n",color[i]);        
    }

    return 0;
}
