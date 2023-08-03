#include<cstdio>
using namespace std;
int hash_(char n)
{
	switch(n)
	{
		case 'A':return 0;
		case 'T':return 1;
		case 'G':return 2;
		case 'C':return 3;
	} 
}
char _hash(int n)
{
	switch(n)
	{
		case 0:return 'A';
		case 1:return 'T';
		case 2:return 'G';
		case 3:return 'C';
	}
}
int main()
{
	int pei[4]={1,0,3,2};
	char a;
	while(a=getchar(),a!='\n')
		printf("%c",_hash(pei[hash_(a)]));
	printf("\n");
	return 0;
}
