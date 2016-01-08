__author__ = 'cfwloader'

import shelve

fieldNames = ('name', 'age', 'job', 'pay')

maxField = max(len(f) for f in fieldNames)

db = shelve.open('class-shelve')

while True:

    key = input('\nKey? => ')

    if not key: break

    try:
        record = db[key]

    except:
        print('No such key "%s"!' % key)

    else:
        for field in fieldNames:
            print(field.ljust(maxField), '=>', getattr(record, field))