__author__ = 'CFWLoader'

from numpy import genfromtxt

data = genfromtxt('iris.csv', delimiter=',', usecols=(0, 1, 2, 3))

target = genfromtxt('iris.csv', delimiter=',', usecols=(4), dtype=str)

from sklearn.cluster import KMeans

kmeans = KMeans(n_clusters=3, init='random')

kmeans.fit(data)

c = kmeans.predict(data)

from sklearn.metrics import completeness_score, homogeneity_score

print(completeness_score(target, c))

print(homogeneity_score(target, c))