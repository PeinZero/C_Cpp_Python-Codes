import urllib.request, urllib.parse, urllib.error, re

fhand = urllib.request.urlopen('http://data.pr4e.org/romeo.txt')

for line in fhand:
    line = line.decode().strip()
    y = re.findall('^W.*e([a-z]*)',line)
    if len(y) < 1 : continue
    print(y)
