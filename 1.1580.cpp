#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MaxSize=1005;
int idx=0;
char s[MaxSize],name[MaxSize],importer[MaxSize],t[MaxSize];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif 
    gets(s);
    sscanf(strstr(s,"@"),"@yyy loves %s",name);
    while(++idx)
	{
        gets(s);
        int len=strlen(s);
        if(len==1) break;
        sscanf(s,"yyy loves %s",importer);
        if(!strcmp(importer,name))
		{
            printf("Successful @yyy loves %s attempt\n",name);
            return 0;
        }
        if(count(s,s+len,'@')!=1
			||(sscanf(strstr(s,"@"),"@yyy loves %s",t),strcmp(t,name)))
		{
            printf("Unsuccessful @yyy loves %s attempt\n", name);
            printf("%d\n",idx+1);
            printf("yyy loves %s\n",importer);
            return 0;
        }
    }
    printf("Unsuccessful @yyy loves %s attempt\n",name);
    printf("%d\n",idx);
    printf("Good Queue Shape\n");
    return 0;
}
