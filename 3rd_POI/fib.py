import sys
import re

def CNT(s, t):
    return len(re.findall(f'(?={t})', s))
 
def CNT2(s, t):
    p = [m.start(0) for m in re.finditer(f'(?={t})', s)]
    abcdef = 0
    for i in p: 
        if i + len(t) - 1 >= 30 and i < 30: abcdef += 1
    return abcdef
 
 
fib = ['', 'b', 'a']
 
s = input().strip()
 
for i in range(3, 14): 
    fib.append(fib[i - 1] + fib[i - 2])
 
n = int(input())
 
#print(f"{s}:{n}:::")
 
if (n <= 12): 
    print(CNT(fib[n], s))
    sys.exit()
 
c = [0] * (n + 5)
 
c[11] = CNT(fib[11], s)
c[12] = CNT(fib[12], s)
 
 
pre = fib[11][0:30]
suf = fib[11][-30:]
 
inc = CNT2(suf + pre, s)
    
for i in range(13, n + 2): 
    c[i] = c[i - 1] + c[i - 2] + inc
 
print(c[n])