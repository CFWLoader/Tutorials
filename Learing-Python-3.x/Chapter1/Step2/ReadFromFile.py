__author__ = 'cfwloader'

from MakePersistentFile import loadDatabase

db = loadDatabase()

for key in db:
    print(key, '=>\n ', db[key])

print(db['sue']['name'])