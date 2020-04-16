import urllib.request, urllib.parse ,urllib.error
import json
import ssl

#ignore ssl certificate error
cfc = ssl.create_default_context()
cfc.check_hostname = False
cfc.verify_mode = ssl.CERT_NONE


url = "http://py4e-data.dr-chuck.net/comments_436079.json"
print('Retrieving', url)
data = urllib.request.urlopen(url, context=cfc ).read().decode()
print('Retrieved', len(data), 'characters')

try:
    # make a tree of data ( will return a dicionary)
    js = json.loads(data)
except:
    # if json.loads() blowuo due to error than do this
    js = None

#if not js or 'status' not in js or js['status'] != 'OK':
#    print('==== Failure To Retrieve ====')

#prints the data beautifully
#print(json.dumps(js, indent=4))

#coding below
sum = 0;
for counts in js['comments']:
    sum = sum + int( counts['count'] )

print("Count:",len(js))
print("Sum:",sum)
