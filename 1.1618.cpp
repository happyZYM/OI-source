#include<cstdio>
int a,b,c;
int check(int x,int y,int z)
{
	if(x<100||x>=1000||y<100||y>=1000||z<100||z>=1000) return false;
	int hsh[10]={0};
	while(x>0) hsh[x%10]++,x/=10;
	while(y>0) hsh[y%10]++,y/=10;
	while(z>0) hsh[z%10]++,z/=10;
	for(int i=1;i<=9;i++) if(hsh[i]!=1) return false;
	return true;
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	bool flag=true;
	for(int i=100;i<1000;i++)
	{
		int x=i,y=i*b/a,z=y*c/b;
		if(x*b==a*y&&y*c==z*b&&check(x,y,z)) printf("%d %d %d\n",x,y,z),flag=false;
	}
	if(flag) puts("No!!!");
	return 0;
}
