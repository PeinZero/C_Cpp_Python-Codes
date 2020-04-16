import re
fh = open("c3a1.txt")
sum = 0
for line in fh:
    line = line.rstrip()
    y = re.findall('[0-9]+',line)
    if len(y) < 1 : continue
    for x in y:
        sum = sum + int(x)

print(sum)
