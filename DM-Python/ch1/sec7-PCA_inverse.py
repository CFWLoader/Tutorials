__author__ = 'CFWLoader'

from numpy import genfromtxt

from pylab import plot, savefig

data = genfromtxt('iris.csv', delimiter=',', usecols=(0, 1, 2, 3))

target = genfromtxt('iris.csv', delimiter=',', usecols=(4), dtype=str)

from sklearn.decomposition import PCA

# pca = PCA(n_components=2)
#
# pcad = pca.fit_transform(data)
#
# data_inv = pca.inverse_transform(pcad)
#
# print(abs(sum(sum(data - data_inv))))

# Increase the components used to analyse.
for i in range(1, 5):
    pca = PCA(n_components=i)
    pca.fit(data)
    print(sum(pca.explained_variance_ratio_) * 100, '%')