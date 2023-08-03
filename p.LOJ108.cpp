#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100005;
const double Pi=acos(-1);
int n,m,r[maxn<<2];
struct Complex
{
	double x,y;
	inline Complex() { x=y=0; }
	inline Complex(const double &xx,const double &yy):x(xx),y(yy) { }
};
inline Complex operator+(const Complex &a,const Complex &b) { return Complex(a.x+b.x,a.y+b.y); }
inline Complex operator-(const Complex &a,const Complex &b) { return Complex(a.x-b.x,a.y-b.y); }
inline Complex operator*(const Complex &a,const Complex &b) { return Complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x); }
Complex a[maxn<<2];
inline void fft(Complex *f,int n,int op)
{
	for(int i=0;i<n;i++) if(i<r[i]) swap(f[i],f[r[i]]);
	for(int p=2;p<=n;p<<=1)
	{
		int len=p/2;
		Complex w(cos(Pi/len),op*sin(Pi/len));
		for(int L=0;L<n;L+=p)
		{
			Complex t(1,0);
			for(int i=L;i<L+len;i++)
			{
				Complex v=t*f[i+len];
				f[i+len]=f[i]-v;
				f[i]=f[i]+v;
				t=t*w;
			}
		}
	}
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++) scanf("%lf",&a[i].x);
	for(int i=0;i<=m;i++) scanf("%lf",&a[i].y);
	for(m+=n,n=1;n<=m;n<<=1);
	for(int i=0;i<n;i++) r[i]=(r[i>>1]>>1)|((i&1)?n>>1:0);
	// for(int i=0;i<n;i++) printf("%d ",r[i]); puts("");
	fft(a,n,1);
	for(int i=0;i<n;i++) a[i]=a[i]*a[i];
	fft(a,n,-1);
	for(int i=0;i<=m;i++) printf("%.0lf ",abs(a[i].y)/n/2); puts("");
	return 0;
}