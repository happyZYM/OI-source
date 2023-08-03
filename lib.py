from sys import *

# IO
def isprint(ch):
    isp=['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
         'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
         '0','1','2','3','4','5','6','7','8','9',
         '~','`','!','@','#','$','%','^','&','*','(',')',
         '-','_','=','+','[','{',']','}','\\','|',
         ';',':','\'','"',
         ',','<','.','>','/','?']
    return ch in isp
class Input:
    io_line_buf=""
    io_line_buf_size=0
    io_line_buf_cnt=0
    file=stdin
    eof=False
    
    def __init__(self,f=stdin):
        self.io_line_buf=""
        self.io_line_buf_size=0
        self.io_line_buf_cnt=0
        self.file=f
        self.eof=False

    def freopen(self,name):
        self.io_line_buf=""
        self.io_line_buf_size=0
        self.io_line_buf_cnt=0
        self.file=open(name)
        self.eof=False
    
    def alloc(self):
        if self.io_line_buf_cnt>=self.io_line_buf_size:
            self.io_line_buf=self.file.readline()
            self.io_line_buf_size=len(self.io_line_buf)
            self.io_line_buf_cnt=0
            if self.io_line_buf_size == 0 :
                self.eof=True
    
    def getchar(self):
        self.alloc()
        if self.eof:
            return '\0'
        self.io_line_buf_cnt=self.io_line_buf_cnt+1
        return self.io_line_buf[self.io_line_buf_cnt-1]
    
    def getline(self):
        self.alloc()
        if self.eof:
            return ''
        if self.io_line_buf[-1:]=='\n':
            res=self.io_line_buf[self.io_line_buf_cnt:-1]
        else:
            res=self.io_line_buf[self.io_line_buf_cnt:]
        self.io_line_buf_cnt=len(self.io_line_buf)
        return res
    
    def read_int(self):
        vali=['-','0','1','2','3','4','5','6','7','8','9']
        S=""
        ch=""
        while not self.eof:
            ch=self.getchar()
            if ch in vali :
                break
        S=ch
        while not self.eof:
            ch=self.getchar()
            if not ( ch in vali ) :
                break
            S=S+ch
        return int(S)
    
    def read_float(self):
        vali=['.','-','0','1','2','3','4','5','6','7','8','9']
        S=""
        ch=""
        while not self.eof:
            ch=self.getchar()
            if ch in vali :
                break
        S=ch
        while not self.eof:
            ch=self.getchar()
            if not ( ch in vali ) :
                break
            S=S+ch
        return int(S)
    
    def read_str(self):
        S=""
        ch=""
        while not self.eof:
            ch=self.getchar()
            if isprint(ch):
                break;
        S=ch
        while not self.eof:
            ch=self.getchar()
            if not isprint(ch):
                break;
            S=S+ch
        return S
    
    def read_char(self):
        ch=""
        while not self.eof:
            ch=self.getchar()
            if isprint(ch):
                break
        return ch
    
    def scanf(self,flist):
        out=[]
        for tp in flist:
            if tp == 'D' or tp == 'd' :
                out.append(self.read_int())
            elif tp == 'F' or tp == 'f' :
                out.append(self.read_float())
            elif tp == 'C' or tp == 'c' :
                out.append(self.read_char())
            else:
                out.append(self.read_str())
        if len(out) == 1:
            return out[0]
        else:
            return out

IO_inf=Input()
def scanf(flist):
    return IO_inf.scanf(flist)
def getchar():
    return IO_inf.getchar()
def getline():
    return IO_inf.getline()

# math
def gcd(a,b):
    if b==0 :
        return a
    return gcd(b,a%b)

def lcm(a,b):
    return int(a/gcd(a,b)*b)

def yf(a,b):
	c=gcd(a,b)
	a=a/c
	b=b/c
	return [a,b]

#自适应辛普森积分
'''c++版
#include<cstdio>
#include<cmath>
double a;
inline double f(double x) { return pow(x,a/x-x); }
inline double simpson(double a,double b) { return (f(a)+4*f((a+b)/2)+f(b))*(b-a)/6; }
double asr(double a,double b,double eps,double A)
{
    double c=(a+b)/2;
    double L=simpson(a,c),R=simpson(c,b);
    if(fabs(L+R-A)<=15*eps) return L+R+(L+R-A)/15;
    return asr(a,c,eps/2,L)+asr(c,b,eps/2,R);
}
double asr(double a,double b,double eps) { return asr(a,b,eps,simpson(a,b)); }
int main()
{
#ifdef local
    freopen("pro.in","r",stdin);
#endif
    scanf("%lf",&a);
    const double eps=1e-8;
    if(a<0) printf("orz\n");
    else printf("%.5lf\n",asr(eps,20,eps));
    return 0;
}
'''
def simpson(f,a,b):
	return (f(a)+4*f((a+b)/2.0)+f(b))*(b-a)/6.0

def asr(f,a,b,eps,A):
	c=(a+b)/2.0
	L=simpson(f,a,c)
	R=simpson(f,c,b)
	if abs(L+R-A)<=15*eps:
		return L+R+(L+R-A)/15.0
	return asr(f,a,c,eps/2.0,L)+asr(f,c,b,eps/2.0,R)

def sps(f,a,b,eps):
	return asr(f,a,b,eps,simpson(f,a,b))

# Data Struct
def Array(*idx,dft=0):
    ary=[]
    idx=list(idx)
    idx.reverse()
    for i in range(0,idx[0]):
        ary.append(dft)
    for rg in idx[1:]:
        x=[]
        for j in range(0,rg):
            x.append(ary[:])
        ary=x
    return ary
