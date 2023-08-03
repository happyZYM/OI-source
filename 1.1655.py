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

n=0
m=0
C=Array(105,105)
C[0][0]=1
for i in range(1,101):
    for j in range(1,i+1):
        C[i][j]=C[i-1][j]*j+C[i-1][j-1]

try:
	while IO_inf.eof==False:
		n,m=scanf("DD")
		if m>n:
			print(0)
		else:
			print(C[n][m])
except ValueError:
	pass