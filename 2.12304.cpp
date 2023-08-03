#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
using std::vector;
using std::swap;

struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;

inline Point read_point()
{
	Point A;
	scanf("%lf%lf",&A.x,&A.y);
	return A;
}

inline Vector operator+(const Vector &A,const Vector &B)
{ return Vector(A.x+B.x,A.y+B.y); }

inline Vector operator-(const Point &a,const Point &b)
{ return Vector(a.x-b.x,a.y-b.y); }

inline Vector operator*(const Vector &A,double p)
{ return Vector(A.x*p,A.y*p); }

inline Vector operator/(const Vector &A,double p)
{ return Vector(A.x/p,A.y/p); }

inline bool operator<(const Point &a,const Point &b)
{ return a.x<b.x||(a.x==b.x&&a.y<b.y); }

const double eps=1e-10;
inline int dcmp(double x)
{ return (x>0?x:-x)<=eps?0:(x>0?1:-1); }

inline bool operator==(const Point &a,const Point &b)
{ return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0; }

inline double Dot(const Vector &A,const Vector &B)
{ return A.x*B.x+A.y*B.y; }

inline double Length(const Vector &A)
{ return sqrt(Dot(A,A)); }

inline double Angle(const Vector &A,const Vector &B)
{ return acos(Dot(A,B)/Length(A)/Length(B)); }

const double Pi=atan(1)*4;
inline double Angle(const Vector &A)
{ return atan2(A.y,A.x); }
inline double R_to_D(double rad)
{ return 180/Pi*rad; }
inline double D_to_R(double D)
{ return Pi/180*D; }

inline double Cross(const Vector &A,const Vector &B)
{ return A.x*B.y-A.y*B.x; }

inline double Area2(const Point &a,const Point &b,const Point &c)
{ return Cross(b-a,c-a); }

inline Vector Rotate(const Vector &A,double rad)
{
	double csr=cos(rad),sir=sin(rad);
	return Vector(A.x*csr-A.y*sir,A.x*sir+A.y*csr);
}

inline Vector Normal(const Vector &A)
{
	double L=Length(A);
	return Vector(-A.y/L,A.x/L);
}
inline Vector Format(const Vector &A)
{
	double L=Length(A);
	return Vector(A.x/L,A.y/L);
}

//inline Point GetLineIntersection
//(const Point &P,const Vector &v,const Point &Q,const Vector &w)
//{
//	Vector u=P-Q;
//	double t=Cross(w,u)/Cross(v,w);
//	return P+v*t;
//}
inline Point GetLineIntersection
(const Point &A1,const Point &B1,const Point &A2,const Point &B2)
{
	Vector u=A1-A2,v=B1-A1,w=B2-A2;
	double t=Cross(w,u)/Cross(v,w);
	return A1+v*t;
}

inline double DistanceToLine
(const Point &P,const Point &A,const Point &B)
{
	Vector v1=B-A,v2=P-A;
	return fabs(Cross(v1,v2))/Length(v1);
}

inline double DistanceToSegment
(const Point &P,const Point &A,const Point &B)
{
	if(A==B) return Length(P-A);
	Vector v1=B-A,v2=P-A,v3=P-B;
	if(dcmp(Dot(v1,v2))<0) return Length(v2);
	else if(dcmp(Dot(v1,v3))>0) return Length(v3);
	else return fabs(Cross(v1,v2))/Length(v1);
}

inline Point GetLineProjection
(const Point &P,const Point &A,const Point &B)
{
	Vector v=B-A;
	return A+v*(Dot(v,P-A)/Dot(v,v));
}

inline bool SegmentProperIntersection
(const Point &a1,const Point &a2,const Point &b1,const Point &b2)
{
	double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),
		   c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}

inline bool OnSegment
(const Point &p,const Point &a1,const Point &a2)
{ return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p))<0; }

inline double PolygonArea(Point* p,int n)
{
	double area=0;
	for(int i=1;i<n-1;i++)
		area+=Cross(p[i]-p[0],p[i+1]-p[0]);
	return area/2;
}



struct Circle
{
	Point c;
	double r;
	Circle(Point c=Point(),double r=0):c(c),r(r){}
	inline Point point(double a)
	{ return Point(c.x+cos(a)*r,c.y+sin(a)*r); }
};
inline Circle read_circle()
{
	Circle C;
	scanf("%lf%lf%lf",&C.c.x,&C.c.y,&C.r);
	return C;
}

inline int GetLineCircleIntersection
(const Point &A,const Point &B,const Circle &C,vector<Point> &sol)
{
	double d=DistanceToLine(C.c,A,B);
	int mode=dcmp(d-C.r);
	if(mode>0) return 0;//ÏàÀë
	Point P=GetLineProjection(C.c,A,B);
	if(mode==0)//ÏàÇÐ 
	{
		sol.push_back(P);
		return 1;
	}
	double dist=sqrt(C.r*C.r-d*d);
	Vector v=Format(B-A);
	sol.push_back(P-v*dist);
	sol.push_back(P+v*dist);
	return 2;
}

inline int GetCircleCircleIntersection
(Circle C1,Circle C2,vector<Point> &sol)
{
	if(C1.r<C2.r) swap(C1,C2);//to make sure C1 is bigger than C2
	double D=Length(C1.c-C2.c);
	if(dcmp(D)==0)
		return dcmp(C1.r-C2.r)==0?-1:0;
	if(dcmp(C1.r+C2.r-D)<0) return 0;
	if(dcmp(fabs(C1.r-C2.r)-D)>0) return 0;
	
	double d1=((C1.r*C1.r-C2.r*C2.r)/D+D)/2;
	double x=sqrt(C1.r*C1.r-d1*d1);
	Point O=C1.c+Format(C2.c-C1.c)*d1;
	Point P1=O+Normal(O-C2.c)*x,P2=O-Normal(O-C2.c)*x;
	sol.push_back(P1);
	if(P1==P2) return 1;
	sol.push_back(P2);
	return 2;
}

