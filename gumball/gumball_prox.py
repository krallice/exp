#!/usr/bin/python

from gumball_state import GumballMachine

class GumballMonitor(object):

    def __init__(self, gumballmachine):

        self.machine = gumballmachine

    def report(self):

        print 'Gumball Machine: %s' % (self.machine.get_location())
        print 'Gumball State: %s' % (self.machine.get_state())
        print 'Gumball Count: %s' % (self.machine.get_count())

class GumballSuperMonitor(object):

    def __init__(self, gumballmachinelist):

        self.list = []
        for machine in gumballmachinelist:
            self.list.append(GumballMonitor(machine))

    def report(self):

        for index, gbm in enumerate(self.list):
            print
            print "Gumball Machine #%s" % (index)
            gbm.report()

if __name__ == "__main__":

    gb_list = []

    gb_list.append(GumballMachine(6, "Smithfield"))
    gb_list.append(GumballMachine(4, "Camperdown"))
    gb_list.append(GumballMachine(5, "Fairfield"))

    gbsm = GumballSuperMonitor(gb_list)
    gbsm.report()

