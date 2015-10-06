__author__ = 'cfwloader'

from InitialData import db

import pickle

dbfile = open('people-pickle', 'wb')

pickle.dump(db, dbfile)

dbfile.close()