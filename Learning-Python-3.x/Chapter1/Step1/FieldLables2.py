__author__ = 'cfwloader'

# Show a bad method to use collection.

bob = [['name', 'Bob Smith'], ['age', 42], ['pay', 10000]]
sue = [['name', 'Sue Jones'], ['age', 45], ['pay', 20000]]

people = [bob, sue]

for person in people:
    print(person[0][1], person[2][1])

print([person[0][1] for person in people])

# Name-Value to find the specified field. It's better to use map.

for person in people:
    for (name, value) in person:
        if name == 'name':
            print(value)

# Encapsulate the finding value by key method to a function.

def field(record, label):
    for (fname, fvalue) in record:
        if fname == label:
            return fvalue

print(field(bob, 'name'))

print(field(sue, 'pay'))

for rec in people:
    print(field(rec, 'age'))
