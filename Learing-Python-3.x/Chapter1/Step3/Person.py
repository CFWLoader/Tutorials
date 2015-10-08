__author__ = 'cfwloader'

class Person:

    def __init__(self, name, age, pay = 0, job = None):

        self.name = name
        self.age = age
        self.pay = pay
        self.job = job

    def lastName(self):
        return self.name.split()[-1]

    def giveRaise(self, percent):
        self.pay *= (1.0 + percent)


if __name__ == '__main__':

    bob = Person('Bob Smith', 42, 30000, 'software')
    sue = Person('Sue Jones', 45, 40000, 'hardware')

    print(bob.name, sue.pay)

    sue.pay *= 1.10

    print(sue.pay)

    people = [bob, sue]

    for person in people:
        print(person.name, person.pay)

    x = [(person.name, person.pay) for person in people]

    print(x)