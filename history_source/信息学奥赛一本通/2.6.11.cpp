#include<cstdio>
int main()
{
	int i,j,minidx,t,people,water;
	scanf("%d%d",&people,&water);
	int queue[water]={0};
	for(i=0;i<people;i++)
	{
		scanf("%d",&t);
		minidx=0;
		for(j=1;j<water;j++) if(queue[j]<queue[minidx]) minidx=j;
		queue[minidx]+=t;
	}
	int ans=queue[0];
	for(i=1;i<water;i++) if(queue[i]>ans) ans=queue[i];
	printf("%d\n",ans);
	return 0;
}
