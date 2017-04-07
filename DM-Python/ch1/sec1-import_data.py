__author__ = 'CFWLoader'

# import urllib2
import urllib.request as reqs

url = 'http://aima.cs.berkeley.edu/data/iris.csv'

# u = urllib2.urlopen(url)
u = reqs.urlopen(url)

localFile = open('iris.csv', 'w')

localFile.write(bytes.decode(u.read()))

localFile.close()
