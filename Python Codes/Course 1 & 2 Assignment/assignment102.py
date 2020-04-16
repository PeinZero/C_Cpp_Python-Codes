fname = input("Enter file name:")
fhand = open(fname)
words = list()
mails = dict()
for line in fhand:
    line = line.rstrip()
    if line.startswith('From:') : continue
    if line.startswith('From'):
        words = line.split()
        time = words[5].split(':')
        hour = time[0]
        mails[hour] = mails.get(hour,0) + 1

for k,v in sorted(mails.items()):
    print(k,v)
