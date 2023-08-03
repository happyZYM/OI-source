#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct CARD {char Face[2];} Src;
typedef vector<CARD> PILE;
inline bool Match(const CARD &c1, const CARD &c2)
{
    return (c1.Face[0]==c2.Face[0]||c1.Face[1]==c2.Face[1]);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    char Pack[256];
    for(string Line;getline(cin, Line)&&Line[0]!='#';cout<<endl)
	{
	    strcpy(Pack,Line.c_str());
	    while(getline(cin,Line)&&Line.empty());
	    	strcat(Pack,Line.c_str());
		*remove(&Pack[0],&Pack[strlen(Pack)],' ')='\0';
	    vector<PILE> Piles;
	    for(int i=0;i<52;++i)
		{
		    PILE Stack(1,((CARD*)&Pack)[i]);
		    Piles.push_back(Stack);
		    for(size_t j=Piles.size()-1,k;j<Piles.size();++j)
			{
			    for(k=j,Src=Piles[j].back();k>0;--k)
				{
				    if(k>=3)
					{
					    if(Match(Src, Piles[k-3].back()))
						{
						    k-=2;
						    continue;
						}
					}
				    if(!Match(Src,Piles[k-1].back()))
					    break;
				}
			    if(k!=j)
				{
				    Piles[k].push_back(Piles[j].back());
				    Piles[j].pop_back();
				    if (Piles[j].empty())
					    Piles.erase(Piles.begin()+j);
				    j=k;
				}
			}
		}
	    int nSize=Piles.size();
	    cout<<nSize<<" pile"<<(nSize>1?"s ":" ")<<"remaining:";
	    for(int i=0;i<nSize;i++)
			cout<<' '<<Piles[i].size();
	}
    return 0;
}
