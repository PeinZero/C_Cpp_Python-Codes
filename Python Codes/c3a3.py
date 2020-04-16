# To run this, download the BeautifulSoup zip file
# http://www.py4e.com/code3/bs4.zip
# and unzip it in the same directory as this file

import urllib.request, urllib.parse, urllib.error
from bs4 import BeautifulSoup
import ssl

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE


#url = "http://py4e-data.dr-chuck.net/known_by_Mehreen.html"
url = input("Enter URL:")
count = int (input ("Enter count:"))
pos = int (input("Enter position:"))
p = 1
name = " "

for c in range(count):
    p = 1
    html = urllib.request.urlopen(url, context=ctx).read()
    soup = BeautifulSoup(html, 'html.parser')

    # Retrieve all of the anchor tags
    tags = soup('a')
    for tag in tags:
        if p == pos:
            url = tag.get('href', None)
            print(tag.get('href', None))
            name = tag.contents[0]
            p = p  + 1
        elif p > pos:
            break
        else:
            p = p + 1
            continue

print(name)
