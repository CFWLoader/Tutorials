__author__ = 'CFWLoader'

from numpy import genfromtxt
from pylab import figure, subplot, hist, xlim, savefig

data = genfromtxt('iris.csv', delimiter=',', usecols=(0, 1, 2, 3))

target = genfromtxt('iris.csv', delimiter=',', usecols=(4), dtype=str)

xmin = min(data[:, 0])

xmax = max(data[:, 0])

figure()

subplot(411)       # distribution of the setosa class (1st, on the top)

hist(data[target=='setosa', 0], color='b', alpha=.7)

xlim(xmin, xmax)

subplot(412)        # distribution of the versicolor class (2nd)

hist(data[target=='versicolor', 0], color='r', alpha=.7)

xlim(xmin, xmax)

subplot(413)        # distribution of the virginica class (3rd)

hist(data[target=='virginica', 0], color='g', alpha=.7)

xlim(xmin, xmax)

subplot(414)        # global histogram (4th, on the bottom)

hist(data[:, 0], color='y', alpha=.7)

xlim(xmin, xmax)

savefig('./result-hist.jpg')