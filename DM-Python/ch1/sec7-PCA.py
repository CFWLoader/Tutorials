__author__ = 'CFWLoader'

from numpy import genfromtxt

from pylab import plot, savefig

data = genfromtxt('iris.csv', delimiter=',', usecols=(0, 1, 2, 3))

target = genfromtxt('iris.csv', delimiter=',', usecols=(4), dtype=str)

from sklearn.decomposition import PCA

pca = PCA(n_components=2)

pcad = pca.fit_transform(data)

plot(pcad[target=='setosa', 0], pcad[target=='setosa', 1], 'bo')
plot(pcad[target=='versicolor', 0], pcad[target=='versicolor', 1], 'ro')
plot(pcad[target=='virginica', 0], pcad[target=='virginica', 1], 'go')

savefig("./PCA.jpg")

print(pca.explained_variance_ratio_)

print(1-sum(pca.explained_variance_ratio_))