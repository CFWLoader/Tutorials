__author__ = 'cfwloader'

from InitialData import bob, sue

import shelve

db = shelve.open('people-shelve')

db['bob'] = bob
db['sue'] = sue

db.close()