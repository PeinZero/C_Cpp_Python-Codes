fname = input("Enter file name: ")
fh = open(fname)
lst = list()
temp = list()
count = 0
found = False
for line in fh:
    newLine = line.rstrip()
    if count == 0:
        lst = newLine.split()
        #print(lst)
        count = 1
    else:
        temp = newLine.split()
        #print(temp)
        for word in temp:
            #print(word)
            for word2 in lst:
                #print(word , word2)
                if word == word2:
                    found = True
                    break
            if found == False:
                lst.append(word)
            found = False
lst.sort()
print(lst)
