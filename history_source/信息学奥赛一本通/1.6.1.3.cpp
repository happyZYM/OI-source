#include<cstdio>
using namespace std;
struct string
{
	char s[10];
	int len=0;
};
struct persons
{
	string name;
	double t;
	bool k;
};
int main()
{
	int n;
	char w;
	scanf("%d",&n);
	persons person[n];
	for(int i=0;i<n;i++)
	{
		w=getchar();
		while(w=getchar(),w!=' ') person[i].name.s[person[i].name.len++]=w;
		scanf("%lf",&person[i].t);
		scanf("%d",&person[i].k);
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(person[i].k&&person[i].t>=37.5)
		{
			sum++;
			for(int j=0;j<person[i].name.len;j++)
				printf("%c",person[i].name.s[j]);
			printf("\n");
		}
	}
	printf("%d\n",sum);
	return 0;
}

