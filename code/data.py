import random
fout = open("big.in","w")
case=1280
fout.write("%d\n"%case)
for c in range(1,case+1):
    # t = input()
    # t=int(t)
    t=57344
    fout.write("%d\n"%t)
    for i in range(1,t+1):
        n = random.randint(1, 2000000000) 
        # n=int(t-i+1)
        fout.write("%d "%n) 
    fout.write("\n")
    '''
    k = input()
    k=int(k)
    '''
    # k=random.randint(1,t)
    k=10000
    fout.write("%d\n"%k)
fout.close()

