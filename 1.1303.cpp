#include<iostream>
//main codes====================\/
#ifndef BIGINT
#define BIGINT
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
template<class T_queue>
struct Node_queue_for_bigint
{
	T_queue num;
	Node_queue_for_bigint *next;
	Node_queue_for_bigint()
	{
		next=0;
	}
};
template<class a_queue>
struct queue_for_bigint
{
	Node_queue_for_bigint<a_queue> *head,*tail,*L;
	bool isn;
	int SIZE_queue;
	void beginning()
	{
		head=tail=L=0;
		isn=0;
		head=tail=new Node_queue_for_bigint<a_queue>;
		tail->next=head;
		SIZE_queue=0;
		isn=1;
	}
	queue_for_bigint()
	{
		beginning();
	}
	~queue_for_bigint()
	{
		Node_queue_for_bigint<a_queue> *p=head,*tp;
		p=p->next;
		while(p!=head)
		{
			tp=p->next;
			delete p;
			p=tp;
		}
	}
	bool push(a_queue s)
	{
		SIZE_queue++;
		tail->num=s;
		if(tail->next==head)
		{
			tail->next=new Node_queue_for_bigint<a_queue>;
			tail->next->next=head;
			L=tail;
			tail=tail->next;
			return 1;
		}
		L=tail;
		tail=tail->next;
		return 0;
	}
	bool pop()
	{
		if(head==tail) return 1;
		head=head->next;
		SIZE_queue--;
		return 0;
	} 
	a_queue& front()
	{
		return head->num;
	} 
	a_queue& back()
	{
		return L->num;
	}
	int size()
	{
		return SIZE_queue;
	}
	void clear()
	{
		SIZE_queue=0;
		tail=head;
	}
	bool operator=(queue_for_bigint<a_queue>b)
	{
		if(!isn)
		{
			this->beginning();
			isn=1;
		}
		this->clear();
		Node_queue_for_bigint<a_queue> *p=b.head;
		while(p!=b.tail)
		{
			this->push(p->num);
			p=p->next;
		}
		return 0;
	}
};
int CacheSize=25;//try to use the cache
queue_for_bigint<char*> Mems;
queue_for_bigint<int> q;
queue_for_bigint<char> cache;
struct BigInt
{
	char f:4,nAn:4;
	std::vector<int> num;
	static const int base=100000000;
	BigInt()
	{
		f=0;
		nAn=0;
		num.push_back(0);
	}
	template<class TYPE>
	BigInt(TYPE V)
	{
		f=nAn=0;
		*this=V;
	}
	void format()
	{
		while(num.size()>1&&num[num.size()-1]<=0) num.erase(num.end()-1);
		if(num.size()==1&&num[0]==0) f=0;
		if(num.size()==0) num.push_back(0),f=nAn=0;
	}
	//Input and Output
	char* c_str()
	{
		char *p,*ptr;
		if(!nAn)
		{
			p=new char[num.size()*8+16];
			ptr=p;
			memset(p,0,num.size()*8+16);
			if(f) sprintf(p,"-"),p++;
			sprintf(p,"%d",num[num.size()-1]);
			for(int i=num.size()-2;i>=0;i--)
			{
				while(*p) p++;
				sprintf(p,"%08d",num[i]);
			}
		}
		else
		{
			p=new char[5];
			sprintf(p,"nan");
		}
		Mems.push(ptr);
		return ptr;
	}
	std::string str()
	{
		std::string ss=c_str();
		return ss;
	}
	BigInt operator=(char* s)
	{
		f=0;
		if(s==0) return BigInt();
		if(*s=='-')
		{
			f=1;
			s++;
		}
		int len=strlen(s),add=0,i,t;
		num.resize(len/8+1);
		char *p=s+len-1;
		while(p-7>=s)
		{
			t=0;
			for(i=-7;i<=0;i++)
				if(p+i>=s) t=t*10+*(p+i)-'0';
			p-=8;
			num[add++]=t;
		}
		if(p>=s)
		{
			t=0;
			while(s<=p) t=t*10+*(s++)-'0';
			num[add++]=t;
		}
		while(num.size()>add) num.erase(num.end()-1);
		return *this;
	}
	BigInt operator=(std::string ss)
	{
		char *s=&ss[0];
		f=0;
		if(s==0) return BigInt();
		if(*s=='-')
		{
			f=1;
			s++;
		}
		int len=strlen(s),add=0,i,t;
		num.resize(len/8+1);
		char *p=s+len-1;
		while(p>=s)
		{
			t=0;
			for(i=-7;i<=0;i++)
				if(p+i>=s) t=t*10+*(p+i)-'0';
			p-=8;
			num[add++]=t;
		}
		while(num.size()>add) num.erase(num.end()-1);
		return *this;
	}
	BigInt operator=(int v)
	{
		f=0;
		if(v<0)
		{
			f=1;
			v=-v;
		}
		q.clear();
		if(v==0) q.push(0);
		else
			while(v>0)
			{
				q.push(v%base);
				v/=base;
			}
		num.resize(q.size());
		for(int i=0;q.size()>0;i++)
		{
			num[i]=q.front();
			q.pop();
		}
		return *this;
	}
	BigInt operator=(unsigned int v)
	{
		f=0;
		q.clear();
		if(v==0) q.push(0);
		else
			while(v>0)
			{
				q.push(v%base);
				v/=base;
			}
		num.resize(q.size());
		for(int i=0;q.size()>0;i++)
		{
			num[i]=q.front();
			q.pop();
		}
		return *this;
	}
	BigInt operator=(long long v)
	{
		f=0;
		if(v<0)
		{
			f=1;
			v=-v;
		}
		q.clear();
		if(v==0) q.push(0);
		else
			while(v>0)
			{
				q.push(v%base);
				v/=base;
			}
		num.resize(q.size());
		for(int i=0;q.size()>0;i++)
		{
			num[i]=q.front();
			q.pop();
		}
		return *this;
	}
	BigInt operator=(unsigned long long v)
	{
		f=0;
		q.clear();
		if(v==0) q.push(0);
		else
			while(v>0)
			{
				q.push(v%base);
				v/=base;
			}
		num.resize(q.size());
		for(int i=0;q.size()>0;i++)
		{
			num[i]=q.front();
			q.pop();
		}
		return *this;
	}
	//====================/
	//In-situ operation
	BigInt operator++()
	{
		format();
		if(!f)
		{
			num[0]++;
			int i=1;
			while(i<num.size()&&num[i-1]>=base)
				num[i]++,num[i-1]-=base,i++;
			if(num[i-1]>=base)
				num.push_back(1),num[i-1]-=base;
		}
		else
		{
			num[0]--;
			int i=1;
			while(i<num.size()&&num[i-1]<0)
				num[i]--,num[i-1]+=base,i++;
			format();
		}
		return *this;
	}
	BigInt operator++(int)
	{
		format();
		BigInt t=*this;
		if(!f)
		{
			num[0]++;
			int i=1;
			while(i<num.size()&&num[i-1]>=base)
				num[i]++,num[i-1]-=base,i++;
			if(num[i-1]>=base)
				num.push_back(1),num[i-1]-=base;
		}
		else
		{
			num[0]--;
			int i=1;
			while(i<num.size()&&num[i-1]<0)
				num[i]--,num[i-1]+=base,i++;
			format();
		}
		return t;
	}
	BigInt operator--()
	{
		format();
		if(!f)
		{
			num[0]--;
			int i=1;
			while(i<num.size()&&num[i-1]<0)
				num[i]--,num[i-1]+=base,i++;
			if(num[i-1]<0)
				*this=-1;
			format();
		}
		else
		{
			num[0]++;
			int i=1;
			while(i<num.size()&&num[i-1]>=base)
				num[i]++,num[i-1]-=base,i++;
			if(num[i-1]>=base)
				num.push_back(1),num[i-1]-=base;
		}
		return *this;
	}
	BigInt operator--(int)
	{
		format();
		BigInt t=*this;
		if(!f)
		{
			num[0]--;
			int i=1;
			while(i<num.size()&&num[i-1]<0)
				num[i]--,num[i-1]+=base,i++;
			if(num[i-1]<0)
				*this=-1;
			format();
		}
		else
		{
			num[0]++;
			int i=1;
			while(i<num.size()&&num[i-1]>=base)
				num[i]++,num[i-1]-=base,i++;
			if(num[i-1]>=base)
				num.push_back(1),num[i-1]-=base;
		}
		return t;
	}
	//=====================/
};
//compare operations
bool operator<(BigInt a,BigInt b)
{
	a.format();
	b.format();
	if(a.f!=b.f) return a.f>b.f;
	if(a.f==0)
	{
		if(a.num.size()<b.num.size()) return 1;
		else if(a.num.size()>b.num.size()) return 0;
		for(int i=a.num.size()-1;i>=0;i--)
			if(a.num[i]<b.num[i]) return 1;
			else if(a.num[i]>b.num[i]) return 0;
	}
	else
	{
		if(a.num.size()>b.num.size()) return 1;
		else if(a.num.size()<b.num.size()) return 0;
		for(int i=a.num.size()-1;i>=0;i--)
			if(a.num[i]>b.num[i]) return 1;
			else if(a.num[i]<b.num[i]) return 0;
	}
	return 0;
}
bool operator==(BigInt a,BigInt b)
{
	a.format();
	b.format();
	if(a.f!=b.f) return 0;
	if(a.num.size()!=b.num.size()) return 0;
	for(int i=a.num.size()-1;i>=0;i--)
		if(a.num[i]!=b.num[i]) return 0;
	return 1;
}
bool operator!=(BigInt a,BigInt b)
{
	a.format();
	b.format();
	if(a.f!=b.f) return 1;
	if(a.num.size()!=b.num.size()) return 1;
	for(int i=a.num.size()-1;i>=0;i--)
		if(a.num[i]!=b.num[i]) return 1;
	return 0;
}
bool operator>(BigInt a,BigInt b)
{
	a.format();
	b.format();
	if(a.f!=b.f) return a.f<b.f;
	if(a.f==0)
	{
		if(a.num.size()>b.num.size()) return 1;
		else if(a.num.size()<b.num.size()) return 0;
		for(int i=a.num.size()-1;i>=0;i--)
			if(a.num[i]>b.num[i]) return 1;
			else if(a.num[i]<b.num[i]) return 0;
	}
	else
	{
		if(a.num.size()<b.num.size()) return 1;
		else if(a.num.size()>b.num.size()) return 0;
		for(int i=a.num.size()-1;i>=0;i--)
			if(a.num[i]<b.num[i]) return 1;
			else if(a.num[i]>b.num[i]) return 0;
	}
	return 0;
}
bool operator<=(const BigInt &a,const BigInt &b){return (a<b||a==b);}
bool operator>=(const BigInt &a,const BigInt &b){return (a>b||a==b);}
//=================/
//maths operations
BigInt operator+(BigInt a,BigInt b);
BigInt operator-(BigInt a,BigInt b);
BigInt operator*(BigInt a,BigInt b);
BigInt operator/(BigInt a,BigInt b);
void BigInt_add		(BigInt &a,BigInt &b,BigInt &c);
void BigInt_minus	(BigInt &a,BigInt &b,BigInt &c);
void BigInt_times	(BigInt &a,BigInt &b,BigInt &c);
void BigInt_divide	(BigInt &a,BigInt &b,BigInt &c);
void BigInt_add(BigInt &a,BigInt &b,BigInt &c)
{
	a.format();
	b.format();
	c.nAn=(a.nAn==1||b.nAn==1);
	if(c.nAn) return;
	if(a.f)
	{
		if(b.f)
		{
			a.f=b.f=0;
			BigInt_add(a,b,c);
			a.f=b.f=c.f=1;
			return;
		}
		else
		{
			a.f=0;
			BigInt_minus(b,a,c);
			a.f=1;
			return;
		}
	}
	else if(b.f)
	{
		b.f=0;
		BigInt_minus(a,b,c);
		b.f=1;
		return;
	}
	int t=0,t2=std::max(a.num.size(),b.num.size())+1;
	c.num.resize(t2);
	memset(&c.num[0],0,t2*4);
	for(int i=0;i<t2;i++)
	{
		if(i<a.num.size()) t+=a.num[i];
		if(i<b.num.size()) t+=b.num[i];
		c.num[i]=t%BigInt::base;
		t/=BigInt::base;
	}
	c.format();
}
void BigInt_minus(BigInt &a,BigInt &b,BigInt &c)
{
	a.format();
	b.format();
	c.nAn=(a.nAn==1||b.nAn==1);
	if(c.nAn) return;
	if(a.f)
	{
		if(b.f)
		{
			a.f=b.f=0;
			BigInt_minus(b,a,c);
			a.f=b.f=1;
			return;
		}
		else
		{
			a.f=0;
			BigInt_add(a,b,c);
			a.f=c.f=1;
			return;
		}
	}
	else if(b.f)
	{
		b.f=0;
		BigInt_add(a,b,c);
		b.f=1;
		return;
	}
	if(a<b)
	{
		BigInt_minus(b,a,c);
		c.f=1;
		return;
	}
	c=a;
	int z=0,k;
	for(int i=0;i<b.num.size();i++)
	{
		c.num[i]=c.num[i]-b.num[i];
		if(c.num[i]<0)
		{
			c.num[i]+=BigInt::base;
			z=1;
		}
		else z=0;
		k=i+1;
		while(z&&k<c.num.size())
		{
			c.num[k]--;
			if(c.num[k]<0)
			{
				z=1;
				c.num[k]+BigInt::base;
			}
			else z=0;
			k++;
		}
	}
	c.format();
}
void BigInt_times(BigInt &a,BigInt &b,BigInt &c)
{
	a.format();
	b.format();
	c.nAn=(a.nAn==1||b.nAn==1);
	if(c.nAn) return;
	c.num.resize(a.num.size()+b.num.size());
	memset(&c.num[0],0,(a.num.size()+b.num.size())*4);
	int i,j,k,I,J;
	long long t;
	int *A,*B,*C,As=a.num.size(),Bs=b.num.size();
	A=&(a.num[0]);
	B=&(b.num[0]);
	C=&(c.num[0]);
	for(i=0;i<As;i+=CacheSize)
		for(j=0;j<Bs;j+=CacheSize)
			for(I=i;I<i+CacheSize&&I<As;I++)
				for(J=j;J<j+CacheSize&&J<Bs;J++)
				{
					t=(long long)A[I]*B[J];
					t=t+C[I+J];
					C[I+J]=t%BigInt::base;
					k=I+J+1;
					t/=BigInt::base;
					while(t>0)
					{
						t=t+C[k];
						C[k++]=t%BigInt::base;
						t=t/BigInt::base;
					}
				}
	c.f=(a.f!=b.f);
	c.format();
}
void BigInt_divide(BigInt &a,BigInt &b,BigInt &c)
{
	BigInt t;
	a.format();
	b.format();
	bool af=a.f,bf=b.f;
	a.f=b.f=0;
	if(a<b)
	{
		c=BigInt();
		return;
	}
	c.nAn=(a.nAn==1||b.nAn==1||(b.num.size()==1&&b.num[0]==0));
	c.f=0;
	if(c.nAn) return;
	c.num.resize(a.num.size()-b.num.size()+1,0);
	int L,R;
	for(int i=c.num.size()-1;i>=0;i--)
	{
		L=0;
		R=a.base-1;
		while(L+1<R)
		{
			c.num[i]=(L+R)/2;
			BigInt_times(b,c,t);
			if(t>a) R=(L+R)/2;
			else L=(L+R)/2;
		}
		c.num[i]=L;
	}
	c.format();
	a.f=af;
	b.f=bf;
	c.f=(af!=bf);
}
BigInt operator+(BigInt a,BigInt b)
{
	BigInt t;
	BigInt_add(a,b,t);
	return t;
}
BigInt operator+=(BigInt &a,BigInt b)
{
	BigInt t;
	BigInt_add(a,b,t);
	return a=t;
}
BigInt operator-(BigInt a,BigInt b)
{
	BigInt t;
	BigInt_minus(a,b,t);
	return t;
}
BigInt operator-=(BigInt &a,BigInt b)
{
	BigInt t;
	BigInt_minus(a,b,t);
	return a=t;
}
BigInt operator*(BigInt a,BigInt b)
{
	BigInt t;
	BigInt_times(a,b,t);
	return t;
}
BigInt operator*=(BigInt &a,BigInt b)
{
	BigInt t;
	BigInt_times(a,b,t);
	return a=t;
}
BigInt operator/(BigInt a,BigInt b)
{
	BigInt c;
	BigInt_divide(a,b,c);
	return c;
}
BigInt operator/=(BigInt &a,BigInt b)
{
	BigInt c;
	BigInt_divide(a,b,c);
	return a=c;
}
BigInt operator%(BigInt a,BigInt b)
{
	BigInt t1,t2;
	BigInt_divide(a,b,t1);
	BigInt_times(t1,b,t2);
	BigInt_minus(a,t2,t1);
	return t1;
}
BigInt operator%=(BigInt &a,BigInt b)
{
	BigInt t1,t2;
	BigInt_divide(a,b,t1);
	BigInt_times(t1,b,t2);
	BigInt_minus(a,t2,t1);
	return a=t1;
}
void free_pointers()//Releasing temporary memory
{
	while(Mems.size()>0)
	{
		delete[] Mems.front();
		Mems.pop();
	}
}
//======================/
int read(BigInt &n,FILE *stream=stdin)
{
	cache.clear();
	char t;
	while(!feof(stream))
	{
		fread(&t,1,1,stream);
		if(t=='-'||(t>='0'&&t<='9'))
		{
			ungetc(t,stream);
			break;
		}
	}
	bool flag=0;
	while(!feof(stream))
	{
		fread(&t,1,1,stream);
		if(t!='-')
		{
			ungetc(t,stream);
			break;
		}
		flag=!flag;
	}
	if(flag) cache.push('-');
	while(!feof(stream))
	{
		fread(&t,1,1,stream);
		if(t<'0'||t>'9')
		{
			ungetc(t,stream);
			break;
		}
		cache.push(t);
	}
	char *p=new char[cache.size()+1],*tp;
	memset(p,0,cache.size()+1);
	tp=p;
	while(cache.size()>0) *tp++=cache.front(),cache.pop();
	n=p;
	delete[] p;
}
int write(BigInt n,FILE *stream=stdout)
{
	n.format();
	if(n.nAn) fprintf(stream,"nan");
	else
	{
		if(n.f) fprintf(stream,"-");
		fprintf(stream,"%d",n.num[n.num.size()-1]);
		for(int i=n.num.size()-2;i>=0;i--)
			fprintf(stream,"%08d",n.num[i]);
	}
}
#endif

