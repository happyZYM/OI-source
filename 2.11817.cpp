#include<cstdio>
#include<cmath>
struct Point3
{
	double x,y,z;
	Point3(double _x=0,double _y=0,double _z=0):x(_x),y(_y),z(_z) { }
};
Point3 operator-(Point3 A,Point3 B)
{ return Point3(A.x-B.x,A.y-B.y,A.z-B.z); }
double Length(Point3 p)
{ return sqrt(p.x*p.x+p.y*p.y+p.z*p.z); }

const double Pi=acos(-1);
inline double D_to_R(double D)
{ return Pi/180*D; }
void get_coord(double R,double lat,double lng,Point3 &p)
{
	lat=D_to_R(lat);
	lng=D_to_R(lng);
	p.x=R*cos(lat)*cos(lng);
	p.y=R*cos(lat)*sin(lng);
	p.z=R*sin(lat);
}
using namespace std;
int n;
double lat1,lng1,lat2,lng2;
const double R=6371009;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	while(n-->0)
	{
		scanf("%lf%lf%lf%lf",&lat1,&lng1,&lat2,&lng2);
		if(lat1<0) lat1+=360;
		if(lng1<0) lng1+=360;
		if(lat2<0) lat2+=360;
		if(lng2<0) lng2+=360;
		Point3 A,B;
		get_coord(R,lat1,lng1,A);
		get_coord(R,lat2,lng2,B);
		double d=Length(A-B);
		printf("%.0lf\n",2*asin(d/(2*R))*R-d);
	}
	return 0;
}
