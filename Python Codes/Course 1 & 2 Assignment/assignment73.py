fname = input("Enter filename:")
fh = open(fname,'r')
count = 0
total = 0.0
for line in fh:
    lineNew = line.rstrip()
    if lineNew.startswith("X-DSPAM-Confidence:"):
        count = count + 1
        pos = lineNew.find('0')
        num = float (lineNew[pos:])
        total = total + num
print("Average spam confidence:",total/count)
