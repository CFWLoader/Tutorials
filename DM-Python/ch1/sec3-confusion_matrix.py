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

# Method for validating the prediction.
# from sklearn.metrics import confusion_matrix
# print(confusion_matrix(classifier.predict(test), t_test))

# Complete report
from sklearn.metrics import classification_report
print(classification_report(classifier.predict(test), t_test, target_names=['setosa', 'versicolor', 'virginica']))

# Average score via multiple test models.
from sklearn.cross_validation import cross_val_score
scores = cross_val_score(classifier, data, t, cv=6)

print(scores)
