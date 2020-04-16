fname = input("Enter file name:")
fhand = open(fname)
lst = list()
count = 0
for line in fhand:
    newLine = line.rstrip()
    if line.startswith('From:'): continue
    if line.startswith('From'):
        lst = newLine.split()
        print(lst[1])
        count = count + 1

print("There were", count, "lines in the file with From as the first word")
