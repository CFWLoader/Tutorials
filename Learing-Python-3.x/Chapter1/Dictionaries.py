__author__ = 'cfwloader'

bob = {'name': 'Bob Smith', 'age': 42, 'pay': 30000, 'job': 'dev'}
sue = {'name': 'Sue Jones', 'age': 45, 'pay': 40000, 'job': 'hdw'}

print((bob['name'], sue['pay']))

print(bob['name'].split()[-1])

# Another way to make dictionaries.

nucky = dict(name = 'Nucky Tompson', age = 50, pay = 360000, job = 'Monger')

print(nucky)

# Assign value immediately.

eli = {}
eli['name'] = 'Eli Tompson'
eli['age'] = 40
eli['pay'] = 20000
eli['job'] = 'shr'

print(eli)

# Zipping

names = ['name', 'age', 'pay', 'job']
values = ['James Darmody', 22, 40000, 'R&D']

print(list(zip(names, values)))

jimmy = dict(zip(names, values))

print(jimmy)

# From a sequence of key values.
fields = ('name', 'age', 'job', 'pay')

record = dict.fromkeys(fields, '?')

print(record)