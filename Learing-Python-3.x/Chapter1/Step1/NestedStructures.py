__author__ = 'cfwloader'

bob = {
    'name': {'first': 'Bob', 'last': 'Smith'},
    'age': 42,
    'job': ['software', 'writing'],
    'pay': (40000, 50000)
}

print(bob['name']['first'] + ' ' + bob['name']['last'])

print(bob['job'][-1])

print(bob['pay'][0])

bob['job'].append('janitor')

print(bob)