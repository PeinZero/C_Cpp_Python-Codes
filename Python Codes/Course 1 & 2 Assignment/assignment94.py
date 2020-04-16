fname = input("Enter file name:")
fhand = open(fname)
words = list()
mails = dict()
for line in fhand:
    line = line.rstrip()
    if line.startswith('From:') : continue
    if line.startswith('From'):
        words = line.split()
        mails[words[1]] = mails.get(words[1],0) + 1

sender = None
max = None

for k,v in mails.items():
    if max is None or max < mails[k]:
        sender = k
        max = v
print(sender,max)
