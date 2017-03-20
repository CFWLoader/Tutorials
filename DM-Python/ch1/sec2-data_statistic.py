__author__ = 'CFWLoader'

from numpy import genfromtxt

data = genfromtxt('iris.csv', delimiter=',', usecols=(0, 1, 2, 3))

target = genfromtxt('iris.csv', delimiter=',', usecols=(4), dtype=str)

# data size
print(data.shape)

print(target.shape)

print(set(target))       # build a collection of unique elements.