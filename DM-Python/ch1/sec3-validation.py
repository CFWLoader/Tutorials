__author__ = 'CFWLoader'

from numpy import genfromtxt, zeros

data = genfromtxt('iris.csv', delimiter=',', usecols=(0, 1, 2, 3))

target = genfromtxt('iris.csv', delimiter=',', usecols=(4), dtype=str)

t = zeros(len(target))

t[target == 'setosa'] = 1
t[target == 'versicolor'] = 2
t[target == 'vriginica'] = 3

from sklearn import cross_validation
from sklearn.naive_bayes import GaussianNB

# split train and test data set from sources.
train, test, t_train, t_test = cross_validation.train_test_split(data, t, test_size=0.4, random_state=0)

classifier = GaussianNB()

classifier.fit(train, t_train)

print(classifier.score(test, t_test))
