__author__ = 'cfwloader'


import pickle

databastFile = open('people-pickle', 'rb')

db = pickle.load(databastFile)

for key in db:
    print(key, '=>\n ', db[key])

print(db['sue']['name'])