inline int GetTangents
(const Point P,const Circle C,vector<Point> &v)
{
	Vector u=C.c-P;
	double dist=Length(u);
	int mode=dcmp(dist-C.r);
	if(mode<0) return 0;
	if(mode==0)
	{
		v.push_back(P+Normal(u));
		return 1;
	}
	double x=sqrt(dist*dist-C.r*C.r);
	Circle C2(P,x);
	return GetCircleCircleIntersection(C,C2,v);
}
using namespace std;
const char* q1="CircumscribedCircle";
const char* q2="InscribedCircle";
const char* q3="TangentLineThroughPoint";
const char* q4="CircleThroughAPointAndTangentToALineWithRadius";
const char* q5="CircleTangentToTwoLinesWithRadius";
const char* q6="CircleTangentToTwoDisjointCirclesWithRadius";
char cmd[100];
Circle WaiJieYuan(Point p1,Point p2,Point p3)
{
	double Bx=p2.x-p1.x,By=p2.y-p1.y;
	double Cx=p3.x-p1.x,Cy=p3.y-p1.y;
	double D=2*(Bx*Cy-By*Cx);
	double ansx=(Cy*(Bx*Bx+By*By)-By*(Cx*Cx+Cy*Cy))/D+p1.x;
	double ansy=(Bx*(Cx*Cx+Cy*Cy)-Cx*(Bx*Bx+By*By))/D+p1.y;
	Point p(ansx,ansy);
	return Circle(p,Length(p1-p));
}
Circle NeiJieYuan(Point p1,Point p2,Point p3)
{
	double a=Length(p2-p3);
	double b=Length(p3-p1);
	double c=Length(p1-p2);
	Point p=(p1*a+p2*b+p3*c)/(a+b+c);
	return Circle(p,DistanceToLine(p,p1,p2));
}
void output(vector<double> res)
{
	sort(res.begin(),res.end());
	printf("[");
	for(int i=0;i<res.size();i++)
	{
		if(i) printf(",");
		printf("%.6lf",res[i]);
	}
	printf("]\n");
}
void output(vector<Point> res)
{
	sort(res.begin(),res.end());
	printf("[");
	for(int i=0;i<res.size();i++)
	{
		if(i) printf(",");
		printf("(%.6lf,%.6lf)",res[i].x,res[i].y);
	}
	printf("]\n");
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%s",cmd)==1)
	{
		if(strcmp(cmd,q1)==0)
		{
			Point p1,p2,p3;
			p1=read_point();
			p2=read_point();
			p3=read_point();
			Circle C=WaiJieYuan(p1,p2,p3);
			printf("(%.6lf,%.6lf,%.6lf)\n",C.c.x,C.c.y,C.r);
		}
		if(strcmp(cmd,q2)==0)
		{
			Point p1,p2,p3;
			p1=read_point();
			p2=read_point();
			p3=read_point();
			Circle C=NeiJieYuan(p1,p2,p3);
			printf("(%.6lf,%.6lf,%.6lf)\n",C.c.x,C.c.y,C.r);
		}
		if(strcmp(cmd,q3)==0)
		{
			Circle C=read_circle();
			Point p=read_point();
			vector<Point> v;
			vector<double> res;
			GetTangents(p,C,v);
			for(int i=0;i<v.size();i++)
			{
				double tmp=R_to_D(Angle(v[i]-p));
				if(tmp<0) tmp+=180;
				if(tmp>=180) tmp-=180;
				res.push_back(tmp);
			}
			output(res);
		}
		if(strcmp(cmd,q4)==0)
		{
			Point p=read_point();
			Point A=read_point();
			Point B=read_point();
			double r;
			scanf("%lf",&r);
			Circle C(p,r);
			Vector v=Normal(B-A)*r;
			Point A1=A+v,B1=B+v;
			Point A2=A-v,B2=B-v;
			vector<Point> res;
			GetLineCircleIntersection(A1,B1,C,res);
			GetLineCircleIntersection(A2,B2,C,res);
			output(res);
		}
		if(strcmp(cmd,q5)==0)
		{
			Point p1=read_point();
			Point p2=read_point();
			Point p3=read_point();
			Point p4=read_point();
			double r;
			scanf("%lf",&r);
			Vector v=Normal(p1-p2)*r;
			Point A1=p1+v,B1=p2+v;
			Point A2=p1-v,B2=p2-v;
			v=Normal(p3-p4)*r;
			Point A3=p3+v,B3=p4+v;
			Point A4=p3-v,B4=p4-v;
			vector<Point> res;
			res.push_back(GetLineIntersection(A1,B1,A3,B3));
			res.push_back(GetLineIntersection(A1,B1,A4,B4));
			res.push_back(GetLineIntersection(A2,B2,A3,B3));
			res.push_back(GetLineIntersection(A2,B2,A4,B4));
			output(res);
		}
		if(strcmp(cmd,q6)==0)
		{
			Circle c1=read_circle();
			Circle c2=read_circle();
			double r;
			scanf("%lf",&r);
			c1.r+=r;c2.r+=r;
			vector<Point> res;
			GetCircleCircleIntersection(c1,c2,res);
			output(res);
		}
	}
	return 0;
}
