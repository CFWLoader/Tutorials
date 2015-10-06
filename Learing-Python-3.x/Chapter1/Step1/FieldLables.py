__author__ = 'cfwloader'

bob = ['Bob Smith', 42, 30000, 'software']
sue = ['Sue Jones', 45, 40000, 'hardware']
nucky = ['Nucky Tompson', 50, 0, None]

NAME, AGE, PAY = range(3)

print(bob[NAME])

print((PAY, bob[PAY]))