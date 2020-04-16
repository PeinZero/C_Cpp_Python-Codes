fname = input("Enter filename:")
fh = open(fname,'r')
for line in fh:
    lineNew = line.rstrip()
    print(lineNew.upper())
