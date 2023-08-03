from lib import *
def main():
    IO_inf.freopen("pro.in")
    n=scanf("d")
    if n==1:
        print(0)
        return
    phi=Array(n)
    phi[1]=1
    isp=Array(n,dft=True)
    isp[1]=False
    cnt=0
    p=Array(n)
    for i in range(2,n):
        if isp[i]:
            p[cnt]=i
            cnt=cnt+1
            phi[i]=i-1
        for j in range(0,cnt):
            if i*p[j]>=n :
                break
            isp[i*p[j]]=False
            if i%p[j]==0 :
                phi[i*p[j]]=phi[i]*p[j]
                break
            else :
                phi[i*p[j]]=phi[i]*(p[j]-1)
    res=0
    for i in range(1,n):
        res=res+phi[i]
    print(res*2+1)

main()
