__author__ = 'CFWLoader'

from numpy.random import rand

x = rand(40, 1)

y = x*x*x + rand(40, 1)/5

from sklearn.linear_model import LinearRegression

linreg = LinearRegression()

linreg.fit(x, y)

from numpy import linspace, matrix
from pylab import plot, savefig

xx = linspace(0, 1, 40)

plot(x, y, 'o', xx, linreg.predict(matrix(xx).T), '--r')

savefig('./regression.jpg')

from sklearn.metrics import mean_squared_error

print(mean_squared_error(linreg.predict(x), y))

