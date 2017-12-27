__author__ = 'cfwloader'

import pickle, glob

for filename in glob.glob('*.pkl'):

    recordFile = open(filename, 'rb')

    record = pickle.load(recordFile)

    print(filename, '=>\n ', record)

suefile = open('sue.pkl', 'rb')

print(pickle.load(suefile)['name'])