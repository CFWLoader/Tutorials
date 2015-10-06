__author__ = 'cfwloader'

from InitialData import bob, sue, nucky

import pickle

for (key, record) in [('bob', bob), ('nucky', nucky), ('sue', sue)]:

    recordFile = open(key + '.pkl', 'wb')

    pickle.dump(record, recordFile)

    recordFile.close()