//stream input and output
#ifdef _GLIBCXX_OSTREAM
std::ostream& operator<<(std::ostream& str,BigInt n)
{
	n.format();
	if(n.nAn) str<<"nan";
	else
		str<<n.c_str();
	return str;
}
#endif

#ifdef _GLIBCXX_ISTREAM
std::istream& operator>>(std::istream& str,BigInt &n)
{
	cache.clear();
	while(!str.eof()&&!(str.peek()=='-'||(str.peek()>='0'&&str.peek()<='9')))
		str.get();
	bool flag=0;
	while(!str.eof()&&str.peek()=='-') flag=!flag,str.get();
	if(flag) cache.push('-');
	while(!str.eof()&&str.peek()>='0'&&str.peek()<='9') cache.push(str.get());
	char *p=new char[cache.size()+1],*t;
	memset(p,0,cache.size()+1);
	t=p;
	while(cache.size()>0) *t++=cache.front(),cache.pop();
	n=p;
	delete[] p;
	return str;
}
#endif
using namespace std;
int main()
{
	BigInt a,b;
	cin>>a>>b;
	cout<<a*b<<endl;
	return 0;
}
/*
512013230123048014584016540526804565814706519846494321001345794503242112976563432120
5120132301230048014584016540526804565814706519846494321001345794503242112976563432120
*/
