__author__ = 'cfwloader'

import shelve

db = shelve.open('people-shelve')                   # Notice that shelve open has writeback side-effect.

for key in db:

    print(key, '=>\n ', db[key])

print(db['sue']['name'])

db.close()