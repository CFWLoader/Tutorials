__author__ = 'cfwloader'

class Person:
    """
    A general person: data + logic.
    """

    def __init__(self, name, age, pay = 0, job = None):

        self.name = name
        self.age = age
        self.pay = pay
        self.job = job

    def lastName(self):
        return self.name.split()[-1]

    def giveRais(self, percent):
        self.pay *= (1.0 + percent)

    def __str__(self):
        return ('<%s => %s: %s, %s>' % (self.__class__.__name__, self.name, self.job, self.pay))

class Manager(Person):
    """
    A person with custom raise inherits general lastname, str.
    """

    def __init__(self, name, age, pay):
        Person.__init__(self, name, age, pay, 'manager')

    def giveRais(self, percent, bonus = 0.1):
        Person.giveRais(self, percent + bonus)

if __name__ == '__main__':
    bob = Person('Bob Smith', 44)

    sue = Person('Sue Jones', 47, 40000, 'hardware')

    tom = Manager(name = 'Tom Doe', age = 50, pay = 50000)

    for obj in (bob, sue, tom):
        obj.giveRais(.10)
        print(obj)