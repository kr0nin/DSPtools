/*

x[n] ==> x(k) = (N-1)SUMSIGMA(n=0) x[n]e^(j(2pikn/N))

N is the number of data points used in the transform

= (N-1)SUMSIGMA(n=0) x[n]e^((j2pik/N)n)

kth value in Zu (Nth root)
Zu = twiddle factor

= (N-1)SUMSIGMA(n=0) x[n](Zu[k])^n

Power of a complex number:

tComplex.cpow_zc(tComplex_c, int)
    INPUT: Zu[k],n
        zp = tConvert_cp(Zu[k])
        zp.dMag = pow(zp.dMag,n)
        zp.dAng = n*zp.dAng
    OUTPUT: tConvert_pc(zp)

---------------------------------------------------
so:

x[n] = {1,1,1,1}
x[0] = x[0]+x[1]+x[2]+x[3] = 4
x[1] = x(0)(e^())


--------------------------------------------------

algorithm DFT

INPUTS: x(n), N
    suppose you need a 4pt. DFT from a matrix of 16? take 4 pts at a time [*,*,*,*][*,*,*,*]
    this is where augmentation comes in if the matricies are not multiples of 4 (append 0's to matrix)

1) find Zu, Nth root (Nth roots of unity)
    for (k=0, k=n-1, k++){
        dftx[k] += x(n)*[Zu(k)]^n       ==>input to ==> Zu[k] (line 35)
    }



*/
