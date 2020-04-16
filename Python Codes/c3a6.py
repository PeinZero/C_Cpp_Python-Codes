import urllib.request, urllib.parse ,urllib.error
import json
import ssl

#ignore ssl certificate error
cfc = ssl.create_default_context()
cfc.check_hostname = False
cfc.verify_mode = ssl.CERT_NONE

address = "Old Dominion University"
parms = dict()
parms['address'] = address
parms['key'] = 42

#this will not work without google api_key !!!
#serviceurl = 'https://maps.googleapis.com/maps/api/geocode/json?'
serviceurl = 'http://py4e-data.dr-chuck.net/json?'


url = serviceurl + urllib.parse.urlencode(parms)
print('Retrieving', url)
data = urllib.request.urlopen(url, context=cfc ).read().decode()
print('Retrieved', len(data), 'characters')

try:
    # make a tree of data ( will return a dicionary)
    js = json.loads(data)
except:
    # if json.loads() blowuo due to error than do this
    js = None

if not js or 'status' not in js or js['status'] != 'OK':
    print('==== Failure To Retrieve ====')

#prints the data beautifully
#print(json.dumps(js, indent=4))

#coding below
print("Place Id",js['results'][0]['place_id'])
