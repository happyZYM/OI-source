#include<iostream>
#include<string>
using namespace std;
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
	inline void format()
	{
		while(num.size()>1&&num[num.size()-1]<=0) num.erase(num.end()-1);
		if(num.size()==1&&num[0]==0) f=0;
		if(num.size()==0) num.push_back(0),f=nAn=0;
	}
	//Input and Output
	inline char* c_str(bool mode=1)
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
		if(mode) Mems.push(ptr);
		return ptr;
	}
	inline std::string str()
	{
		char *p=c_str(0);
		std::string ss=p;
		delete[] p;
		return ss;
	}
	inline BigInt operator=(char* s)
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
	inline BigInt operator=(std::string ss)
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
	inline BigInt operator=(int v)
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
	inline BigInt operator=(unsigned int v)
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
	inline BigInt operator=(long long v)
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
	inline BigInt operator=(unsigned long long v)
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
	inline BigInt operator++()
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
	inline BigInt operator++(int)
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
	inline BigInt operator--()
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
	inline BigInt operator--(int)
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
inline bool operator<(BigInt a,BigInt b)
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
inline bool operator==(BigInt a,BigInt b)
{
	a.format();
	b.format();
	if(a.f!=b.f) return 0;
	if(a.num.size()!=b.num.size()) return 0;
	for(int i=a.num.size()-1;i>=0;i--)
		if(a.num[i]!=b.num[i]) return 0;
	return 1;
}
inline bool operator!=(BigInt a,BigInt b)
{
	a.format();
	b.format();
	if(a.f!=b.f) return 1;
	if(a.num.size()!=b.num.size()) return 1;
	for(int i=a.num.size()-1;i>=0;i--)
		if(a.num[i]!=b.num[i]) return 1;
	return 0;
}
inline bool operator>(BigInt a,BigInt b)
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
inline bool operator<=(const BigInt &a,const BigInt &b){return (a<b||a==b);}
inline bool operator>=(const BigInt &a,const BigInt &b){return (a>b||a==b);}
//=================/
//maths operations
#if __cplusplus >= 201103L
inline BigInt operator+(BigInt  &a,BigInt  &b);
inline BigInt operator+(BigInt &&a,BigInt  &b);
inline BigInt operator+(BigInt  &a,BigInt &&b);
inline BigInt operator+(BigInt &&a,BigInt &&b);
inline BigInt operator-(BigInt  &a,BigInt  &b);
inline BigInt operator-(BigInt &&a,BigInt  &b);
inline BigInt operator-(BigInt  &a,BigInt &&b);
inline BigInt operator-(BigInt &&a,BigInt &&b);
inline BigInt operator*(BigInt  &a,BigInt  &b);
inline BigInt operator*(BigInt &&a,BigInt  &b);
inline BigInt operator*(BigInt  &a,BigInt &&b);
inline BigInt operator*(BigInt &&a,BigInt &&b);
inline BigInt operator/(BigInt  &a,BigInt  &b);
inline BigInt operator/(BigInt &&a,BigInt  &b);
inline BigInt operator/(BigInt  &a,BigInt &&b);
inline BigInt operator/(BigInt &&a,BigInt &&b);
inline BigInt operator%(BigInt  &a,BigInt  &b);
inline BigInt operator%(BigInt &&a,BigInt  &b);
inline BigInt operator%(BigInt  &a,BigInt &&b);
inline BigInt operator%(BigInt &&a,BigInt &&b);
inline BigInt operator+=(BigInt &a,BigInt  &b);
inline BigInt operator+=(BigInt &a,BigInt &&b);
inline BigInt operator-=(BigInt &a,BigInt  &b);
inline BigInt operator-=(BigInt &a,BigInt &&b);
inline BigInt operator*=(BigInt &a,BigInt  &b);
inline BigInt operator*=(BigInt &a,BigInt &&b);
inline BigInt operator/=(BigInt &a,BigInt  &b);
inline BigInt operator/=(BigInt &a,BigInt &&b);
inline BigInt operator%=(BigInt &a,BigInt  &b);
inline BigInt operator%=(BigInt &a,BigInt &&b);
#else
inline BigInt operator+(BigInt a,BigInt b);
inline BigInt operator-(BigInt a,BigInt b);
inline BigInt operator*(BigInt a,BigInt b);
inline BigInt operator/(BigInt a,BigInt b);
inline BigInt operator%(BigInt a,BigInt b);
inline BigInt operator+=(BigInt &a,BigInt b);
inline BigInt operator-=(BigInt &a,BigInt b);
inline BigInt operator*=(BigInt &a,BigInt b);
inline BigInt operator/=(BigInt &a,BigInt b);
inline BigInt operator%=(BigInt &a,BigInt b);
#endif
void BigInt_add		(BigInt &a,BigInt &b,BigInt &c);
void BigInt_minus	(BigInt &a,BigInt &b,BigInt &c);
inline void BigInt_times	(BigInt &a,BigInt &b,BigInt &c);
inline void BigInt_divide	(BigInt &a,BigInt &b,BigInt &c);

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
const double pi=acos(-1.0);
struct complex
{
	double r,i;
	inline complex(double real=0.0,double image=0.0)
	{
		r=real;	i=image;
	}
	inline complex operator+(const complex &o)
	{
		return complex(r+o.r,i+o.i);
	}
	inline complex operator-(const complex &o)
	{
		return complex(r-o.r,i-o.i);
	}
	inline complex operator*(const complex &o)
	{
		return complex(r*o.r-i*o.i,r*o.i+i*o.r);
	}
};
void brc(complex *y,int l)
{
	int i,j,k;
	for(i=1,j=l/2;i<l-1;++i)
	{
		if(i<j)	std::swap(y[i],y[j]);
		k=l/2;
		while(j>=k)
		{
			j-=k;
			k>>=1;
		}
		if(j<k)	j+=k;
	}
}
void fft(complex *y,int l,double on)
{
	int h,i,j,k;
	complex u,t; 
	brc(y,l);
	for(h=2;h<=l;h<<=1)
	{
		complex wn(cos(on*2*pi/h),sin(on*2*pi/h));
		for(j=0;j<l;j+=h)
		{
			complex w(1,0);
			for(k=j;k<j+h/2;++k)
			{
				u=y[k];
				t=w*y[k+h/2];
				y[k]=u+t;
				y[k+h/2]=u-t;
				w=w*wn;
			}
		}
	}
	if(on==-1)
		for(i=0;i<l;i++) y[i].r/=l;
}
void BigInt_times(BigInt &A,BigInt &B,BigInt &C)
{
	A.format();
	B.format();
	C.nAn=(A.nAn==1||B.nAn==1);
	if(C.nAn) return;
	
	int l1,l2,l,i;
	char *a=A.c_str(0),*b=B.c_str(0);
	if(*a=='-') a++;
	if(*b=='-') b++;
	l1=strlen(a);
	l2=strlen(b);
	l=1;
	while(l<l1*2 || l<l2*2)	l<<=1;
	complex *x1=new complex[l+5],*x2=new complex[l+5];
	int* sum=new int[l+5];
	for(i=0;i<l1;i++)
	{
		x1[i].r=a[l1-i-1]-'0';
		x1[i].i=0.0;
	}
	for(;i<l;i++) x1[i].r=x1[i].i=0.0;
	for(i=0;i<l2;i++)
	{
		x2[i].r=b[l2-i-1]-'0';
		x2[i].i=0.0;
	}
	for(;i<l;i++) x2[i].r=x2[i].i=0.0;
	fft(x1,l,1);
	fft(x2,l,1);
	for(i=0;i<l;i++) x1[i]=x1[i]*x2[i];
	fft(x1,l,-1);
	for(i=0;i<l;i++) sum[i]=x1[i].r+0.5;
	for(i=0;i<l;i++)
	{
		sum[i+1]+=sum[i]/10;
		sum[i]%=10;
	}
	l=l1+l2-1;
	while(sum[l]<=0&&l>0) l--;
	
	char *res=new char[l1+l2+5],*p=res;
	for(i=l;i>=0;i--) *p++=sum[i]+'0';
	*p=0;
	C=res;
	C.f=(A.f!=B.f);
	C.format();
	
	delete[] (A.f?a-1:a);
	delete[] (B.f?b-1:b);
	delete[] x1;
	delete[] x2;
	delete[] sum;
	delete[] res;
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

#if __cplusplus >= 201103L
BigInt operator+(BigInt &a,BigInt &b)
{
	BigInt t;
	BigInt_add(a,b,t);
	return t;
}
BigInt operator+(BigInt &a,BigInt &&b)
{
	BigInt t;
	BigInt_add(a,b,t);
	return t;
}
BigInt operator+(BigInt &&a,BigInt &b)
{
	BigInt t;
	BigInt_add(a,b,t);
	return t;
}
BigInt operator+(BigInt &&a,BigInt &&b)
{
	BigInt t;
	BigInt_add(a,b,t);
	return t;
}
BigInt operator+=(BigInt &a,BigInt &b)
{
	BigInt t;
	BigInt_add(a,b,t);
	return a=t;
}
BigInt operator+=(BigInt &a,BigInt &&b)
{
	BigInt t;
	BigInt_add(a,b,t);
	return a=t;
}

BigInt operator-(BigInt &a,BigInt &b)
{
	BigInt t;
	BigInt_minus(a,b,t);
	return t;
}
BigInt operator-(BigInt &&a,BigInt &b)
{
	BigInt t;
	BigInt_minus(a,b,t);
	return t;
}
BigInt operator-(BigInt &a,BigInt &&b)
{
	BigInt t;
	BigInt_minus(a,b,t);
	return t;
}
BigInt operator-(BigInt &&a,BigInt &&b)
{
	BigInt t;
	BigInt_minus(a,b,t);
	return t;
}
BigInt operator-=(BigInt &a,BigInt &b)
{
	BigInt t;
	BigInt_minus(a,b,t);
	return a=t;
}
BigInt operator-=(BigInt &a,BigInt &&b)
{
	BigInt t;
	BigInt_minus(a,b,t);
	return a=t;
}

BigInt operator*(BigInt  &a,BigInt  &b)
{
	BigInt t;
	BigInt_times(a,b,t);
	return t;
}
BigInt operator*(BigInt &&a,BigInt  &b)
{
	BigInt t;
	BigInt_times(a,b,t);
	return t;
}
BigInt operator*(BigInt  &a,BigInt &&b)
{
	BigInt t;
	BigInt_times(a,b,t);
	return t;
}
BigInt operator*(BigInt &&a,BigInt &&b)
{
	BigInt t;
	BigInt_times(a,b,t);
	return t;
}
BigInt operator*=(BigInt &a,BigInt &b)
{
	BigInt t;
	BigInt_times(a,b,t);
	return a=t;
}
BigInt operator*=(BigInt &a,BigInt &&b)
{
	BigInt t;
	BigInt_times(a,b,t);
	return a=t;
}

BigInt operator/(BigInt  &a,BigInt  &b)
{
	BigInt c;
	BigInt_divide(a,b,c);
	return c;
}
BigInt operator/(BigInt &&a,BigInt  &b)
{
	BigInt c;
	BigInt_divide(a,b,c);
	return c;
}
BigInt operator/(BigInt  &a,BigInt &&b)
{
	BigInt c;
	BigInt_divide(a,b,c);
	return c;
}
BigInt operator/(BigInt &&a,BigInt &&b)
{
	BigInt c;
	BigInt_divide(a,b,c);
	return c;
}
BigInt operator/=(BigInt &a,BigInt &b)
{
	BigInt c;
	BigInt_divide(a,b,c);
	return a=c;
}
BigInt operator/=(BigInt &a,BigInt &&b)
{
	BigInt c;
	BigInt_divide(a,b,c);
	return a=c;
}

BigInt operator%(BigInt  &a,BigInt  &b)
{
	BigInt t1,t2;
	BigInt_divide(a,b,t1);
	BigInt_times(t1,b,t2);
	BigInt_minus(a,t2,t1);
	return t1;
}
BigInt operator%(BigInt &&a,BigInt  &b)
{
	BigInt t1,t2;
	BigInt_divide(a,b,t1);
	BigInt_times(t1,b,t2);
	BigInt_minus(a,t2,t1);
	return t1;
}
BigInt operator%(BigInt  &a,BigInt &&b)
{
	BigInt t1,t2;
	BigInt_divide(a,b,t1);
	BigInt_times(t1,b,t2);
	BigInt_minus(a,t2,t1);
	return t1;
}
BigInt operator%(BigInt &&a,BigInt &&b)
{
	BigInt t1,t2;
	BigInt_divide(a,b,t1);
	BigInt_times(t1,b,t2);
	BigInt_minus(a,t2,t1);
	return t1;
}
BigInt operator%=(BigInt &a,BigInt &b)
{
	BigInt t1,t2;
	BigInt_divide(a,b,t1);
	BigInt_times(t1,b,t2);
	BigInt_minus(a,t2,t1);
	return a=t1;
}
BigInt operator%=(BigInt &a,BigInt &&b)
{
	BigInt t1,t2;
	BigInt_divide(a,b,t1);
	BigInt_times(t1,b,t2);
	BigInt_minus(a,t2,t1);
	return a=t1;
}
#else
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
#endif

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
	{
		char *p=n.c_str(0);
		str<<p;
		delete[] p;
	}
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
//======================/
int main()
{
	BigInt a,b,c;
	string s1;
	cin>>s1; a=s1;
	cin>>s1; b=s1;
	c=a/b;
	printf("%s\n",c.c_str());
	return 0;
}
