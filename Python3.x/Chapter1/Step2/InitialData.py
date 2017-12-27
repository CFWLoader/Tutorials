__author__ = 'cfwloader'

bob = {'name': 'Bob Smith', 'age': 42, 'pay': 30000, 'job': 'dev'}

sue = {'name': 'Sue Jones', 'age': 45, 'pay': 40000, 'job': 'hdw'}

nucky = dict(name = 'Nucky Tompson', age = 50, pay = 360000, job = 'Monger')

eli = {}
eli['name'] = 'Eli Tompson'
eli['age'] = 40
eli['pay'] = 20000
eli['job'] = 'shr'

db = {'bob': bob, 'sue': sue, 'nucky': nucky, 'eli': eli}

if __name__ == '__main__':                                  # When run as a script.
    for key in db:
        print(key, '=>\n ', db[key])