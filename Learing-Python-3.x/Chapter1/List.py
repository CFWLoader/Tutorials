__author__ = 'cfwloader'

bob = ['Bob Smith', 42, 30000, 'software']
sue = ['Sue Jones', 45, 40000, 'hardware']

people = [bob, sue]                             # Making a collection of two object.

for person in people:                           # Operate objects in this collection.
    print(person)
    person[2] *= 1.20

pays = [person[2] for person in people]         # Collect the pay of every employee.

# print(pays)

pays = map((lambda x: x[2]), people)            # Ditto.

print(list(pays))

print(sum(person[2] for person in people))      # Generate the sum of pays via built-in function -- sum.

people.append(['Nucky Tompson', 50, 0, None])   # Add a new object.

print(len(people))                              # Print the size of this collection.

print(people[-1][0])                            # Print the first attribute of the last object in this collection.