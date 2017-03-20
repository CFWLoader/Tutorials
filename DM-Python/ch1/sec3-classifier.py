__author__ = 'CFWLoader'

from numpy import genfromtxt, zeros

data = genfromtxt('iris.csv', delimiter=',', usecols=(0, 1, 2, 3))

target = genfromtxt('iris.csv', delimiter=',', usecols=(4), dtype=str)

t = zeros(len(target))

t[target == 'setosa'] = 1
t[target == 'versicolor'] = 2
t[target == 'vriginica'] = 3

from sklearn.naive_bayes import GaussianNB

classifier = GaussianNB()

classifier.fit(data, t)             # training

print(classifier.predict(data[0]))

print(t[0])