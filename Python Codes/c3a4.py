import urllib.request, urllib.parse, urllib.error
import xml.etree.ElementTree as ET
#import ssl

#if you dont want to write [urllib.request.] before urlopen(url, context=ctx).read() then uncomment this
#from urllib.request import urlopen

# Ignore SSL certificate errors
#ctx = ssl.create_default_context()
#ctx.check_hostname = False
#ctx.verify_mode = ssl.CERT_NONE


#url = input('Enter location: ')
url = "http://py4e-data.dr-chuck.net/comments_436078.xml"

print('Retrieving', url)
#data = urllib.request.urlopen(url, context=ctx).read()
data = urllib.request.urlopen(url).read()
print('Retrieved', len(data), 'characters')

tree = ET.fromstring(data)
comment = tree.findall('comments/comment')
print("Count:",len(comment))

sum = 0
for counts in comment:
    sum = sum + int(counts.find('count').text)

print("Sum:",sum)
