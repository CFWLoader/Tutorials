__author__ = 'CFWLoader'

from numpy import genfromtxt, corrcoef, arange

data = genfromtxt('iris.csv', delimiter=',', usecols=(0, 1, 2, 3))

# target = genfromtxt('iris.csv', delimiter=',', usecols=(4), dtype=str)
corr = corrcoef(data.T)             # .T Transpose the matrix.

print(corr)

from pylab import pcolor, colorbar, xticks, yticks, savefig

pcolor(corr)
colorbar()

xticks(arange(0.5, 4.5), ['sepal length',  'sepal width', 'petal length', 'petal width'], rotation=-20)
yticks(arange(0.5, 4.5), ['sepal length',  'sepal width', 'petal length', 'petal width'], rotation=-20)

savefig('./corrcoef.jpg')