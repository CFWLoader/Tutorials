__author__ = 'cfwloader'

dbFileName = 'people-file'

ENDDB = 'enddb.'

ENDREC = 'endrec.'

RECSEP = '=>'

def storeDatabse(db, dbFilename = dbFileName):
    "Formatted dump of database to flat file."
    dbFile = open(dbFilename, 'w')

    for key in db:

        print(key, file = dbFile)

        for (name, value) in db[key].items():

            print(name + RECSEP + repr(value), file = dbFile)

        print(ENDREC, file = dbFile)

    print(ENDDB, file = dbFile)

    dbFile.close()

def loadDatabase(dbFilename = dbFileName):
    "Parse data to reconstuct database."
    dbFile = open(dbFilename)

    import sys

    sys.stdin = dbFile

    db = {}

    key = input()

    while key != ENDDB:

        rec = {}

        field = input()

        while field != ENDREC:

            name, value = field.split(RECSEP)

            rec[name] = eval(value)

            field = input()

        db[key] = rec

        key = input()

    return db

if __name__ == '__main__':

    from InitialData import db

    storeDatabse(db)