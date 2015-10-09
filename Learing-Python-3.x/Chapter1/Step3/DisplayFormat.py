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

    def __str__(self):
        return '<%s => %s>' % (self.__class__.__name__, self.name)


class Manager(Person):

    def giveRaise(self, percent, bonus = 0.1):
        Person.giveRaise(self, percent + bonus)


if __name__ == '__main__':

    tom = Manager('Tom Jones', 50)

    print(tom)